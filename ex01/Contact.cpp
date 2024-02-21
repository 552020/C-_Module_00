#include "Contact.hpp"

Contact::~Contact() {}

std::string Contact::getFirstName() const { return _firstName; }

std::string Contact::getLastName() const { return _lastName; }

std::string Contact::getNickname() const { return _nickname; }

std::string Contact::getPhoneNumber() const { return _phoneNumber; }

std::string Contact::getDarkestSecret() const { return _darkestSecret; }
