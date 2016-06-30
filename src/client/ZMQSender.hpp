#include <string>
#include <zmq.hpp>
#include <zmq_addon.hpp>

class ZMQSender{

	public:
		ZMQSender();
		~ZMQSender();
		void zmqMethod(std::string &message, std::string &messageHeader );

	private:
		zmq::context_t _context;
		zmq::socket_t _socket;
};
