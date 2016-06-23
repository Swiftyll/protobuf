#include <iostream>
#include <unistd.h>
#include <string>

#include "proxyServer.cpp"

int main()
{
	Services *s = new ProxyServer();
	s->getMessage();
	
}