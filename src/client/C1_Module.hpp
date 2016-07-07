#ifndef CLIENTMODULE
#define CLIENTMODULE

#include "C1_Interface.hpp"

class ClientModule{

public:
	ClientModule(C1_Service* s);
	void start();
private:
	C1_Service* s;
};
#endif
