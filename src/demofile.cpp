#include "demofile.h"

std::unique_ptr<DemoFile> DemoFile::fromIStream(std::istream& f)
{
    std::unique_ptr<DemoFile> demoFile(new DemoFile());

    demoFile->header = std::shared_ptr<DemoHeader>(DemoHeader::fromIStream(f));

    if (!demoFile->header->isValidDemoFile())
        return NULL;

    return demoFile;
}

std::shared_ptr<DemoHeader> DemoFile::getHeader()
{
    return this->header;
}
