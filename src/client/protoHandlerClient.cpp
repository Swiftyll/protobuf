#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include "protoHandlerClient.hpp"
#include "../pb2/phase2.pb.h"
#include "../pb2/sentMessage.pb.h"


using namespace google::protobuf;


void ProtoHandler::protoMethod(std::string &message, std::string &messageHeader){
	
	//Initialise person message
	Person p = Person();
	//p.set_description(p.descriptor()->full_name());
	p.set_name("Luke Swift");
	p.set_id(999);
	p.set_debug("Unread");
	std::string str;
	p.SerializeToString(&str);
	cout << "Created Person Message";
	
	
	//Create header for message

	messageHeader = p.descriptor()->full_name();
	std::cout << messageHeader << std::endl;
	/*
	//Initialise envelope message
	DescribedMessage dMsg;
	dMsg.set_full_name(p.descriptor()->full_name());
	dMsg.set_message(str);
	dMsg.set_debug_msg("Unread");
	
	
	std::string data;
	dMsg.SerializeToString(&data);s
	*/
	message = str;
	//int sz = message.length();
	//std::cout << "Created Envelope Message";

	
}

void ProtoHandler::protoPrint(std::string &message){
	
	//DescribedMessage dMsg;
	Person p;
	
	//dMsg.ParseFromArray(message.data(),message.size());
	p.ParseFromString(message);
	std::cout << "Person debug: " << p.debug() << std::endl;
}
