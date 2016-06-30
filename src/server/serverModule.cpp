#include "serverModule.hpp"

ServerModule::ServerModule(Services *s)
{
	this->s =s;
}

void ServerModule::start()
{
	s->getMessage();
}
