#include <iostream>
#include "socket/TcpSocket.h"
#include "util/Parser.h"

using namespace sisp;

int main() {
    //std::cout << "What are you doing ANDREW!" << std::endl;
    TcpSocket testrun;
    testrun.urlToIp("www.google.com");
    testrun.receive();

    Parser::linkFinder("example.html");

    return 0;
}
