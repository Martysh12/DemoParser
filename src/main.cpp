#include "demofile.h"

#include <fstream>
#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <demo file>" << std::endl;
        return 1;
    }

    std::ifstream f (argv[1], std::ios::in | std::ios::binary | std::ios::app);

    std::unique_ptr<DemoFile> demoFile = DemoFile::fromIStream(f);

    if (demoFile == NULL)
    {
        std::cerr << "Invalid filestamp! Are you sure the file in question is a demo file?" << std::endl;
        return 1;
    }

    std::cout << "Demo Protocol:       " << demoFile->getHeader()->getDemoProtocol() << std::endl;
    std::cout << "Network Protocol:    " << demoFile->getHeader()->getNetworkProtocol() << std::endl;

    std::cout << "Server Name:         " << std::quoted(demoFile->getHeader()->getServerName())    << " (" << demoFile->getHeader()->getServerName().size()    << " chars)" << std::endl;
    std::cout << "Client Name:         " << std::quoted(demoFile->getHeader()->getClientName())    << " (" << demoFile->getHeader()->getClientName().size()    << " chars)" << std::endl;
    std::cout << "Map Name:            "  << std::quoted(demoFile->getHeader()->getMapName())      << " (" << demoFile->getHeader()->getMapName().size()       << " chars)" << std::endl;
    std::cout << "Game Directory:      " << std::quoted(demoFile->getHeader()->getGameDirectory()) << " (" << demoFile->getHeader()->getGameDirectory().size() << " chars)" << std::endl;

    std::cout << "Playback Time:       "
        << demoFile->getHeader()->getPlaybackTime() << " (seconds), "
        << demoFile->getHeader()->getPlaybackTicks() << " (ticks), "
        << demoFile->getHeader()->getPlaybackFrames() << " (frames)" << std::endl;

    std::cout << "Sign-on Data Length: " << demoFile->getHeader()->getSignOnLength() << " bytes" << std::endl;

    return 0;
}
