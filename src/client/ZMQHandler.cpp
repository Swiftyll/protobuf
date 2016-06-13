#include <zmq.hpp>
#include <zmq_addon.hpp>
#include <string>
#include <iostream>

#include "ZMQHandler.hpp"

using namespace std;

void ZMQHandler::zmqMethod(string &message){

	zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);
	socket.connect ("tcp://localhost:8123");

	int message_size =  message.length();
	zmq::message_t query(message_size);
	memcpy(query.data(), message.c_str(), message_size);
	socket.send (query);

	//  Get the reply.
	zmq::message_t reply;
	socket.recv (&reply);


	
	
}