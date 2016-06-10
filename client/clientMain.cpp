#include <iostream>
#include <unistd.h>
#include <string>

#include "protoHandler.hpp"
#include "ZMQHandler.hpp"

int main()
{
	std::cout << "started" << std::endl;
	std::string message;
	
	ProtoHandler pHandle;
	pHandle.protoMethod(message);
	
	ZMQHandler zHandle;
	zHandle.zmqMethod(message);
}