# TCP Client–Server Communication in C++ (Windows ↔ macOS)
A simple cross-platform TCP socket communication project between a Windows server and a macOS client using C++.

# Technologies Used
- **Language:** C++
- **Libraries:**
  - Winsock2 (Windows)
  - sys/socket.h, arpa/inet.h, unistd.h (macOS)
- **Compiler:** g++
- **Protocol:** TCP/IP


# How the Code Works (Explanation of Logic)

###  Server (Windows)
1. Initializes Winsock using `WSAStartup`.
2. Creates a TCP socket using `socket()`.
3. Binds the socket to a local IP and port (8080).
4. Listens for client connections using `listen()`.
5. Accepts a connection using `accept()`.
6. Sends a message to the client and receives a reply.

### Client (macOS)
1. Creates a TCP socket using `socket()`.
2. Specifies the server's IP and port.
3. Connects to the server using `connect()`.
4. Sends a message to the server.
5. Receives and prints the server’s response.

### Setup Instructions

### On Windows (Server)
g++ tcp_server.cpp -o server -lws2_32
server

## On MacOs (Client)
g++ tcp_client.cpp -o client
./client

## Network Configuration
- Connect both systems to the same Wi-Fi or LAN.
- On Windows, find your IP:
  ```bash
  ipconfig

## Author & License (Optional)
Developed by **Mukesh Kumar Singh**  
Language: **C++17**  
Platforms: **Windows & macOS**



