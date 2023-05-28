#ifndef USER_H
#define USER_H
#include <iostream>

class User {
public:
	User(std::string name, std::string surname, std::string login, std::string password, std::string email);
	std::string getName();
	void setName(std::string value);
	std::string getSurname();
	void setSurname(std::string value);
	std::string getLogin();
	void setLogin(std::string value);
	std::string getPassword();
	void setPassword(std::string value);
	std::string getEmail();
	void setEmail(std::string value);
	std::string getFullName();   


protected:
	std::string fullName;
	std::string name;
	std::string surname;
	std::string login;
	std::string password;
	std::string email;
};

#endif
