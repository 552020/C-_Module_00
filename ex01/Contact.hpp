#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		// The constructor
		Contact();
		// The destructor
		~Contact();

		// Getters
		std::string getFirstName() const; // For the meaning of const see Notes.
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		// Setters
		void setFirstName(const std::string &name);
		void setLastName(const std::string &name);
		void setNickname(const std::string &name);
		void setPhoneNumber(const std::string &number);
		void setDarkestSecret(const std::string &secret);
};

#endif


// Notes:

// The const at the end of a member function in a class declaration signifies that the member function is a constant member function. When a member function is declared as const, it means that the function does not modify any non-static data members of the object for which it is called. Additionally, within the scope of a const member function, the this pointer (which points to the object on which the member function was invoked) is treated as a pointer to a const object, so you can't call any non-const member functions on it.
// This means that all "member function" or "method' which are "getters; will be const. 

// If the function which is marked as 'const' will modify the class member, which it is a function of we will get a compile-time error
