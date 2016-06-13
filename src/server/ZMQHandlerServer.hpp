#include <zmq.hpp>
#include <zmq_addon.hpp>
#include <string>

class ZMQHandler
{
   public:
	 ZMQHandler();
     void zmqReadMethod(std::string &message);
	 void zmqReplyMethod(std::string &message);
   private:
	 zmq::context_t _context;//(1);//(1);
     zmq::socket_t _socket;//(_context, ZMQ_REP);

};
