#include <iostream>
#include <unistd.h>
#include <string>

#include "serverImplementation.cpp"

int main()
{
	Services* s = new ServiceImplementation();
	s->getNav();
	
}