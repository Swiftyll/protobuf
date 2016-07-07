#ifndef S_SERVICE
#define S_SERVICE

class C2_Service{

public:
	C2_Service(){}
	~C2_Service(){}
	virtual void addNum(int a, int b) = 0;
	virtual void getMessage() = 0;
};
#endif
