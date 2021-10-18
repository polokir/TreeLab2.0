#include "DataTime.h"
#include<iostream>

using namespace std;



bool DateTime::intercalary(int y) {
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) return true;
	else return false;
}



int DateTime::day_in_year(int year) {
	return 365 + intercalary(year);
}


int DateTime::day_in_month(int year, int month) {
	if (month == 2) return 28 + intercalary(year);
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 31;
}


bool DateTime::date_is_correct() {
	if (month > 12 || month < 0 || hour > 23 || hour < 0 || minute > 59 || minute < 0 || second > 59 || second < 0) return false;
	if (day < 0 || day > day_in_month(year, month)) return false;
	return true;
}


long int DateTime::count_days_from_beg() {
	long int d = 0;
	for (int i = 1; i < year; i++) d = d + day_in_year(i);
	for (int j = 1; j < month; j++) d = d + day_in_month(year, j);
	return d + day;
}


int DateTime::difference_days(DateTime D) {
	int d = abs(D.count_days_from_beg() - count_days_from_beg());
	return d;
}


void DateTime::add_difference_days(int d) {
	for (int i = 0; i < d; i++) {
		day++;
		if (day > day_in_month(year, month)) {
			day = 1;
			month++;
		}
		if (month > 12) {
			month = 1;
			year++;
		}
	}
}



int DateTime::shift_weekday() {
	if (!this->date_is_correct()) return -1;
	int shift = 1;
	for (int i = 1; i < year; i++)
		if (intercalary(i))shift += 2;//in intercalary years weekday shifts on 2 days
		else shift++;
	for (int i = 1; i < month; i++)
		shift += day_in_month(year, i);
	shift = shift + day - 1;
	return shift;
}



void DateTime::cout_weekday() {
	int shift = shift_weekday();
	if (shift < 0) {
		std::cout << "The date is not correct for now" << std::endl;
		return;
	}

	shift = shift % 7;
	switch (shift) {
	case 1: std::cout << "Monday"; break;
	case 2: std::cout << "Tuesday"; break;
	case 3: std::cout << "Wednesday"; break;
	case 4: std::cout << "Thursday"; break;
	case 5: std::cout << "Friday"; break;
	case 6: cout << "Saturday"; break;
	case 0: cout << "Sunday"; break;
	default:
		std::cout << "The date is not correct";
		break;
	}
	std::cout << std::endl;
}