#include "Employee.h"
#include "windows.h"

Employee::Employee(
	std::string name,
	std::string surname,
	std::string login,
	std::string password,
	std::string email,
	bool isManager) : User (name, surname, login, password, email) {
	this->isManager = isManager;
}


void Employee::showInfo(Client client) {
	std::cout << "\nNome: " << client.getFullName();
	std::cout << "\nEmail: " << client.getEmail();
	std::cout << "\nSaldo: " << client.getOnAccount();
	std::cout << "\nVIP:" ;
	if (!client.getVip()) {
		std::cout << "Não.";
	}
	else {
		std::cout << "Sim.";
	}
}


void Employee::getClientInfo(Client &client){
	int choice;
	std::string newString;
	
	if (isManager) {
		std::cout << "\nVocê deseja:\n1.Acessar os dados de um cliente.\n2.Alterar os dados do cliente.\n";
		std::cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			showInfo(client);
			break;
		case 2:
			system("cls");
			std::cout << "Qual informação deseja alterar?\n1.Nome\n2.Sobrenome\n3.Login\n4.Senha\n5.Email";
			std::cin >> choice;
			switch (choice) {
			case 1:
				std::cout << "Insira o novo nome: ";
				std::cin >> newString;
				client.setName(newString);
				system("cls");
				std::cout << "Novo nome cadastrado.";
				break;
			case 2:
				std::cout << "Insira o novo sobrenome: ";
				std::cin >> newString; 
				client.setSurname(newString); 
				system("cls");
				std::cout << "Novo sobrenome cadastrado.";
				break;
			case 3:
				std::cout << "Insira o novo login: ";
				std::cin >> newString; 
				client.setLogin(newString); 
				system("cls");
				std::cout << "Novo login cadastrado.";
				break;
			case 4:
				std::cout << "Insira o nova senha: ";
				std::cin >> newString;
				client.setPassword(newString); 
				system("cls");
				std::cout << "Nova senha cadastrada.";
				break; 
			case 5:
				std::cout << "Insira o novo email: ";
				std::cin >> newString;
				client.setEmail(newString); 
				system("cls");
				std::cout << "Novo email cadastrado.";
				break;
			default: 
				std::cout << "Valor inválida. Tente novamente."; 
				Sleep(5000);
			}
			break;
		default:
			std::cout << "Valor inválida. Tente novamente."; 
			Sleep(5000);
		}
	}
	else {
		std::cout << "Você deseja:\n1.Acessar os dados do cliente.\n2.Alterar o email do cliente.\n";
		std::cin >> choice;

		switch (choice) {
		case 1:
			showInfo(client);
			break;
		case 2:
			std::cout << "Insira o novo email: ";
			std::cin >> newString;
			client.setEmail(newString);
			break;
		default:
			std::cout << "Ação inválida.";
		}
	}
	
}
// maybe i'll be using this in the future
//void Employee::setIsManager(bool value) { isManager = value; } 
bool Employee::getIsManager() { return isManager; }