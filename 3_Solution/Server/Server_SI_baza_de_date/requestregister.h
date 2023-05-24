
#pragma once
#include "DAL.h"
#include "irequest.h"
#include <iostream>
#include <string>
 
using namespace std;
class requestregister : public irequest
{
public:
	virtual void print(string v, string &r) const override;
};