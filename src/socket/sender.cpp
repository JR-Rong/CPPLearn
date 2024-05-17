#include <iostream>
#include <fstream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <chrono>

#include "pro.pb.h"   // 包含protobuf生成的头文件

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

int main() {
    // 初始化socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    // 连接至服务器
    connect(sockfd, (sockaddr*)&servaddr, sizeof(servaddr));

    // 发送序列化的消息
    for(int ii=0;ii<10;ii++){
        // 使用Protobuf序列化消息
        std::fstream input{"/home/lixiang/code/example/CPPLearn/config/person.conf", std::ios::in | std::ios::binary};
        if (!input) {
            std::cerr << "Failed to open config/person.conf file." << std::endl;
            return -1;
        }
        google::protobuf::io::IstreamInputStream fs(&input);
        // 解析配置
        config::personList msg;
        if (!google::protobuf::TextFormat::Parse(&fs, &msg)) {
            std::cerr << "Failed to parse config file." << std::endl;
            return false;
        }
        std::string serialized;
        msg.SerializeToString(&serialized);
        send(sockfd, serialized.data(), serialized.size(), MSG_NOSIGNAL);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        std::cout << "a" << std::endl;
    }
    
    // 关闭socket
    close(sockfd);
    return 0;
}