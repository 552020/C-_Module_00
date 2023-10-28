#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

  public:
	Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") {}
	Contact(const std::string &firstName, const std::string &lastName, const std::string &nickname,
			const std::string &phoneNumber, const std::string &darkestSecret)
		: _firstName(firstName), _lastName(lastName), _nickname(nickname), _phoneNumber(phoneNumber),
		  _darkestSecret(darkestSecret)
	{
		std::cout << "Contact created!" << std::endl;
	}
	~Contact();

	// Getters
	std::string getFirstName() const; // For the meaning of const see Notes.
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif

// Notes:

// The const at the end of a member function in a class declaration signifies
// that the member function is a constant member function. When a member
// function is declared as const, it means that the function does not modify any
// non-static data members of the object for which it is called. Additionally,
// within the scope of a const member function, the this pointer (which points
// to the object on which the member function was invoked) is treated as a
// pointer to a const object, so you can't call any non-const member functions
// on it. This means that all "member function" or "method' which are "getters;
// will be const.

// If the function which is marked as 'const' will modify the class member,
// which it is a function of we will get a compile-time error
