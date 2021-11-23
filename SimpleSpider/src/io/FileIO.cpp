#include "FileIO.h"

using namespace sisp;

sisp::FileIO::FileIO(const char* name) : myfile(name)
{
}

FileIO::~FileIO()
{
}


int FileIO::writeToFile(const char* text)
{
    if (myfile.is_open())
    {
        myfile << text;
    } else std::cout << "Unable to open file";
    return 0;
}

int FileIO::closeFile()
{
    myfile.close();
    return 0;
}

