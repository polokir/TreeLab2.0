#pragma once
#include"DataTime.h"
#include<string>
using namespace std;


template<typename T> 
bool is_equal(T a, T b) {
	if (a == b) return true;
	else return false;
}


bool Equally(DateTime a, DateTime b) {
	if (a.get_year() != b.get_year()) return false;
	if (a.get_month() != b.get_month()) return false;
	if (a.get_day() != b.get_day()) return false;
	if (a.get_hour() != b.get_hour()) return false;
	if (a.get_minute() != b.get_minute()) return false;
	if (a.get_second() != b.get_second()) return false;
	return true;
}

bool Equally(string a, string b) {
	if (a == b) return true;
	return false;
}