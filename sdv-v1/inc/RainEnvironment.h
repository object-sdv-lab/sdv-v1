#pragma once
#include "IEnvironment.h"
#include <vector>

using namespace std;

class RainEnvironment : public IEnvironment
{
private:
	vector<Data> data_arr_;

public:
	RainEnvironment();
	Data now_value(int idx);
};