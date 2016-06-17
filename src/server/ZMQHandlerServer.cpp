#include <string>
#include <iostream>
#include <vector>

#include "ZMQHandlerServer.hpp"

using namespace std;

ZMQHandler::ZMQHandler(): _context(1),_socket(_context, ZMQ_REP) {
	_socket.bind ("tcp://*:8123");
}

void ZMQHandler::zmqReadMethod(std::string &message, std::string &messageHeader){
	

	vector<string> v; // we know the multipart message has two parts 

	// process all parts of a multi-part message and place into vector v;
	 while (1) {
        //  Process all parts of the message
        zmq::message_t recMessage;
        _socket.recv(&recMessage);

        //  Dump the message as text or binary
        int size = recMessage.size();
        std::string data(static_cast<char*>(recMessage.data()), size);
		v.push_back(data);
		
        bool is_text = true;

        int char_nbr;
        unsigned char byte;
        for (char_nbr = 0; char_nbr < size; char_nbr++) {
            byte = data [char_nbr];
            if (byte < 32 || byte > 127)
                is_text = false;
        }
        std::cout << "[" << std::setfill('0') << std::setw(3) << size << "]";
        for (char_nbr = 0; char_nbr < size; char_nbr++) {
            if (is_text)
                std::cout << (char)data [char_nbr];
            else
                std::cout << std::setfill('0') << std::setw(2)
                   << std::hex << (unsigned int) data [char_nbr];
        }
        std::cout << std::endl;

        int more = 0;           //  Multipart detection
        size_t more_size = sizeof (more);
        _socket.getsockopt (ZMQ_RCVMORE, &more, &more_size);
        if (!more)
            break;              //  Last message part
    }
	messageHeader = v[0];
	message = v[1];

}

void ZMQHandler::zmqReplyMethod(std::string &message){

	cout << message << endl;
	zmq::message_t reply(message.length());
	memcpy(reply.data(), message.c_str(), message.length());
	_socket.send (reply);
	
}