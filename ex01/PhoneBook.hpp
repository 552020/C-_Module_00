#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _currentContacts;
	std::string truncateEntry(const std::string &str) const;

  public:
	PhoneBook();
	PhoneBook(bool fillWithTestData);
	~PhoneBook();

	void addContact(const Contact &contact);
	void displayContacts() const;
	void displayContactDetails(int index) const;
	int getCurrentContacts() const;
};

#endif
