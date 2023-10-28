#include <iostream>
#include "PhoneBook.hpp"

std::string trim(const std::string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return "";

	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, (last - first + 1));
}

std::string getInput(const std::string &fieldName)
{
	std::string input;
	std::cout << "Enter the " << fieldName << " : ";
	std::getline(std::cin, input);
	input = trim(input);
	if (input.empty())
	{
		std::cout << fieldName << " not provided! Using dafault value: N/A" << std::endl;
		input = "N/A";
	}
	return input;
}

int promptForIndex(int maxIndex)
{
	int index;
	int maxAttempts = 3;

	do
	{
		std::cout << "Enter the index of the contact you want to see the details of : 1-" << maxIndex
				  << " or q to return to main menu : ";
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::string input;
			std::cin >> input;
			if (input == "q")
				return -1;
		}
		if (std::cin.good())
		{

			if (index < 1 || index > maxIndex)
			{
				std::cout << "Invalid index! Please enter a number between 1 and " << maxIndex << "." << std::endl;
				continue;
			}
		}
		break;
	} while (--maxAttempts > 0);
	// Return -1 or other suitable value to indicate the function exited without a valid index
	return -1;
}

int main()
{
	PhoneBook phonebook;
	std::string command;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT) : ";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			std::string firstName;
			std::string lastName;
			std::string nickname;
			std::string phoneNumber;
			std::string darkestSecret;

			firstName = getInput("first name");
			lastName = getInput("last name");
			nickname = getInput("nickname");
			phoneNumber = getInput("phone number");
			darkestSecret = getInput("darkest secret");

			Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phonebook.addContact(newContact);
			std::cout << "Contact added!" << std::endl;
		}

		else if (command == "SEARCH")
		{
			phonebook.displayContacts();
			int index = promptForIndex(8);
			if (index != -1)
			{
				phonebook.displayContactDetails(index);
			}
			else
			{
				std::cout << "Returning to main menu." << std::endl;
			}
			// std::string indexString;
			// std::cout << "Enter the index of the contact you want to see the details of : ";
			// std::getline(std::cin, indexString);
			// if (indexString.empty())
			// {
			// 	std::cout << "Index not provided! Returning to main menu." << std::endl;
			// 	continue;
			// }
			// int index = std::stoi(indexString);
			// phonebook.displayContactDetails(index);
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command!" << std::endl;
	}
}