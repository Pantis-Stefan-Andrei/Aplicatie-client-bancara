#pragma once

#include <iostream>
#include <string>
#include"string.h"

using namespace std;
__interface irequest
{
public:
	virtual void print(string nr, string &r) const = 0;
};
namespace FactoryRequest
{
	enum class TipRequest {amenda,rdelete,deschidere,login,vizualizare,inregistrare,virament,card};
	static irequest* factoryStaticMethod(TipRequest tip);
}