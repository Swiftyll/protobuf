#ifndef S_INTERFACE
#define S_INTERFACE

#include <map>
#include "C2_Interface.hpp"

class serverContainer : public C2_Service {

public:
	serverContainer();
	virtual ~serverContainer();

	void addNum(int a, int b);
	void getMessage();

};
#endif

