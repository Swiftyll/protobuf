#include <iostream>
#include <unistd.h>
#include <string>


#include "servicesImplementation.cpp"

int main()
{
	Services *s = new ServiceImplementation();
	s->getNav();
	return 0;
}