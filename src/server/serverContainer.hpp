#ifndef S_INTERFACE
#define S_INTERFACE

#include "serverInterface.hpp"

class serverContainer : public Services{

	public:
		serverContainer();
		virtual ~serverContainer();

		void addNum(int a, int b);
		void getMessage();
};
#endif
