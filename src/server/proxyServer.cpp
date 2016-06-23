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
		void addNum(){
			std::cout << "sum of the two numbers: " << std::endl;
		}
	
		void getMessage(){
			std::cout << "started" << std::endl;
	
			usleep(1000);
			std::string message;
			std::string messageHeader;
			std::string serviceRequest;
			
			
			ProtoHandler pHandle;
			ZMQHandler zHandle;

			zHandle.zmqReadMethod(message, messageHeader);	
			pHandle.protoMethod(message, messageHeader, serviceRequest);

			if(serviceRequest == "addNum"){
				addNum();
			}
	}
};