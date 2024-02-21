#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

const std::string testFirstNames[8] = {"Alice", "Bob", "Charlie", "Dana", "Evan", "Fiona", "George", "Hannah"};
const std::string testLastNames[8] = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson"};
const std::string testNicknames[8] = {"Ally", "Bobby", "Chuck", "Dane", "Evie", "Fee", "Georgie", "Hannie"};
const std::string darkestSecrets[8] = {"Believes the earth is flat",
									   "Can't ride a bike",
									   "Afraid of ducks",
									   "Secretly a vampire",
									   "Still uses a flip phone",
									   "Talks to plants",
									   "Thinks cereal is soup",
									   "Wanted to be a clown"};
const std::string phoneNumbers[8] = {
	"1234567890", "2345678901", "3456789012", "4567890123", "5678901234", "6789012345", "7890123456", "8901234567"};

PhoneBook::PhoneBook() : _currentContacts(0)
{
}
PhoneBook::PhoneBook(bool fillWithTestData) : _currentContacts(0)
{
	if (fillWithTestData)
	{
		for (int i = 0; i < 8; ++i)
		{
			Contact testContact(
				testFirstNames[i], testLastNames[i], testNicknames[i], phoneNumbers[i], darkestSecrets[i]);
			addContact(testContact);
		}
	}
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(const Contact &contact)
{
	_contacts[_currentContacts % 8] = contact;
	_currentContacts++;
	std::cout << "Contact added!" << std::endl;
}

void PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "index"
			  << "|";
	std::cout << std::setw(10) << "first name"
			  << "|";
	std::cout << std::setw(10) << "last name"
			  << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < _currentContacts && i < 8; i++)
	{
		std::cout << std::setw(10) << (i + 1) << "|";
		std::cout << std::setw(10) << truncateEntry(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncateEntry(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncateEntry(_contacts[i].getNickname()) << std::endl;
	}
}

std::string PhoneBook::truncateEntry(const std::string &str) const
{
	std::string truncatedString = str;
	if (truncatedString.length() > 10)
	{
		truncatedString.resize(9);
		truncatedString.append(".");
	}
	return truncatedString;
}

void PhoneBook::displayContactDetails(int index) const
{
	if (index < 1 || index > _currentContacts || index > 8)
	{
		std::cout << "Invalid index! No contact found for the given index." << std::endl;
		return;
	}

	index--;
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getCurrentContacts() const
{
	return _currentContacts < 8 ? _currentContacts : 8;
}