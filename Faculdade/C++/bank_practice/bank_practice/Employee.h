#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "User.h"
#include "Client.h"

class Employee : public User {
public: 
	Employee(
		std::string name,
		std::string surname,
		std::string login,
		std::string password,
		std::string email,
		bool isManager
	);
	void getClientInfo(Client &client);
	void showInfo(Client client);
	//void setIsManager(bool value);
	bool getIsManager();
private: 
	bool isManager;
};


#endif