#include "Client.h"
using namespace cilent;

Cilent* Cilent::instance = NULL;

Cilent::Cilent()
{
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(8888);
	serAddr.sin_addr.s_addr = inet_addr("106.52.165.96");
}

Cilent* Cilent::getInstance()
{
	if (instance == NULL)
		instance = new Cilent;
	return instance;
}

void Cilent::start()
{
	while (true) {
		sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sclient == -1)
		{
			printf("invalid socket!");
			return;
		}

		if (connect(sclient, (sockaddr*)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		{  //连接失败 
			printf("connect error !");
			close(sclient);
			return;
		}

		std::cin >> data;
		sendData = data.c_str();   //string转const char* 
		//char * sendData = "你好，TCP服务端，我是客户端\n";
		send(sclient, sendData, strlen(sendData), 0);
		//send()用来将数据由指定的socket传给对方主机
		//int send(int s, const void * msg, int len, unsigned int flags)
		//s为已建立好连接的socket，msg指向数据内容，len则为数据长度，参数flags一般设0
		//成功则返回实际传送出去的字符数，失败返回-1，错误原因存于error 

		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if (ret > 0) {
			recData[ret] = 0x00;
			printf(recData);
		}
		close(sclient);
	}



}


