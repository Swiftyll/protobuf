#include "C2_Module.hpp"

#include <iostream>

ServerModule::ServerModule(C2_Service *s){

	std::cout << "severModule constructor" << std::endl;
	this->s =s;
}

void ServerModule::start(){

	s->getMessage();
}
