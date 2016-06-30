#ifndef S_SERVICE
#define S_SERVICE

class Services{

	public:
		Services(){}
		~Services(){}
		virtual void addNum(int a, int b) = 0;
		virtual void getMessage() = 0;
};
#endif
