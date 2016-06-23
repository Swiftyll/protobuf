#include <iostream>
#include <unistd.h>
#include <string>

#include "protoHandlerClient.hpp"
#include "ZMQHandlerClient.hpp"

#include "clientInterface.hpp"

class ProxyClient : public Services
{
	public:
		ProxyClient(){}
		~ProxyClient(){}
	
	
		void addNum(){
			//define the service message
			std::string message = "addNum";
			std::string messageHeader;

			
			//two parameters
			//int lValue = a;
			//int rValue = b;
			
			ProtoHandler pHandle;
			pHandle.protoMethod(message, messageHeader);


			ZMQHandler zHandle;

			zHandle.zmqMethod(message, messageHeader);
			
			
			
			//pHandle.protoPrint(message);	//reply..

	}
};
