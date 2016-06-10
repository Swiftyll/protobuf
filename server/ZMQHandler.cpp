#include <string>
#include <iostream>

#include "ZMQHandler.hpp"

using namespace std;

ZMQHandler::ZMQHandler(): _context(1),_socket(_context, ZMQ_REP) {
	_socket.bind ("tcp://*:8123");
}

void ZMQHandler::zmqReadMethod(std::string &message){
	
	std::cout << "debug";
	bool ok = true;

    while (true) {
		std::cout << "While loop" << endl;
        //  Wait for next request from client
        zmq::message_t request;
        ok = _socket.recv(&request);
        assert(ok);
		
		std::string msg_str(static_cast<char*>(request.data()), request.size());
		message = msg_str;
		cout << "after while loop" << endl;
    }
    
}

void ZMQHandler::zmqReplyMethod(std::string &message){
	
    _socket.bind ("tcp://0.0.0.0:8123");
	zmq::message_t reply;
	memcpy(reply.data(), message.c_str(), message.length());
	
	_socket.send (reply);
	
}