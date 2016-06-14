#include <zmq.hpp>
#include <zmq_addon.hpp>
#include <string>
#include <iostream>

#include "ZMQHandlerClient.hpp"

using namespace std;

void ZMQHandler::zmqMethod(string &message, string &messageHeader){
	//Set up ZMQ 
	zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);
	socket.connect ("tcp://localhost:8123");

	//Create and send the message
	int message_size =  message.length();
	int header_size = messageHeader.length();
	
	zmq::message_t header(header_size);
	memcpy(header.data(), messageHeader.c_str(), header_size);
	socket.send(header, ZMQ_SNDMORE);
	
	zmq::message_t query(message_size);
	memcpy(query.data(), message.c_str(), message_size);
	socket.send (query);

	//  Get the reply.
	zmq::message_t reply;
	socket.recv (&reply);
	std::string msg_str(static_cast<char*>(reply.data()), reply.size());
	message =  msg_str;
}