#include <string>

class ProtoHandler{

public:
	ProtoHandler();
	~ProtoHandler();
	void protoMethod(std::string &message, std::string &messageHeader, int &serviceRequest, int &lValue, int &rValue);

};
