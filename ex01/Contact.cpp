#include "Contact.hpp"

// Default constructor is already defined in Contact.hpp, so no need to redefine it here.

// Define the destructor (if needed)
Contact::~Contact()
{
	// Any cleanup code if required
}

// Define getter functions
std::string Contact::getFirstName() const { return _firstName; }

std::string Contact::getLastName() const { return _lastName; }

std::string Contact::getNickname() const { return _nickname; }

std::string Contact::getPhoneNumber() const { return _phoneNumber; }

std::string Contact::getDarkestSecret() const { return _darkestSecret; }
