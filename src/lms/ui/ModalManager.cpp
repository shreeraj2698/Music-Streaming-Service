

#include "ModalManager.hpp"
#include "utils/Logger.hpp"

namespace UserInterface
{
	ModalManager::ModalManager()
		: _closed {this, "closed"}
	{
		_closed.connect([=](const std::string& id)
		{
			LMS_LOG(UI, DEBUG) << "Received closed for id '" << id << "'";
			for (int i {}; i < count(); ++i)
			{
				Wt::WWidget* widget {this->widget(i)};
				LMS_LOG(UI, DEBUG) << "Widget " << i << ", id = '" << widget->id();
				if (widget->id() == id)
				{
					removeWidget(widget);
					break;
				}
			}
		});
	}

	void
	ModalManager::show(std::unique_ptr<Wt::WWidget> modalWidget)
	{
		LMS_LOG(UI, DEBUG) << "Want to show, id = " << modalWidget->id();

		std::ostringstream oss;
		oss
			<< R"({const modalElement = )" << jsRef() << R"(.getElementsByClassName('modal')[0];)"
			<< R"(const modal = bootstrap.Modal.getOrCreateInstance(modalElement);)"
			<< R"(modal.show();)"
			<< R"(modalElement.addEventListener('hidden.bs.modal', function () {)"
				<< _closed.createCall({"'" + modalWidget->id() + "'"})
				<< R"(modal.dispose();)"
			<< R"(});})";

		LMS_LOG(UI, DEBUG) << "Running JS '" << oss.str() << "'";

		doJavaScript(oss.str());

		addWidget(std::move(modalWidget));
	}

	void
	ModalManager::dispose(Wt::WWidget* modalWidget)
	{
		std::ostringstream oss;
		oss
			<< R"({const modalElementParent = document.getElementById(')" << modalWidget->id() << R"(');)"
			<< R"(const modalElement = modalElementParent.getElementsByClassName('modal')[0];)"
			<< R"(const modal = bootstrap.Modal.getInstance(modalElement);)"
			<< R"(modal.hide();)"
			<< R"(})";

		LMS_LOG(UI, DEBUG) << "Running JS '" << oss.str() << "'";

		doJavaScript(oss.str());
	}
}
