#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : currentContacts(0), oldestContactIndex(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact &contact)
{
    _contacts[_currentContacts % 8] = contact;
    _currentContacts++;
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "Index"
              << "|";
    std::cout << std::setw(10) << "First name"
              << "|";
    std::cout << std::setw(10) << "Last name"
              << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < _currenctContacts && i < 8; i++)
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