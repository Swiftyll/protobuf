#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include "protoHandlerClient.hpp"
#include "../pb2/ecoaType.pb.h"

using namespace google::protobuf;




void ProtoHandler::protoMethod(std::string &message, std::string &messageHeader){
	
	
	//Initialise requestService & parameters
	RequestService rS;
	
	rS.set_servicename(message);		 
	rS.set_description("addNum call");
	
	std::string str;
	rS.SerializeToString(&str);
	
	// parameter as message
	/*
	//conver int to bytes
	int *p = &lValue;
	char* byteMessage;
	memcpy(byteMessage,p,4);
	
	int *p2 = &rValue;
	char* byteMessage2;
	memcpy(byteMessage2,p2,4);
	
	
	rSParameterOne.set_parametertype("int");
	rSParameterOne.set_parameterdata(lValue);
	rSParameterOne.SerializeToString(&parameterOne);
	
	rSParameterTwo.set_parametertype("int");
	rSParameterTwo.set_parameterdata(rValue);
	rSParameterTwo.SerializeToString(&parameterTwo);
	*/
	
	cout << "Created message";
	
	//Create header for message
	messageHeader = rS.descriptor()->full_name();
	std::cout << messageHeader << std::endl;

	message = str;
}

void ProtoHandler::protoPrint(std::string &message){
	//Person p;
	
	//Parse message and print debug message to screen
	//p.ParseFromString(message);
	//std::cout << "Person debug: " << p.debug() << std::endl;
}
