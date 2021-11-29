#include "FileIO.h"

using namespace sisp;

FileIO::FileIO(const char* name, bool write)
{
    if (write) {
        myfile.open(name, fstream::out);
        if (!myfile) {
            cout << "Error: Fail to create file";
        }
    }
    else {
        myfile.open(name, fstream::in);
        if (!myfile) {
            cout << "Error: Fail to open file";
        }
    }
}

FileIO::~FileIO()
{
}


int FileIO::writeToFile(const char* text)
{
    if (myfile.is_open())
    {
        myfile << text;
    } else cout << "Error: Unable to open file";
    return 0;
}

int FileIO::readFile()
{
    if (myfile.is_open())
    {
        string contents((istreambuf_iterator<char>(myfile)),
           istreambuf_iterator<char>());
        cout << contents;
    }
    else cout << "Error: Unable to open file";
    return 0;
}

int FileIO::closeFile()
{
    myfile.close();
    return 0;
}

