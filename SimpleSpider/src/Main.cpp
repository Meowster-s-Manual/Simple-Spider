#include <iostream>
#include "socket/TcpSocket.h"

using namespace sisp;

int main() {
    //std::cout << "What are you doing ANDREW!" << std::endl;
    TcpSocket testrun;
    testrun.urlToIp("www.google.com");
    testrun.receive();

    return 0;
}
