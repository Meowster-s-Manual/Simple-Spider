#include "TcpSocket.h"

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
	int returnCode;
	// Initialize Winsock
	returnCode = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (returnCode != 0) {
		printf("WSAStartup failed: %d\n", returnCode);
		return 1;
	}
	printf("Here is result from WSAStartup: %d\n", returnCode);
	//After initialization(addrinfo)
	struct addrinfo * result = NULL,
		            * ptr = NULL,
		            hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// Resolve the server address and port
	returnCode = getaddrinfo("www.google.com", DEFAULT_PORT, &hints, &result);
	if (returnCode != 0) {
		printf("getaddrinfo failed: %d\n", returnCode);
		WSACleanup();
		return 1;
	}

	// Attempt to connect to the first address returned by
	// the call to getaddrinfo
	ptr = result;

	// Create a SOCKET for connecting to server
	ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
		ptr->ai_protocol);

	// Check if socket is valid or not
	if (ConnectSocket == INVALID_SOCKET) {
		printf("Error at socket(): %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}
	
	/* Sperate function */
	const char* sendbuf = "GET / HTTP/1.1\r\n\r\n";
	char recvbuf[DEFAULT_BUFLEN];

	int connectionCode;

	connectionCode = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (connectionCode == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
		printf("Unable to connect to server!\n");
		WSACleanup();
		return 1;
	}

	//freeaddrinfo(res);

	/* Seperate function */
	//int recvbuflen = DEFAULT_BUFLEN;


	connectionCode = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (connectionCode == SOCKET_ERROR) {
		printf("Send Failed %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	printf("Bytes Sent: %ld\n", connectionCode);

	connectionCode = shutdown(ConnectSocket, SD_SEND);
	if (connectionCode == SOCKET_ERROR) {
		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	do {
		connectionCode = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
		if (connectionCode > 0) {
			printf("Bytes recieved: %d\n", connectionCode);
			puts(recvbuf);
		}
		else if (connectionCode == 0)
			printf("Connection close\n");
		else
			printf("recv failed: %d\n", WSAGetLastError());
	} while (connectionCode > 0);

	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();

	return 0;
}