#include "Date.h"

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
