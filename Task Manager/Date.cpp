#include "Date.h"

void Date::setDateToToday()
{
	std::time_t now;
	std::time(&now);// get current time

	localtime_s(&_date, &now);
}

void Date::readDate()
{
	if (!(std::cin >> std::get_time(&_date, "%Y-%m-%d")))
	{
		std::cout << "Error reading date\n";
		throw _exception();
	}
}

tm Date::getDate() const
{
	return _date;
}

void Date::printDate() const
{
	std::cout << std::put_time(&_date, "%a %b %d %H:%M:%S %Y") << std::endl;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return (lhs.getDate().tm_year == rhs.getDate().tm_year &&
		lhs.getDate().tm_mon == rhs.getDate().tm_mon &&
		lhs.getDate().tm_mday == rhs.getDate().tm_mday);
}

bool operator>(const Date& lhs, const Date& rhs)
{
	// Compare year
	if (lhs.getDate().tm_year > rhs.getDate().tm_year) return true;
	if (lhs.getDate().tm_year < rhs.getDate().tm_year) return false;

	// Compare month
	if (lhs.getDate().tm_mon > rhs.getDate().tm_mon) return true;
	if (lhs.getDate().tm_mon < rhs.getDate().tm_mon) return false;

	// Compare day
	if (lhs.getDate().tm_mday > rhs.getDate().tm_mday) return true;
	if (lhs.getDate().tm_mday < rhs.getDate().tm_mday) return false;

	return false; // If all components are equal, return false
}