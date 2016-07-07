#include <src/client/C1_Container.hpp>
#include <src/client/C1_Interface.hpp>
#include <iostream>
#include <unistd.h>
#include <string>

#include "C1_Module.hpp"


int main(){

	clientContainer container;
	C1_Service* service = &container;
	ClientModule module(service);
	module.start();
}
