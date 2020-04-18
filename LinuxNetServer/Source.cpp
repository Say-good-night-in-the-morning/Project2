#include "Server.h"

int main()
{
	server::Server* s = server::Server::getInstance();
	s->start();
	return 0;
}