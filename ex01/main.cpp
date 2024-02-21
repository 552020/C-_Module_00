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

std::string getInput(const std::string fieldName)
{

	std::string input;
	while (true)
	{
		std::cout << "Enter the " << fieldName << " : ";
		std::getline(std::cin, input);
		input = trim(input);
		if (input.empty())
		{
			std::cout << fieldName << " not provided! Using default value: N/A" << std::endl;
			return "N/A";
		}
		if (fieldName == "phone number")
		{
			bool allDigits = true;
			for (size_t i = 0; i < input.length(); ++i) {
    		if (!isdigit(input[i])) {
        		allDigits = false;
        		break;
    		}
			}
			if (!allDigits)
			//if (!std::all_of(input.begin(), input.end(), ::isdigit))
			{
				std::cout << "Invalid phone number! Phone numbers should contain only digits." << std::endl;
				continue;
			}
		}
		else if (fieldName == "first name" || fieldName == "last name" || fieldName == "nickname")
		{
			if (std::any_of(input.begin(), input.end(), ::isdigit))
			{
				std::cout << "Invalid " << fieldName << "! " << fieldName
						  << " should not continaes numbers! Please enter a valid" << fieldName << "!" << std::endl;
				continue;
			}
		}
		return input;
	}
}

int promptForIndex(int numberOfContacts, const std::string promptMessage)
{
	while (true)
	{
		std::cout << promptMessage;
		std::string input;
		std::getline(std::cin, input);

		if (input == "q")
			return -1;
		try
		{
			int index = std::stoi(input);
			if (index < 1 || index > numberOfContacts)
			{
				std::cout << "Invalid index! Please enter a number between 1 and " << numberOfContacts
						  << " or press q to exit!" << std::endl;
				continue;
			}
			return index;
		}
		catch (const std::invalid_argument &e)
		{
			std::cout << "Invalid input! Please enter a number between 1 and " << numberOfContacts << "." << std::endl;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << "Invalid input! Please enter a number between 1 and " << numberOfContacts << "." << std::endl;
		}
	}
}

int main()
{
	PhoneBook phonebook;
	// PhoneBook phonebook(true);
	std::string command;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
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
		}

		else if (command == "SEARCH")
		{
			int numberOfContacts = phonebook.getCurrentContacts();

			if (numberOfContacts == 0)
				std::cout << "The PhoneBook is empty!" << std::endl;
			else
			{
				phonebook.displayContacts();
				std::string promptMessage = "Enter the index of the contact to see all details: ";
				if (numberOfContacts == 1)
					promptMessage += "There is only 1 contact! Enter 1";
				else if (numberOfContacts == 2)
					promptMessage += "1, 2";
				else
				{
					promptMessage += "1-" + std::to_string(numberOfContacts);
				}
				promptMessage += " or q to return to main menu : ";
				int index = promptForIndex(numberOfContacts, promptMessage);
				if (index == -1)
					continue;
				phonebook.displayContactDetails(index);
			}
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command!" << std::endl;
	}
}