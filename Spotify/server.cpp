// server.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port number
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);

    std::cout << "Server listening on port 12345" << std::endl;

    while (true) {
        int clientSocket = accept(serverSocket, NULL, NULL);
        std::cout << "Client connected" << std::endl;

        std::ifstream musicFile("erg.mp3", std::ios::binary);
        if (!musicFile.is_open()) {
            std::cerr << "Failed to open music file" << std::endl;
            return 1;
        }

        char buffer[1024];
        while (!musicFile.eof()) {
            musicFile.read(buffer, sizeof(buffer));
            send(clientSocket, buffer, musicFile.gcount(), 0);
        }

        close(clientSocket);
        musicFile.close();
        std::cout << "Music file sent" << std::endl;
    }

    close(serverSocket);
    return 0;
}

