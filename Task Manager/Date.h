#pragma once
#include <ctime>
#include <iomanip>
#include "MyString.h"

class Date
{
private:
	tm _date = {};

public:
	Date() = default;

	void readDate();
	tm getDate() const;
	void printDate() const;
};

bool operator==(const Date& lhs, const Date& rhs);