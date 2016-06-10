#include <iostream>
#include <unistd.h>
#include <string>

#include "protoHandler.hpp"
#include "ZMQHandler.hpp"

int main()
{
	std::cout << "started" << std::endl;
	
	usleep(1000);
	std::string message;
	
	
	ProtoHandler pHandle;
	ZMQHandler zHandle;
	
	zHandle.zmqReadMethod(message);
	pHandle.protoMethod(message);
	zHandle.zmqReplyMethod(message);
	
}