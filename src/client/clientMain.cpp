#include <iostream>
#include <unistd.h>
#include <string>

#include "proxyClient.cpp"

int main()
{
	Services *s = new ProxyClient();
	s->addNum();

}