#ifndef INTERFACE
#define INTERFACE

#include "serviceInterface.hpp"

class clientContainer : public Service
{
	public:
		clientContainer();
		~clientContainer();
		
		void addNum(int a, int b);	
};	
#endif