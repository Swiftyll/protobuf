#include <iostream>
#include <unistd.h>
#include <string>

#include "protoHandlerClient.hpp"
#include "ZMQHandlerClient.hpp"

int main()
{
	std::string message;
	
	ProtoHandler pHandle;
	pHandle.protoMethod(message);
	
	ZMQHandler zHandle;
	int count;
	
	//Send message 10 sends and process reply
	for(count=0;count<10;count++){
		zHandle.zmqMethod(message);
		pHandle.protoPrint(message);
	}
	
}