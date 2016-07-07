#ifndef C_INTERFACE
#define C_INTERFACE

#include <string>
#include <map>

#include "C1_Interface.hpp"

class clientContainer : public C1_Service {
public:
	clientContainer();
	~clientContainer();

	void addNum(int a, int b);
	void getNav();

private:
	std::map <int, std::string> I_Map;

};	
#endif
