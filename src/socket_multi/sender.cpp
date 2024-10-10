// sender.cpp
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    const int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0)
    {
        std::cerr << "Error creating socket!" << std::endl;
        return 1;
    }

    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(12345);                    // replace with the receiver's port
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr); // replace with the receiver's IP

    const int message_size = 2048; // 2KB
    const int chunk_size = 500;
    char message[message_size];
    std::fill_n(message, message_size, 'A'); // Fill the message with 'A's for simplicity

    // Now we send the message in chunks
    int bytes_sent = 0;
    while (bytes_sent < message_size)
    {
        int current_chunk_size = std::min(chunk_size, message_size - bytes_sent);
        int sent = sendto(sockfd, message + bytes_sent, current_chunk_size, 0,
                          (struct sockaddr *)&serveraddr, sizeof(serveraddr));
        if (sent < 0)
        {
            std::cerr << "sendto failed" << std::endl;
            break;
        }
        bytes_sent += sent;
    }

    if (bytes_sent == message_size)
    {
        std::cout << "Full message sent." << std::endl;
    }
    else
    {
        std::cerr << "Only part of the message was sent." << std::endl;
    }

    close(sockfd);
    return 0;
}