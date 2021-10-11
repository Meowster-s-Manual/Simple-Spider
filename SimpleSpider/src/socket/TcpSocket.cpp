#include "TcpSocket.h"

#define DEFAULT_BUFLEN 512

using namespace Socket;

TcpSocket::TcpSocket() {
	this->initialization();
}

TcpSocket::~TcpSocket() {}

int TcpSocket::initialization() {
	/* Sperate function */
	WSADATA wsaData;
	// Create socket object called ConnectSocket
	SOCKET ConnectSocket = INVALID_SOCKET;
	int result;
	// Initialize Winsock
	result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0) {
		printf("WSAStartup failed: %d\n", result);
		return 1;
	}
	printf("Here is result from WSAStartup: %d\n", result);
	//After initialization(addrinfo)
	struct addrinfo * res = NULL,
		            * ptr = NULL,
		            hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	result = getaddrinfo("www.google.com", DEFAULT_PORT, &hints, &res);
	if (result != 0) {
		printf("getaddrinfo failed: %d\n", result);
		WSACleanup();
		return 1;
	}

	// Attempt to connect to the first address returned by
	// the call to getaddrinfo
	ptr = res;

	// Create a SOCKET for connecting to server
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
		ptr->ai_protocol);

	// Check if socket is valid or not
	if (ConnectSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(res);
		WSACleanup();
		return 1;
	}
	
	/* Sperate function */
	const char* sendbuf = "this is a test";
	char recvbuf[DEFAULT_BUFLEN];

	int iResult;

	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}

	//freeaddrinfo(res);

	/* Seperate function */
	//int recvbuflen = DEFAULT_BUFLEN;


	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR) {
		printf("Send Failed %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	printf("Bytes Sent: %ld\n", iResult);

	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	do {
		iResult = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
		if (iResult > 0)
			printf("Bytes recieved: %d\n", iResult);
		else if (iResult == 0)
			printf("Connection close\n");
		else
			printf("recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0);

	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();

	return 0;
}