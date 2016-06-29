#ifndef CLIENTMODULE
#define CLIENTMODULE

#include "serviceInterface.hpp"

class ClientModule
{
	public:
		ClientModule(Service* s);
		void start();
	private:
		Service* s;
};
#endif