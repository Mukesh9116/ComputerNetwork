#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    std::string hello = "Hello from macOS Client!";

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 👉 Change this IP to your Windows machine’s IPv4 address
    const char* server_ip = "172.22.20.183";  // Replace with server's IP
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        std::cout << "Invalid address / Address not supported" << std::endl;
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection Failed" << std::endl;
        return -1;
    }

    send(sock, hello.c_str(), hello.size(), 0);
    int valread = read(sock, buffer, 1024);
    buffer[valread] = '\0';
    std::cout << "Server says: " << buffer << std::endl;

    close(sock);
    return 0;
}
