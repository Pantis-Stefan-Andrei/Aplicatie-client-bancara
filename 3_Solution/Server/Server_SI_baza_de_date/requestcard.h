#pragma once
#include "irequest.h"
#include <iostream>
#include <string>

using namespace std;
class requestcard : public irequest
{
public:
	virtual void print(string v, string& r) const override;
};