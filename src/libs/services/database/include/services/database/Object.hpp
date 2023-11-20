

#pragma once

#include <Wt/WSignal.h>
#include <Wt/Dbo/ptr.h>
#include "services/database/IdType.hpp"

namespace Database
{
	template <typename T>
	class ObjectPtr
	{
		public:
			ObjectPtr() = default;
			ObjectPtr(Wt::Dbo::ptr<T> obj) : _obj {obj} {}

			const T* operator->() const { return _obj.get(); }
			operator bool() const { return _obj.get(); }
			bool operator!() const { return !_obj.get(); }
			bool operator==(const ObjectPtr& other) const { return _obj == other._obj; }
			bool operator!=(const ObjectPtr& other) const { return other._obj != _obj; }

			auto modify() { return _obj.modify(); }
			void remove()
			{
				if (_obj->hasOnPreRemove())
					_obj.modify()->onPreRemove();
				_obj.remove();
			}

		private:
			template <typename, typename> friend class Object;
			Wt::Dbo::ptr<T> _obj;
	};

	template <typename T, typename ObjectIdType>
	class Object : public Wt::Dbo::Dbo<T>
	{
		static_assert(std::is_base_of_v<Database::IdType, ObjectIdType>);
		static_assert(!std::is_same_v<Database::IdType, ObjectIdType>);

		public:
			using pointer = ObjectPtr<T>;
			using IdType = ObjectIdType;

			IdType getId() const { return Wt::Dbo::Dbo<T>::self()->Wt::Dbo::template Dbo<T>::id(); }

			// catch some misuses
			typename Wt::Dbo::dbo_traits<T>::IdType id() const = delete;

		protected:
			template <typename> friend class ObjectPtr;

			virtual bool hasOnPreRemove() const { return false; }
			virtual void onPreRemove() {}

			virtual bool hasOnPostCreated() const { return false; }
			virtual void onPostCreated() {}

			// Can get raw dbo ptr only from Objects
			template <typename SomeObject>
			static
			Wt::Dbo::ptr<SomeObject> getDboPtr(ObjectPtr<SomeObject> ptr) { return ptr._obj; }
	};
}
