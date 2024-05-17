#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "pro.pb.h"   // 包含protobuf生成的头文件

int main() {
    // 初始化socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    bind(sockfd, (sockaddr*)&servaddr, sizeof(servaddr));
    listen(sockfd, 10);

    // 接受连接
    while(true) {
        int connfd = accept(sockfd, (sockaddr*)NULL, NULL);

        std::cout << "adabasdfaweaasdfe" << std::endl;

        bool keep_receiving = true;
        while (keep_receiving) {  // 第二层循环 - 持续接收数据
            char buffer[1024] = {0};
            int bytes_read = read(connfd, buffer, 1024);
            
            if (bytes_read > 0) {
                // 使用Protobuf反序列化消息
                config::personList msg;
                msg.ParseFromArray(buffer, 1024);
                for(auto pp : msg.people()) {
                    std::cout << "Received person name: " << pp.name() << ", age: " << pp.age() << ", email: " << pp.email() << std::endl;
                }
            } else if (bytes_read == 0) {
                // 接收到0字节数据，通常表示发送端已正常关闭了连接
                std::cout << "Connection closed by peer" << std::endl;
                keep_receiving = false;
            } else {
                // 发生错误，处理错误
                std::cerr << "Error on receiving data" << std::endl;
                keep_receiving = false;
            }
        }
        
        // 关闭socket
        close(connfd);
        break;
    }
    
    close(sockfd);
    return 0;
}