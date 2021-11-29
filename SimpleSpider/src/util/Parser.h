#pragma once
#include <string.h>
#include <vector>
#include <string>
#include <regex>
#include "../io/FileIO.h"

using namespace std;

namespace sisp {
	class Parser
	{
	private:
	public:
		static char * removeHeader(char * buffer);
		static vector<char*> linkFinder(const char* fileName);
	};
};
