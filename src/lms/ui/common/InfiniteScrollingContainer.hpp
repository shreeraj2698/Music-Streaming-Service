

#pragma once

#include <memory>
#include <optional>
#include <utility>

#include <Wt/WContainerWidget.h>
#include <Wt/WSignal.h>
#include <Wt/WString.h>
#include <Wt/WTemplate.h>

namespace UserInterface
{
	// Atomatically raises onRequestElements signal when the sentinel is displayed
	// can add elements afterwards by calling setHasMoreElements()
	class InfiniteScrollingContainer final : public Wt::WTemplate
	{
		public:
			// "text" must contain loading-indicator and "elements"
			InfiniteScrollingContainer(const Wt::WString& text = Wt::WString::tr("Lms.infinite-scrolling-container.template"));

			void reset();
			std::size_t getCount();
			void add(std::unique_ptr<Wt::WWidget> result);

			template<typename T, typename... Args>
			T* addNew(Args&&... args)
			{
				return _elements->addNew<T>(std::forward<Args>(args)...);
			}

			void remove(Wt::WWidget& widget);
			void remove(std::size_t first, std::size_t last);

			Wt::WWidget*				getWidget(std::size_t pos) const;
			std::optional<std::size_t>	getIndexOf(Wt::WWidget& widget) const;
			void 						setHasMore(); // can be used to add elements afterwards

			Wt::Signal<>	onRequestElements;

		private:
			void clear() override;
			void displayLoadingIndicator();
			void hideLoadingIndicator();
			void setHasMore(bool hasMore); // can be used to add elements afterwards

			Wt::WContainerWidget*	_elements;
			Wt::WTemplate*			_loadingIndicator;
	};
}
