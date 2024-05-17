#include <fstream>
#include <iostream>
#include <sstream>

#include "pro.pb.h" // 引入生成的头文件

#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

using namespace std;

int main() {
    // 初始化protobuf库
    // 打开配置文件
    fstream input{"/home/lixiang/code/example/CPPLearn/config/person.conf", ios::in | ios::binary};
    if (!input) {
        cerr << "Failed to open config/person.conf file." << endl;
        return -1;
    }

    google::protobuf::io::IstreamInputStream fs(&input);

    // 解析配置
    config::personList psl;
    if (!google::protobuf::TextFormat::Parse(&fs, &psl)) {
        cerr << "Failed to parse config file." << endl;
        return false;
    }
    

    // 调试打印
    for(auto ps : psl.people()) {
        cout << "Name: " << ps.name() << endl;
        cout << "Age: " << ps.age() << endl;
        cout << "Email: " << ps.email() << endl;
    }

    // 清理protobuf库资源
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}