#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include "protoHandlerClient.hpp"
#include "../pb2/phase2.pb.h"
#include "../pb2/sentMessage.pb.h"


using namespace google::protobuf;


void ProtoHandler::protoMethod(std::string &message){
	
	//Initialise person message
	Person p = Person();
	p.set_name("Luke Swift");
	p.set_id(999);
	p.set_debug("Unread");
	std::string str;
	p.SerializeToString(&str);
	cout << "Created Person Message";
	
	//Initialise envelope message
	DescribedMessage dMsg;
	dMsg.set_full_name(p.descriptor()->full_name());
	dMsg.set_message(str);
	dMsg.set_debug_msg("Unread");

	std::string data;
	dMsg.SerializeToString(&data);
	message = data;
	//int sz = message.length();
	std::cout << "Created Envelope Message";

	
}

void ProtoHandler::protoPrint(std::string &message){
	
	DescribedMessage dMsg;
	Person p;
	
	dMsg.ParseFromArray(message.data(),message.size());
	p.ParseFromString(dMsg.message());
	std::cout << "Person debug: " << p.debug() << std::endl;
}
