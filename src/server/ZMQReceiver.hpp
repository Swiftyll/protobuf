#include <zmq.hpp>
#include <zmq_addon.hpp>
#include <string>

class ZMQHandler
{
public:
	ZMQHandler();
	~ZMQHandler();

	void zmqReadMethod(std::string &message, std::string &messageHeader);
	void zmqReplyMethod(std::string &message);

private:
	zmq::context_t _context;
	zmq::socket_t _socket;
};
