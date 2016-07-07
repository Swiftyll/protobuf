#include <src/server/C2_Container.hpp>
#include <src/server/C2_Interface.hpp>
#include <src/server/C2_Module.hpp>
#include <iostream>
#include <unistd.h>
#include <string>


int main(){

	serverContainer container;		// Create the component container
	C2_Service*  service = &container;
	ServerModule module(service);
	module.start();
}
