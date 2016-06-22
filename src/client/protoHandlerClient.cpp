#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include "protoHandlerClient.hpp"
#include "../pb2/phase2.pb.h"
#include "../pb2/sentMessage.pb.h"
#include "../pb2/ecoaType.pb.h"

using namespace google::protobuf;


void ProtoHandler::protoMethod(std::string &message, std::string &messageHeader){
	
	
	//Initialise requestService
	RequestService rS;
	
	rS.set_servicename(message);
	rS.set_description("getNav call");
	std::string str;
	rS.SerializeToString(&str);
	
	/*
	//Initialise person message
	Person p;

	p.set_name("Luke Swift");
	p.set_id(999);
	p.set_debug("Unread");
	std::string str;
	p.SerializeToString(&str);
	*/
	
	cout << "Created Person Message";

	//Create header for message
	messageHeader = rS.descriptor()->full_name();
	std::cout << messageHeader << std::endl;

	message = str;
}

void ProtoHandler::protoPrint(std::string &message){
	Person p;
	
	//Parse message and print debug message to screen
	p.ParseFromString(message);
	std::cout << "Person debug: " << p.debug() << std::endl;
}
