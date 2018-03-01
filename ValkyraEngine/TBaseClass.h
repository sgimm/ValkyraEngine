#pragma once
class TBaseClass;
class TBaseClass
{
public:
	TBaseClass();
	~TBaseClass();
protected:
	const char* m_szClassName;
	virtual const char* Serialize() { return nullptr; };
	virtual TBaseClass* Deserialize(const char* szStream) { return nullptr; };
};

