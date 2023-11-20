

#pragma once


#include <cassert>
#include <functional>
#include <Wt/Dbo/ptr.h>

namespace Database
{
	class IdType
	{
		public:
			using ValueType = Wt::Dbo::dbo_default_traits::IdType;

			IdType() = default;
			IdType(ValueType id) : _id {id} { assert(isValid()); }

			bool isValid() const { return _id != Wt::Dbo::dbo_default_traits::invalidId(); }
			std::string toString() const { assert(isValid()); return std::to_string(_id); }

			ValueType getValue() const { return _id; }

			bool operator==(IdType other) const { return other._id == _id; }
			bool operator!=(IdType other) const { return !(*this == other); }
			bool operator<(IdType other) const { return _id < other._id; }
			bool operator>(IdType other) const { return _id > other._id; }

		private:
			Wt::Dbo::dbo_default_traits::IdType _id {Wt::Dbo::dbo_default_traits::invalidId()};
	};

#define LMS_DECLARE_IDTYPE(name) \
	namespace Database { \
		class name : public IdType \
		{ \
			public: \
					using IdType::IdType; \
		};\
	} \
	namespace std \
	{ \
		template<> \
		class hash<Database::name> \
		{ \
			public: \
					size_t operator()(Database::name id) const \
			{ \
				return std::hash<Database::name::ValueType>()(id.getValue()); \
			} \
		}; \
	} // ns std
} // namespace Database

