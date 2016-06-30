#include <iostream>
#include <unistd.h>

#include "serverContainer.hpp"
#include "protoHandlerServer.hpp"
#include "ZMQReceiver.hpp"

serverContainer::serverContainer()
{

}

serverContainer::~serverContainer()
{

}

void serverContainer::addNum(int a,int b)
{
	std::cout << "sum of the two numbers: " << a + b << std::endl;
}

void serverContainer::getMessage()
{
	std::cout << "started" << std::endl;

	usleep(1000);
	std::string message;
	std::string messageHeader;
	int serviceRequest;
	int lValue;
	int rValue;


	ProtoHandler pHandle;
	ZMQHandler zHandle;

	zHandle.zmqReadMethod(message, messageHeader);
	pHandle.protoMethod(message, messageHeader, serviceRequest, lValue, rValue);

	if(serviceRequest == 1){
		addNum(lValue, rValue);
	}
}
