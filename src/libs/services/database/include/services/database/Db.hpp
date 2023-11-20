

#pragma once

#include <filesystem>

#include <Wt/Dbo/SqlConnectionPool.h>

#include "utils/RecursiveSharedMutex.hpp"

namespace Database {

    class Session;
    class Db
    {
    public:
        Db(const std::filesystem::path& dbPath, std::size_t connectionCount = 10);

        Session& getTLSSession();

        void executeSql(const std::string& sql);

    private:
        Db(const Db&) = delete;
        Db& operator=(const Db&) = delete;

        friend class Session;

        RecursiveSharedMutex& getMutex() { return _sharedMutex; }
        Wt::Dbo::SqlConnectionPool& getConnectionPool() { return *_connectionPool; }

        class ScopedConnection
        {
        public:
            ScopedConnection(Wt::Dbo::SqlConnectionPool& pool);
            ~ScopedConnection();

            Wt::Dbo::SqlConnection* operator->() const;

        private:
            ScopedConnection(const ScopedConnection&) = delete;
            ScopedConnection& operator=(const ScopedConnection&) = delete;

            Wt::Dbo::SqlConnectionPool& _connectionPool;
            std::unique_ptr<Wt::Dbo::SqlConnection> _connection;
        };

        RecursiveSharedMutex				_sharedMutex;
        std::unique_ptr<Wt::Dbo::SqlConnectionPool>	_connectionPool;

        std::mutex _tlsSessionsMutex;
        std::vector<std::unique_ptr<Session>> _tlsSessions;
    };

} // namespace Database


