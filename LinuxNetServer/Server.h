#pragma once
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<errno.h>
typedef int SOCKET;
typedef unsigned char BYTE;
typedef unsigned long WORD;
#define FALSE 0
#define SOCKET_ERROR (-1)

namespace server
{
    class Server
    {

    private:
        WORD sockVersion;
        sockaddr_in sin;
        SOCKET slisten;
        SOCKET sClient;
        sockaddr_in remoteAddr;
        socklen_t nAddrlen;
        char revData[255];
        u_short ip;
        static Server* instance;

        Server();
        //Server(Server&) = delete;
        //Server& operator= (const Server&) = delete;

    public:

        /** 判断是否初始化成功 */
        bool isInit();

        /** 循环接收客户端信息 */
        void start();

        /** 修改ip */
        void setIp(u_short);

        /** 获取单例模式 */
        static Server* getInstance();

    };

}