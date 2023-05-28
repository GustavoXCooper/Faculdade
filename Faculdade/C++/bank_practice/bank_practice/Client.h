#ifndef CLIENT_H
#define CLIENT_H
#include "User.h"

class Client : public User {
public:
	Client(
		std::string name,
		std::string surname,
		std::string login,
		std::string password,
		std::string email,
		double onAccount, 
		bool vipClient
	);
	void withdraw(double value);
	void deposit(double value);
	void setVip(bool value);
	bool getVip();
	double getOnAccount();

private:
	double onAccount;
	bool vipClient;
};


#endif
