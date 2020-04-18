#pragma once
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstdio>
#include<iostream>
#include<cstring>

typedef int SOCKET;
typedef unsigned char BYTE;
typedef unsigned long WORD;
#define FALSE 0
#define SOCKET_ERROR (-1)

namespace cilent
{
	class Cilent
	{
	public:
		/** 获取单例模式实例 */
		static Cilent* getInstance();
		/** 运行入口 */
		void start();
	private:
		WORD sockVersion;
		sockaddr_in serAddr;
		SOCKET sclient;
		std::string data;
		const char* sendData;
		char revData[255];
		u_short ip;

		static Cilent* instance;

		Cilent();
	};
}
