#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _currentContacts;

	public:
		PhoneBook();
		~PhoneBook();

		void addContact(const Contact &contact);
		void displayContacts() const;
		void displayContactDetails(int index) const;
};

#endif

