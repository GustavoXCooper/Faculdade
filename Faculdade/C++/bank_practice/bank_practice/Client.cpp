#include "Client.h"

Client::Client(
	std::string name,
	std::string surname,
	std::string login,
	std::string password,
	std::string email,
	double onAccount,
	bool vipClient) : User(name, surname, login, password, email) {
	this->onAccount = onAccount;
	this->vipClient = vipClient;
}

double Client::getOnAccount() { return onAccount; }
void Client::withdraw(double value){

	if (onAccount > value && value > 0) {
		onAccount -= value;
		std::cout << "\nVocê retirou " << value << " reais.";
		std::cout << "\nValor atual da conta: " << onAccount << " reais.";
	}
	else if (onAccount< value && value > 0){
		std::cout << "\nValor superior ao saldo na sua conta.";
	} else {
		std::cout << "\nValor inválido.";
	}

}
void Client::deposit(double value) {
	if (value > 0) {
		onAccount += value;
		std::cout << "\nValor atual da conta: " << onAccount << " reais.";
	}
	else {
		std::cout << "\nValor inválido.";
	}
}
void Client::setVip(bool value) {
	if (!vipClient && onAccount < 10000) {
		std::cout << "\nSaldo insuficiente para ser um cliente VIP.";
	} else {
		std::cout << name << "é oficialmente um cliente VIP.";
		vipClient = value;
	}
}
bool Client::getVip() {
	return vipClient;
}
