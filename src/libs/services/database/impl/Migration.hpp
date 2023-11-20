

#pragma once

#include <Wt/Dbo/Dbo.h>

namespace Database
{
    class Session;

    using Version = std::size_t;
    static constexpr Version LMS_DATABASE_VERSION{ 42 };
    class VersionInfo
    {
    public:
        using pointer = Wt::Dbo::ptr<VersionInfo>;

        static VersionInfo::pointer getOrCreate(Session& session);
        static VersionInfo::pointer get(Session& session);

        Version getVersion() const { return _version; }
        void setVersion(Version version) { _version = static_cast<int>(version); }

        template<class Action>
        void persist(Action& a)
        {
            Wt::Dbo::field(a, _version, "db_version");
        }

    private:
        int _version{ LMS_DATABASE_VERSION };
    };

    namespace Migration
    {
        void doDbMigration(Session& session);
    }
}
