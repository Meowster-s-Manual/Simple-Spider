#include "Parser.h"

using namespace sisp;

char * Parser::removeHeader(char * buffer) {
	char * found = strstr(buffer, "\r\n\r\n");
	if (found == NULL) {
		return buffer;
	}
	found += 4;
	return found;
}

vector<char*> Parser::linkFinder(const char* fileName)
{
	vector<char*> links;
	FileIO myFile(fileName, false);
	myFile.readFile();
	// TODO get links using regex <a.+?href="(.+?)" and save in links

	return links;
}
;