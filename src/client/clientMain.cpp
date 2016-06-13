#include <iostream>
#include <unistd.h>
#include <string>

#include "protoHandler.hpp"
#include "ZMQHandler.hpp"

int main()
{

	std::string message;
	ProtoHandler pHandle;
	pHandle.protoMethod(message);
	
	ZMQHandler zHandle;
	int i;
	for(i=0;i<10;i++){
		zHandle.zmqMethod(message);
		pHandle.protoPrint(message);
	}
	
}