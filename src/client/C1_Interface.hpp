#ifndef SERVICES
#define SERVICES

class C1_Service {

public:
	C1_Service(){}
	virtual ~C1_Service() {}
	virtual void addNum(int a,int b) = 0;
	virtual void getNav();
};
#endif
