#include <iostream>
#include <unistd.h>
#include <string>

#include "protoHandlerClient.hpp"
#include "ZMQSender.hpp"
#include "clientContainer.hpp"


clientContainer::clientContainer()		//constructor
{
	std::cout << " clientContainer Constructed...";
}

clientContainer::~clientContainer()		//destructor
{
	std::cout << "clientContainer Destructed...";
}

void clientContainer::addNum(int a, int b)
{
	//define the service message
	std::string message = "addNum";
	std::string messageHeader;	
	
	//two parameters
	int lValue = a;
	int rValue = b;
	
	ProtoHandler pHandle;
	pHandle.protoMethod(message, messageHeader, lValue, rValue);

	ZMQSender zHandle;

	zHandle.zmqMethod(message, messageHeader);	
	
}
