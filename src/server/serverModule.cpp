#include <iostream>
#include "serverModule.hpp"

ServerModule::ServerModule(Services *s){

	std::cout << "severModule constructor" << std::endl;
	this->s =s;
}

void ServerModule::start(){

	s->getMessage();
}
