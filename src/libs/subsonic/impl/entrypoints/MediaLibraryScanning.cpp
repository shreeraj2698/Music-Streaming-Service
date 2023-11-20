

#include "MediaLibraryScanning.hpp"

#include "services/scanner/IScannerService.hpp"
#include "utils/Service.hpp"

namespace API::Subsonic::Scan
{
    using namespace Scanner;

    namespace
    {
        Response::Node createStatusResponseNode()
        {
            Response::Node statusResponse;

            const IScannerService::Status scanStatus{ Service<IScannerService>::get()->getStatus() };

            statusResponse.setAttribute("scanning", scanStatus.currentState == IScannerService::State::InProgress);
            if (scanStatus.currentState == IScannerService::State::InProgress)
            {
                std::size_t count{};

                if (scanStatus.currentScanStepStats && scanStatus.currentScanStepStats->currentStep == ScanStep::ScanningFiles)
                    count = scanStatus.currentScanStepStats->processedElems;

                statusResponse.setAttribute("count", count);
            }

            return statusResponse;
        }
    }

    Response handleGetScanStatus(RequestContext& context)
    {
        Response response{ Response::createOkResponse(context.serverProtocolVersion) };
        response.addNode("scanStatus", createStatusResponseNode());

        return response;
    }

    Response handleStartScan(RequestContext& context)
    {
        Service<IScannerService>::get()->requestImmediateScan(false);

        Response response{ Response::createOkResponse(context.serverProtocolVersion) };
        response.addNode("scanStatus", createStatusResponseNode());

        return response;
    }
}

