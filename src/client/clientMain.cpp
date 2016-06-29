#include <iostream>
#include <unistd.h>
#include <string>

#include "clientModule.hpp"
#include "clientContainer.hpp"
#include "serviceInterface.hpp"

int main()
{
	clientContainer container;
	Service* service = &container;
	ClientModule module(service);
	module.start();
}
