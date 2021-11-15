#pragma once
#include <iostream>
#include <fstream>

using namespace std;

namespace sisp {
	class WriteToFile
	{
	private:
		ofstream myfile;
	public:
		WriteToFile(const char* name);
		~WriteToFile();

		int writeToFile(const char* text);
		int closeFile();
	};
}


