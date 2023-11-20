

#pragma once

#include <Wt/WDateTime.h>

#include <filesystem>
#include <vector>

#include "services/database/TrackId.hpp"

namespace Scanner
{
	enum class ScanErrorType
	{
		CannotReadFile,			// cannot read file
		CannotParseFile,		// cannot parse file
		NoAudioTrack,			// no audio track found
		BadDuration,			// bad duration
	};

	enum class DuplicateReason
	{
		SameHash,
		SameTrackMBID,
	};

	struct ScanError
	{
		std::filesystem::path	file;
		ScanErrorType		error;
		std::string		systemError;

		ScanError(const std::filesystem::path& file, ScanErrorType error, const std::string& systemError = "");
	};

	struct ScanDuplicate
	{
		Database::TrackId	trackId;
		DuplicateReason		reason;
	};

	enum class ScanStep
	{
		DiscoveringFiles,
		ScanningFiles,
		ChekingForMissingFiles,
		CheckingForDuplicateFiles,
		FetchingTrackFeatures,
		ReloadingSimilarityEngine,
	};
	static inline constexpr unsigned ScanProgressStepCount {5};

	// reduced scan stats
	struct ScanStepStats
	{
		Wt::WDateTime   startTime;

		ScanStep currentStep;

		std::size_t	totalElems {};
		std::size_t	processedElems {};

		unsigned		progress() const;
	};

	struct ScanStats
	{
		Wt::WDateTime	startTime;
		Wt::WDateTime	stopTime;

		std::size_t	filesScanned {};	// Total number of files scanned (estimated)

		std::size_t	skips {};			// no change since last scan
		std::size_t	scans {};			// actually scanned filed

		std::size_t	additions {};		// added in DB
		std::size_t	deletions {};		// removed from DB
		std::size_t	updates {};			// updated file in DB

		std::size_t	featuresFetched {};	// features fetched in DB

		std::vector<ScanError>		errors;
		std::vector<ScanDuplicate>	duplicates;

		std::size_t	nbFiles() const;
		std::size_t	nbChanges() const;
	};
} // namespace Scanner

