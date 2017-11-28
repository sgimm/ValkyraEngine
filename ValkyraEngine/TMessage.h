#pragma once
#include "TBaseClass.h"
#include "MessageTypes.h"
class TMessage : public TBaseClass
{
public:
	const char* szSender;
	const char* szReceiver;
	void* MessageObject;
	void* AdditionalMessageObject;
	EMessageTypes MessageType;
	TMessage();
	~TMessage();
};

