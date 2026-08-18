#include "RainEnvironment.h"

RainEnvironment::RainEnvironment() {
	data_arr_.push_back({ 0, 0 });
	data_arr_.push_back({ 10, 30 });
	data_arr_.push_back({ 50, 50 });
	data_arr_.push_back({ 80, 30 });
	data_arr_.push_back({ 20, 30 });
	data_arr_.push_back({ 0, 0 });
}

Data RainEnvironment::now_value(int idx) {
	if(idx < 6)	return data_arr_[idx];
	return		{ 0, 0 };
}