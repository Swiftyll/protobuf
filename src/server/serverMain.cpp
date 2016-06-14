#include <iostream>
#include <unistd.h>
#include <string>

#include "protoHandlerServer.hpp"
#include "ZMQHandlerServer.hpp"

int main()
{
	std::cout << "started" << std::endl;
	
	usleep(1000);
	std::string message;
	std::string messageHeader;
		
	ProtoHandler pHandle;
	ZMQHandler zHandle;
	
	int count;
	
	for(count=0;count<10;count++){	
		zHandle.zmqReadMethod(message, messageHeader);
		pHandle.protoMethod(message, messageHeader);
		zHandle.zmqReplyMethod(message);
	}
}