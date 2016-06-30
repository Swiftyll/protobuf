#include <zmq.hpp>
#include <zmq_addon.hpp>
#include <string>
#include <iostream>

#include "ZMQSender.hpp"


ZMQSender::ZMQSender(): _context(1), _socket(_context, ZMQ_REQ){

	_socket.connect ("tcp://localhost:8123");
	std::cout << "ZMQSender Constructor" << std::endl;
}

ZMQSender::~ZMQSender(){

	std::cout << "ZMQSender Destructor" << std::endl;
}

void ZMQSender::zmqMethod(std::string &message, std::string &messageHeader){

	//Create and send the message
	int message_size =  message.length();
	int header_size = messageHeader.length();
	
	zmq::message_t header(header_size);		//message header defining message type
	memcpy(header.data(), messageHeader.c_str(), header_size);
	_socket.send(header, ZMQ_SNDMORE);		//ZMQ_SNDMORE flag to specify multi-part
	
	zmq::message_t query(message_size);		//send the rest of the message
	memcpy(query.data(), message.c_str(), message_size);
	_socket.send (query);

	//  Get the reply.
	zmq::message_t reply;
	_socket.recv (&reply);
	std::string msg_str(static_cast<char*>(reply.data()), reply.size());
	message =  msg_str;
}
