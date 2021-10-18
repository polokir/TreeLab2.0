#pragma once
#include <iostream>
#include <cmath>
#include <string>

#include "Random.h"

class DateTime {
private:
	int year, month, day, hour, minute, second;

	bool intercalary(int y);
	int day_in_year(int year);
	int day_in_month(int year, int month);

public:
	DateTime() {
		year = Random(1900, 2100);
		month = Random(1, 12);
		day = Random(1, day_in_month(year, month));
		hour = Random(0, 23);
		minute = Random(0, 59);
		second = Random(0, 59);
	};
	DateTime(int y, int mon, int d, int h, int min, int s)
	{
		year = y;
		month = mon;
		day = d;
		hour = h;
		minute = min;
		second = s;
	};

	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() { return day; }
	int get_hour() { return hour; }
	int get_minute() { return minute; }
	int get_second() { return second; }

	bool date_is_correct();
	int difference_days(DateTime D);
	void add_difference_days(int d);
	long int count_days_from_beg();
	int shift_weekday();
	void cout_weekday();

};


inline DateTime Random(DateTime R) {
	DateTime D;
	return D;
}