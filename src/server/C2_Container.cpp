#include "C2_Container.hpp"

#include <iostream>
#include <unistd.h>
#include <map>

#include "ProtoHandler_C2.hpp"
#include "ZMQReceiver.hpp"

serverContainer::serverContainer(){

	std::cout << "serverContainer constructor.." << std::endl;
}

serverContainer::~serverContainer(){

	std::cout << "serverContainer destructor.." << std::endl;
}

void serverContainer::addNum(int a,int b){

	std::cout << "sum of the two numbers: " << a + b << std::endl;
}

void serverContainer::getMessage(){
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

	if(serviceRequest == 1)	{
		addNum(lValue, rValue);
	}
}
