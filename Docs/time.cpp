#include <ctime>
#include <iomanip>
#include <iostream>

int main()
{
	std::time_t specificTime = 694224932;
	std::cout << "Specific Time: " << specificTime << std::endl;
	std::time_t currentTime = std::time(nullptr);
	std::cout << "Current Time: " << currentTime << std::endl;

	std::tm *localCurrentTime = std::localtime(&currentTime);
	std::cout << "Specific Time: " << specificTime << std::endl;
	std::cout << "Current Time: " << currentTime << std::endl;
	std::cout << "Local Current Time: " << localCurrentTime << std::endl;
	std::tm *localSpecificTime = std::localtime(&specificTime);
	std::cout << "Specific Time: " << specificTime << std::endl;
	std::cout << "Current Time: " << currentTime << std::endl;
	std::cout << "Local Specific Time: " << localSpecificTime << std::endl;

	std::cout << "Current Time: " << localCurrentTime->tm_year + 1900 << localCurrentTime->tm_mon + 1
			  << localCurrentTime->tm_mday << "_" << localCurrentTime->tm_hour << localCurrentTime->tm_min
			  << localCurrentTime->tm_sec << std::endl;

	std::cout << "Specific Time: " << localSpecificTime->tm_year + 1900 << localSpecificTime->tm_mon + 1
			  << localSpecificTime->tm_mday << "_" << localSpecificTime->tm_hour << localSpecificTime->tm_min
			  << localSpecificTime->tm_sec << std::endl;

	std::cout << "Current Time (Formatted): [" << std::setfill('0') << std::setw(4) << localCurrentTime->tm_year + 1900
			  << std::setw(2) << localCurrentTime->tm_mon + 1 << std::setw(2) << localCurrentTime->tm_mday << "_"
			  << std::setw(2) << localCurrentTime->tm_hour << std::setw(2) << localCurrentTime->tm_min << std::setw(2)
			  << localCurrentTime->tm_sec << "]" << std::endl;

	std::cout << "Specific Time (Formatted): [" << std::setfill('0') << std::setw(4)
			  << localSpecificTime->tm_year + 1900 << std::setw(2) << localSpecificTime->tm_mon + 1 << std::setw(2)
			  << localSpecificTime->tm_mday << "_" << std::setw(2) << localSpecificTime->tm_hour << std::setw(2)
			  << localSpecificTime->tm_min << std::setw(2) << localSpecificTime->tm_sec << "]" << std::endl;

	return 0;
}
