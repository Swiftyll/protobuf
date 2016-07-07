#include "C1_Container.hpp"

#include <iostream>
#include <unistd.h>
#include <string>

#include "ProtoHandler_C1.hpp"
#include "ZMQSender.hpp"


clientContainer::clientContainer(){			//constructor

	std::cout << " clientContainer Constructed...";

}

clientContainer::~clientContainer(){		//destructor

	std::cout << "clientContainer Destructed...";
}

void clientContainer::addNum(int a, int b){		//addNum implementation

	I_Map[1,4];
	//define the service message
	std::string message = "addNum";
	std::string messageHeader;	

	//two parameters
	int lValue = a;
	int rValue = b;

	//serialize the message using protocol buffers
	ProtoHandler pHandle;
	pHandle.protoMethod(message, messageHeader, lValue, rValue);

	//send the message through ZMQ
	ZMQSender zHandle;
	zHandle.zmqMethod(message, messageHeader);	

}

void clientContainer::getNav(){		//getNav implementation
	//tbc...
}
