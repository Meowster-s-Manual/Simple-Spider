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

vector<string> Parser::linkFinder(const char* fileName)
{
	vector<string> links;
	string htmlData;
	FileIO myFile(fileName, false);

	htmlData = myFile.readFile();

	smatch sm;
	while (regex_search(htmlData, sm, regex("<a.+?href=\"(http.+?)\""))) {
		//cout << sm.str(1) << "\n";
		links.push_back(sm.str(1)); // 1 to grab the regex capture group

		htmlData = sm.suffix().str(); // iterator
	}

	return links;
}