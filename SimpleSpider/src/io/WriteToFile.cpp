#include "WriteToFile.h"

using namespace sisp;

sisp::WriteToFile::WriteToFile(const char* name) : myfile(name)
{
}

WriteToFile::~WriteToFile()
{
}


int WriteToFile::writeToFile(const char* text)
{
    if (myfile.is_open())
    {
        myfile << text;
    } else std::cout << "Unable to open file";
    return 0;
}

int WriteToFile::closeFile()
{
    myfile.close();
    return 0;
}

