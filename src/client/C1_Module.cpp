#include "C1_Module.hpp"

ClientModule::ClientModule(C1_Service* s){

	this->s = s;
}

void ClientModule::start(){

	s->addNum(2,5);
}
