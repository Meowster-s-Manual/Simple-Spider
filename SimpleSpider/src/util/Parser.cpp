#include "Parser.h"
#include <stdio.h>

using namespace sisp;

char * Parser::removeHeader(char * buffer) {
	char * found = strstr(buffer, "\r\n\r\n");
	//printf("Here is found: %s", found);
	if (found == NULL) {
		return buffer;
	}
	found += 4;
	return found;
};