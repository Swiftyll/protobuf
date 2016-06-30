#ifndef SERVERMODULE
#define SERVERMODULE

#include "serverInterface.hpp"

class ServerModule{

	public:
		ServerModule(Services* s);
		void start();
	private:
		Services* s;
};
#endif
