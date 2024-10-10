// receiver.cpp
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    const int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        std::cerr << "Error creating socket!" << std::endl;
        return 1;
    }

    struct sockaddr_in myaddr;
    memset(&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_port = htons(12345); // Replace with your port
    myaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0)
    {
        std::cerr << "Bind failed!" << std::endl;
        close(sockfd);
        return 1;
    }

    std::cout << "Waiting for messages..." << std::endl;
    const int total_size = 2048;
    int bytes_received = 0;
    char message[total_size];
    int chunk_count = 0;

    while (bytes_received < total_size)
    {
        char buf[512];
        struct sockaddr_in remaddr;
        socklen_t addrlen = sizeof(remaddr);
        ssize_t recvlen = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&remaddr, &addrlen);
        if (recvlen > 0)
        {
            memcpy(message + bytes_received, buf, recvlen);
            bytes_received += recvlen;
            std::cout << "Received chunk " << ++chunk_count << ": " << recvlen << " bytes." << std::endl;
        }
        else if (recvlen < 0)
        {
            std::cerr << "recvfrom failed" << std::endl;
            break;
        }
    }

    if (bytes_received == total_size)
    {
        std::cout << "Full message received: " << bytes_received << " bytes." << std::endl;
    }
    else
    {
        std::cerr << "Only part of the message was received: " << bytes_received << " bytes." << std::endl;
    }

    close(sockfd);
    return 0;
}