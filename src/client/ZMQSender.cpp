#include <zmq.hpp>
#include <zmq_addon.hpp>
#include <string>
#include <iostream>
#include <unistd.h>
#include "ZMQSender.hpp"


ZMQSender::ZMQSender(): _context(1), _socket(_context, ZMQ_PUB){

	_socket.bind ("tcp://*:8123");
	std::cout << "ZMQSender Constructor" << std::endl;
}

ZMQSender::~ZMQSender(){

	std::cout << "ZMQSender Destructor" << std::endl;
}

void ZMQSender::zmqMethod(std::string &message, std::string &messageHeader){

	//Create and send the message
	int message_size =  message.length();
	int header_size = messageHeader.length();

	usleep(500000);
	//send the first part of the multi-part message containing message type
	zmq::message_t header(header_size);
	memcpy(header.data(), messageHeader.c_str(), header_size);
	_socket.send(header, ZMQ_SNDMORE);

	//send the second part of the multi-part message
	zmq::message_t query(message_size);		//send the rest of the message
	memcpy(query.data(), message.c_str(), message_size);
	_socket.send (query);

	//  Get the reply.
	//	zmq::message_t reply;
	//	_socket.recv (&reply);
	//	std::string msg_str(static_cast<char*>(reply.data()), reply.size());
	//	message =  msg_str;
}
