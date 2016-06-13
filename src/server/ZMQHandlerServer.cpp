#include <string>
#include <iostream>

#include "ZMQHandlerServer.hpp"

using namespace std;

ZMQHandler::ZMQHandler(): _context(1),_socket(_context, ZMQ_REP) {
	_socket.bind ("tcp://*:8123");
}

void ZMQHandler::zmqReadMethod(std::string &message){
	
	//  Wait for next request from client
	zmq::message_t request;
	 _socket.recv(&request);

	std::string msg_str(static_cast<char*>(request.data()), request.size());
	message = msg_str;

}

void ZMQHandler::zmqReplyMethod(std::string &message){

	cout << message << endl;
	zmq::message_t reply(message.length());
	memcpy(reply.data(), message.c_str(), message.length());
	_socket.send (reply);
	
}