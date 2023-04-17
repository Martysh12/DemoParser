#pragma once

#include "demoheader.h"

#include <istream>
#include <memory>

class DemoFile
{
public:
    static std::unique_ptr<DemoFile> fromIStream(std::istream& f);

    std::shared_ptr<DemoHeader> getHeader();

private:
    std::shared_ptr<DemoHeader> header;

};
