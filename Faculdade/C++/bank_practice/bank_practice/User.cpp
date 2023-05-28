#include "User.h"


User::User(std::string name, std::string surname, std::string login, std::string password, std::string email) {
	this->name = name;
	this->surname = surname;
	this->login = login;
	this->password = password;
	this->email = email;
	this->fullName = name + " " + surname;

}

std::string User::getName() { return this->name;}
void User::setName(std::string value){ 
	name = value;
	fullName = name + " " + surname;
}

std::string User::getSurname(){ return surname;}
void User::setSurname(std::string value) { 
	surname = surname; 
	fullName = name + " " + surname;
}

std::string User::getFullName() { return fullName; }

std::string User::getLogin(){ return login; }
void User::setLogin(std::string value) { login = value; } 
 
std::string User::getPassword(){ return password; }
void User::setPassword(std::string value) { password = value; } 

std::string User::getEmail(){ return email; }
void User::setEmail(std::string value) { email = value; }
