#pragma once

typedef struct data_ {
	int rain_data;
	int speed_data;
}Data;

class IEnvironment
{
public:
	virtual ~IEnvironment() = default;

	virtual Data now_value(int idx) = 0;
};

