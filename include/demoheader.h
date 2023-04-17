#pragma once

#include <istream>
#include <string>
#include <memory>

class DemoHeader
{
    static const std::string VALID_HEADER;
    static const size_t MAX_OSPATH;

    bool isValid;

    int demoProtocol;
    int networkProtocol;
    std::string serverName;
    std::string clientName;
    std::string mapName;
    std::string gameDirectory;
    float playbackTime;
    int playbackTicks;
    int playbackFrames;
    int signOnLength;

public:
    static std::unique_ptr<DemoHeader> fromIStream(std::istream& f);

    bool isValidDemoFile();

    int getDemoProtocol();
    int getNetworkProtocol();
    std::string getServerName();
    std::string getClientName();
    std::string getMapName();
    std::string getGameDirectory();
    float getPlaybackTime();
    int getPlaybackTicks();
    int getPlaybackFrames();
    int getSignOnLength();

};
