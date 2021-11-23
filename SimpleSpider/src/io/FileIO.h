#pragma once
#include <iostream>
#include <fstream>

using namespace std;

namespace sisp {
	class FileIO
	{
	private:
		ofstream myfile;
	public:
		FileIO(const char* name);
		~FileIO();

		int writeToFile(const char* text);
		int closeFile();
	};
}


