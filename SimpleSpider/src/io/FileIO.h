#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace sisp {
	class FileIO
	{
	private:
		fstream myfile;
	public:
		FileIO(const char* name, bool write = true);
		~FileIO();

		int writeToFile(const char* text);
		string readFile();
		int closeFile();
	};
}


