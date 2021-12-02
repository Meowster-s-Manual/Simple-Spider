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
    myfile.close();
}


int FileIO::writeToFile(const char* text)
{
    if (myfile.is_open())
    {
        myfile << text;
    } else cout << "Error: Unable to open file";
    return 0;
}

string FileIO::readFile()
{
    if (!myfile.is_open())
    {
        cout << "Error: Unable to open file";
    }

    string contents{ istreambuf_iterator<char>{myfile}, {} }; // uniform initilization
    //cout << contents;

    return contents;
}

int FileIO::closeFile()
{
    myfile.close();
    return 0;
}

