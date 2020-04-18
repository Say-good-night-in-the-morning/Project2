#include "Server.h"
using namespace server;

Server* Server::instance = NULL;

Server::Server()
{
	ip = 8888;
	memset(&sin, 0, sizeof(sockaddr_in));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(ip);
	sin.sin_addr.s_addr = INADDR_ANY;
	nAddrlen = sizeof(remoteAddr);

}

void server::Server::setIp(u_short IP)
{
	this->ip = IP;
}

Server* server::Server::getInstance()
{
	if (Server::instance == NULL)
		instance = new Server;
	return instance;
}

bool server::Server::isInit()
{
	slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == -1)
	{
		printf("socket error ! error code:%d\n", errno);
		return false;
	}

	if (bind(slisten, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error ! error code:%d\n",errno);
		return false;
	}

	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		printf("listen error ! error code:%d\n", errno);
		return false;
	}

	return true;
}

void server::Server::start()
{
	if (!isInit())
		return;

	while (true)
	{
		
		printf("等待连接...\n");
		sClient = accept(slisten, (sockaddr*)&remoteAddr, &nAddrlen);
		if (sClient == -1)
		{
			printf("accept error !");
			continue;
		}
		printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));

		//接收数据  
		int ret = recv(sClient, revData, 255, 0);
		if (ret > 0)
		{
			revData[ret] = 0x00;
			printf(revData);
			printf("\n");
		}

		//发送数据  
		const char sendData[] = "你好，TCP客户端！\n";
		send(sClient, sendData, strlen(sendData), 0);
		close(sClient);
	}

	close(slisten);
	return;
}




