#include <string>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include "../pb2/ecoaType.pb.h"
#include "ProtoHandler_C1.hpp"


void ProtoHandler::protoMethod(std::string &message, std::string &messageHeader,
		int &lValue, int &rValue ){

	//Initialise requestService & parameters
	RequestService rS;

	rS.set_serviceid(1);
	rS.set_messagetype("RequestService");

	rS.set_paraonetype("int");
	rS.set_paraonepayload(2);

	rS.set_paratwotype("int");
	rS.set_paratwopayload(2);

	std::string str;
	rS.SerializeToString(&str);

	std::cout << "Created message";

	//Create header for message
	messageHeader = rS.descriptor()->full_name();
	std::cout << messageHeader << std::endl;

	message = str;
}

void ProtoHandler::protoPrint(std::string &message)
{
	//needs to be implemented...
}
