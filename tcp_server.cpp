#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#define PORT 8080

int main() {
    WSADATA wsa;
    SOCKET server_fd, new_socket;
    struct sockaddr_in server, client;
    int c;
    char buffer[1024] = {0};
    std::string message = "Hello from Windows Server!";

    // Initialize Winsock
    std::cout << "Initializing Winsock..." << std::endl;
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        std::cout << "WSAStartup failed!" << std::endl;
        return 1;
    }
    std::cout << "Initialized.\n";

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        std::cout << "Socket creation failed!" << std::endl;
        return 1;
    }

    // Prepare sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        std::cout << "Bind failed!" << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    listen(server_fd, 3);
    std::cout << "Server listening on port " << PORT << "..." << std::endl;

    c = sizeof(struct sockaddr_in);
    new_socket = accept(server_fd, (struct sockaddr*)&client, &c);
    if (new_socket == INVALID_SOCKET) {
        std::cout << "Accept failed!" << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    std::cout << "Client connected!" << std::endl;
    send(new_socket, message.c_str(), message.size(), 0);
    int valread = recv(new_socket, buffer, sizeof(buffer), 0);
    buffer[valread] = '\0';
    std::cout << "Client says: " << buffer << std::endl;

    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();
    return 0;
}
