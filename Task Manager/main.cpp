#include <iostream>
#include "System.h"
#include "Date.h"

#include <iomanip>      // std::put_time, std::get_time
#include <ctime>        // std::time_t, struct std::tm, std::localtime

int main()
{
	try
	{
		run();
	}
	catch (std::invalid_argument& exc)
	{
		std::cout << "Invalid command" << std::endl;
	}
	catch (std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Invalid argument given" << std::endl;
	}

	return 0;
}