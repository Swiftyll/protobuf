#include <iostream>
#include <unistd.h>
#include <string>

#include "serverContainer.hpp"
#include "serverInterface.hpp"
#include "serverModule.hpp"

int main(){

	serverContainer container;
	Services* service = &container;
	ServerModule module(service);
	module.start();
}
