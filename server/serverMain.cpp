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
	int i;
	for(i=0;i<10;i++){
	zHandle.zmqReadMethod(message);
	pHandle.protoMethod(message);
	zHandle.zmqReplyMethod(message);
	}
}