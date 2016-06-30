#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cassert>
#include <fstream>
#include <fcntl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/descriptor_database.h>
#include <google/protobuf/dynamic_message.h>

#include "protoHandlerServer.hpp"

/*  
Function creates a dynamic message using 'allproto.desc' in order to create a dynamic message to modify/read the message being passed in.

A FileDescriptorSet (fds) is created, and populated using 'allproto.desc'. The fds is now used to populate a SimpleDescriptorDatabase (sddb).
	Note: - The .desc file is created at the same time as the .protoc file is compiled using ""descriptor_set_out yes""

The sddb is used to construct a DescriptorPool object (dp).

The dp is used to construct a DynamicMessageFactory (dmf).

The dp's are also used to populate Descriptor objects (dp.FindMessageTypeByName("DescribedMessage")).

The dmf can now be used to create dynamic messages using those created Descriptors, from these dynamic messages there is the ability the parse
the recieved message.

We can create FieldDescriptors for these messages, and use those to Read/Write to individual fields using Reflection


*/

using namespace google::protobuf;

ProtoHandler::ProtoHandler(){
	std::cout << "ProtoHandler constructor..." << std::endl;
}

ProtoHandler::~ProtoHandler(){
	std::cout << "ProtoHandler destructor..." << std::endl;
}

void ProtoHandler::protoMethod(std::string &message, std::string &messageHeader, int &serviceRequest,
								int &lValue, int &rValue){
	
	int cfile = open("allProto.desc", O_RDONLY);
	FileDescriptorSet fileDescSet;
	fileDescSet.ParseFromFileDescriptor(cfile);
	close(cfile);
	SimpleDescriptorDatabase simpleDescDB;
    for ( int i = 0; i < fileDescSet.file_size() ; i++ ){
	   //Iterate over the "file" collection in the FileDescriptorSet
	   //Populate the sddb
       simpleDescDB.Add(fileDescSet.file(i));
    }
	
	DescriptorPool descPool(&simpleDescDB);
	
	DynamicMessageFactory dMsgFactory(&descPool);
	
    const Descriptor* desc;
	
	desc = descPool.FindMessageTypeByName(messageHeader);
	
	Message *msg = dMsgFactory.GetPrototype(desc)->New();
	
	msg->ParseFromArray(message.data(),message.size());
	
	const FieldDescriptor* requestID = desc->FindFieldByName("serviceID");
	const FieldDescriptor* parameterOne = desc->FindFieldByName("paraOnePayload");
	const FieldDescriptor* parameterTwo = desc->FindFieldByName("paraTwoPayload");
	
	const Reflection *msgRefl = msg->GetReflection();

	serviceRequest =  msgRefl->GetInt32(*msg, requestID);
	lValue =  msgRefl->GetInt32(*msg, parameterOne);
	rValue =  msgRefl->GetInt32(*msg, parameterTwo);
	//msgRefl->SetString(msg, debugField, "Read by Server");
	
	msg->SerializeToString(&message);
	
}
