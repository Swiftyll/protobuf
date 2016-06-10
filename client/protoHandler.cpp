#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include "protoHandler.hpp"
#include "phase2.pb.h"
#include "sentMessage.pb.h"


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
