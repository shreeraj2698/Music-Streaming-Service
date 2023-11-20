

#include "DatabaseCollectorBase.hpp"

#include "utils/String.hpp"

namespace UserInterface
{
	DatabaseCollectorBase::DatabaseCollectorBase(Filters& filters, Mode defaultMode, std::size_t maxCount)
		: _filters {filters}
		, _mode {defaultMode}
		, _maxCount {maxCount}
	{
	}

	DatabaseCollectorBase::Range
	DatabaseCollectorBase::getActualRange(Range range) const
	{
		assert(range.offset < _maxCount);
		range.size = std::min(_maxCount - range.offset, range.size);

		return range;
	}

	std::size_t
	DatabaseCollectorBase::getMaxCount() const
	{
		return _maxCount;
	}

	void
	DatabaseCollectorBase::setSearch(std::string_view searchText)
	{
		_searchText = searchText;
		_searchKeywords = StringUtils::splitString(_searchText, " ");
	}

} // ns UserInterface

