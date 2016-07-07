#ifndef SERVERMODULE
#define SERVERMODULE

#include "C2_Interface.hpp"

class ServerModule{

public:
	ServerModule(C2_Service* s);
	void start();
private:
	C2_Service* s;
};
#endif
