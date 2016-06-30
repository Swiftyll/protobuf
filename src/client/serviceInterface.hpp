#ifndef SERVICES
#define SERVICES

class Service {
	public:
		Service(){}
		virtual ~Service() {}	
		virtual void addNum(int a,int b) = 0;
};
#endif
