#include "demoheader.h"

#include <algorithm>

using namespace std::string_literals;

const std::string DemoHeader::VALID_HEADER = "HL2DEMO\0"s;
const size_t      DemoHeader::MAX_OSPATH   = 260;

std::unique_ptr<DemoHeader> DemoHeader::fromIStream(std::istream& f)
{
    std::unique_ptr<DemoHeader> demoHeader(new DemoHeader());

    std::string fileStamp(8, '\0');
    f.read(&fileStamp[0], 8);

    demoHeader->isValid = fileStamp == DemoHeader::VALID_HEADER;

    if (!demoHeader->isValid)
    {
        return demoHeader;
    }

    f.read(reinterpret_cast<char *>(&demoHeader->demoProtocol),    sizeof(int));
    f.read(reinterpret_cast<char *>(&demoHeader->networkProtocol), sizeof(int));

    // Allocate space for strings
    demoHeader->serverName    = std::string(DemoHeader::MAX_OSPATH, '\0');
    demoHeader->clientName    = std::string(DemoHeader::MAX_OSPATH, '\0');
    demoHeader->mapName       = std::string(DemoHeader::MAX_OSPATH, '\0');
    demoHeader->gameDirectory = std::string(DemoHeader::MAX_OSPATH, '\0');

    // Read strings
    f.read(reinterpret_cast<char *>(&demoHeader->serverName[0]),    DemoHeader::MAX_OSPATH);
    f.read(reinterpret_cast<char *>(&demoHeader->clientName[0]),    DemoHeader::MAX_OSPATH);
    f.read(reinterpret_cast<char *>(&demoHeader->mapName[0]),       DemoHeader::MAX_OSPATH);
    f.read(reinterpret_cast<char *>(&demoHeader->gameDirectory[0]), DemoHeader::MAX_OSPATH);

    // Remove trailing null-bytes
    demoHeader->serverName    = demoHeader->serverName.c_str();
    demoHeader->clientName    = demoHeader->clientName.c_str();
    demoHeader->mapName       = demoHeader->mapName.c_str();
    demoHeader->gameDirectory = demoHeader->gameDirectory.c_str();

    f.read(reinterpret_cast<char *>(&demoHeader->playbackTime),   sizeof(float));
    f.read(reinterpret_cast<char *>(&demoHeader->playbackTicks),  sizeof(int));
    f.read(reinterpret_cast<char *>(&demoHeader->playbackFrames), sizeof(int));
    f.read(reinterpret_cast<char *>(&demoHeader->signOnLength),   sizeof(int));

    return demoHeader;
}

bool DemoHeader::isValidDemoFile()
{
    return this->isValid;
}

int DemoHeader::getDemoProtocol()
{
    return this->demoProtocol;
}

int DemoHeader::getNetworkProtocol()
{
    return this->networkProtocol;
}

std::string DemoHeader::getServerName()
{
    return this->serverName;
}

std::string DemoHeader::getClientName()
{
    return this->clientName;
}

std::string DemoHeader::getMapName()
{
    return this->mapName;
}

std::string DemoHeader::getGameDirectory()
{
    return this->gameDirectory;
}

float DemoHeader::getPlaybackTime()
{
    return this->playbackTime;
}

int DemoHeader::getPlaybackTicks()
{
    return this->playbackTicks;
}

int DemoHeader::getPlaybackFrames()
{
    return this->playbackFrames;
}

int DemoHeader::getSignOnLength()
{
    return this->signOnLength;
}
