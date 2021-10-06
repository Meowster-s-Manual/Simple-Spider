#include "TcpSocket.h"

using namespace Socket;

TcpSocket::TcpSocket() {
	std::cout << "Creating class" << std::endl;
	this->initialization();
}

TcpSocket::~TcpSocket() {}

int TcpSocket::initialization() {
	WSADATA wsaData;
	int result;
	std::cout << "Starting initialization" << std::endl;
	// Initialize Winsock
	result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) {
		printf("WSAStartup failed: %d\n", result);
		return 1;
	}
	printf("Here is result from WSAStartup: %d\n", result);
	std::cout << "Here is result from WSAStartup: " << result << std::endl;
	//After initialization(addrinfo)
	struct addrinfo * res = NULL,
		            * ptr = NULL,
		            hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	std::cout << "ZeroMemory finished" << std::endl;

	// Resolve the server address and port
	result = getaddrinfo("https://wwww.google.com", DEFAULT_PORT, &hints, &res);
	if (result != 0) {
		printf("getaddrinfo failed: %d\n", result);
		WSACleanup();
		return 1;
	}
	std::cout << "Result for getaddrinfo: " << result << std::endl;

	// Create socket object called ConnectSocket
	SOCKET ConnectSocket = INVALID_SOCKET;

	// Attempt to connect to the first address returned by
	// the call to getaddrinfo
	ptr = res;

	// Create a SOCKET for connecting to server
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
		ptr->ai_protocol);
	std::cout << "Socket is created" << std::endl;
	// Check if socket is valid or not
	if (ConnectSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(res);
		WSACleanup();
		return 1;
	}







	WSACleanup();
	std::cout << "Killing Socket" << std::endl;
}