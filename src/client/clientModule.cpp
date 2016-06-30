#include "clientModule.hpp"

ClientModule::ClientModule(Service* s){

	this->s = s;
}

void ClientModule::start(){

	s->addNum(2,5);
}
