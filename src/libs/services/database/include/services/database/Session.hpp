

#pragma once

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/SqlConnectionPool.h>

#include "utils/RecursiveSharedMutex.hpp"
#include "services/database/Object.hpp"


namespace Database
{
    class UniqueTransaction
    {
    private:
        friend class Session;
        UniqueTransaction(RecursiveSharedMutex& mutex, Wt::Dbo::Session& session);

        std::unique_lock<RecursiveSharedMutex> _lock;
        Wt::Dbo::Transaction _transaction;
    };

    class SharedTransaction
    {
    private:
        friend class Session;
        SharedTransaction(RecursiveSharedMutex& mutex, Wt::Dbo::Session& session);

        std::shared_lock<RecursiveSharedMutex> _lock;
        Wt::Dbo::Transaction _transaction;
    };

    class Db;
    class Session
    {
    public:
        Session(Db& database);

        [[nodiscard]] UniqueTransaction createUniqueTransaction();
        [[nodiscard]] SharedTransaction createSharedTransaction();

        void checkUniqueLocked();
        void checkSharedLocked();

        void analyze();

        void prepareTables(); // need to run only once at startup

        Wt::Dbo::Session& getDboSession() { return _session; }
        Db& getDb() { return _db; }

        template <typename Object, typename... Args>
        typename Object::pointer create(Args&&... args)
        {
            checkUniqueLocked();

            typename Object::pointer res{ Object::create(*this, std::forward<Args>(args)...) };
            getDboSession().flush();

            if (res->hasOnPostCreated())
                res.modify()->onPostCreated();

            return res;
        }

    private:
        Session(const Session&) = delete;
        Session& operator=(const Session&) = delete;

        Db& _db;
        Wt::Dbo::Session	_session;
    };
} // namespace Database


