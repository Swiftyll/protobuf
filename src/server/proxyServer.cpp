#include <iostream>
#include <unistd.h>
#include <string>


#include "protoHandlerServer.hpp"
#include "ZMQHandlerServer.hpp"

#include "serverInterface.hpp"

class ProxyServer : public Services
{
	public:
		ProxyServer(){}
		~ProxyServer(){}
		void addNum(int a,int b){
			std::cout << "sum of the two numbers: " << a + b << std::endl;
		}
	
		void getMessage(){
			std::cout << "started" << std::endl;
	
			usleep(1000);
			std::string message;
			std::string messageHeader;
			int serviceRequest;
			int lValue;
			int rValue;
			
			
			ProtoHandler pHandle;
			ZMQHandler zHandle;

			zHandle.zmqReadMethod(message, messageHeader);	
			pHandle.protoMethod(message, messageHeader, serviceRequest, lValue, rValue);

			if(serviceRequest == 1){
				addNum(lValue, rValue);
			}
	}
};