#include"Client.h"

using namespace cilent;

int main()
{
	Cilent* c = Cilent::getInstance();
	c->start();
	return 0;
}