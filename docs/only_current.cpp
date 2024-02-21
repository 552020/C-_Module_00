#include <iostream>
#include <iomanip>
#include <ctime>

int main()
{
	// Obtain the current time
	std::time_t currentTime = std::time(nullptr);

	// Convert to local time
	std::tm *localCurrentTime = std::localtime(&currentTime);

	// Display the current date and time with zero-padding
	std::cout << "Current Time (Formatted): [" << std::setfill('0') << std::setw(4) << localCurrentTime->tm_year + 1900
			  << std::setw(2) << localCurrentTime->tm_mon + 1 << std::setw(2) << localCurrentTime->tm_mday << "_"
			  << std::setw(2) << localCurrentTime->tm_hour << std::setw(2) << localCurrentTime->tm_min << std::setw(2)
			  << localCurrentTime->tm_sec << "]" << std::endl;

	return 0;
}
