#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_PORT "80"
#define DEFAULT_BUFLEN 5120

namespace Socket {
	class TcpSocket
	{
	public:
		int initialization();
		TcpSocket();
		~TcpSocket();

	private:

	};
}