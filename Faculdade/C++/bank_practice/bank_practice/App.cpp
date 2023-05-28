#include "App.h"
#include <windows.h>

App::App() {
	Employee employee("Gustavo", "Teste", "gustavo", "123", "gusxavier@gmail.com", false);
	this->employees.push_back(employee); 

	Employee employee1("Sofia", "Teste", "sofi", "123", "sofi@gmail.com", true);
	this->employees.push_back(employee1);

	Client client1("Henrique", "Teste", "ikki", "1234", "ikki@gmail.com", 1000, false);
	this->clients.push_back(client1);

	Client client2("Leandro", "Teste", "leandro", "12", "leandro@gmail.com", 10000, true);
	this->clients.push_back(client2); 

	Client client3("Raquel", "Teste", "raquela", "122", "raquela@gmail.com", 10, false);
	this->clients.push_back(client3);
}

void App::loginAsEmployee() {
	std::string loginAttempt; 
	std::string passwordAttempt;
	bool loggedIn = false;
	system("cls");
	std::cout << "Login: ";
	std::cin >> loginAttempt;
	std::cout << "Senha: ";
	std::cin >> passwordAttempt;

		for (int i = 0; i < employees.size(); i++) {
			if (employees[i].getLogin() == loginAttempt && employees[i].getPassword() == passwordAttempt) {
				loggedIn = true;
				system("cls");
				runEmployee(employees[i]);
			}
		}
		if(!loggedIn) {
			system("cls");
			std::cout << "Senha ou login incorretos. Tente novamente.";
			Sleep(5000);
		}

}
void App::runEmployee(Employee employee) {
	int choice;
	bool running = true;
	while (running) {
		std::cout << "Você deseja:\n1.Acessar uma conta de um cliente\n2.Sair\n";
		std::cin >> choice;
		if (choice == 1) {
			std::cout << "Você deseja acessar a conta de qual usuário?\n";
			for (int i = 0; i < clients.size(); i++) {
				std::cout << (i+1) << ". " << clients[i].getName() << std::endl;
			}
			std::cin >> choice;
			if (choice <= clients.size()) {
				choice--;
				employee.getClientInfo(clients[choice]);
				Sleep(5000);
			}
			else {
				system("cls");
				std::cout << "Valor inválido. Tente Novamente.";
				Sleep(5000);
			}
			
		}
		else if (choice == 2) {
			system("cls");
			running = false;
		}
		else {
			system("cls");
			std::cout << "Valor inválido.";
			Sleep(5000);
		}
		system("cls");
	}
}

void App::runClient(Client client) {
	int choice;
	bool running = true;

	while (running) {
		std::cout << "Você deseja:\n1.Consultar seu saldo.\n2.Fazer um depósito.\n3.Retirar uma quantia.\n4.Sair\n";
		std::cin >> choice; 
		if (choice == 1) { 
			std::cout << "\nO seu saldo é de " << client.getOnAccount() << " reais.";
			Sleep(5000);
		}
		else if (choice == 2) {
			double value;
			std::cout << "Qual o valor do depósito que deseja fazer?\n";
			std::cin >> value;
			client.deposit(value);
			Sleep(5000);
		}
		else if (choice == 3) {
			double value;
			std::cout << "Qual o valor da retirada que deseja fazer?\n";
			std::cin >> value;
			client.withdraw(value);
			Sleep(5000);
		}
		else if (choice == 4){
			system("cls");
			std::cout << "Obrigado, " << client.getName() << "! Até a próxima ;)\n";
			Sleep(5000);
			running = false;
		}
		else {
			std::cout << "\nValor inválido.\n";
			Sleep(5000);
		}
		system("cls");
	}
}
void App::loginAsClient() {
	std::string loginAttempt;
	std::string passwordAttempt;
	bool loggedIn = false;
	system("cls");
	std::cout << "Login: ";
	std::cin >> loginAttempt;
	std::cout << "Senha: ";
	std::cin >> passwordAttempt;

	for (int i = 0; i < clients.size(); i++) {
		if (clients[i].getLogin() == loginAttempt && clients[i].getPassword() == passwordAttempt) {
			loggedIn = true;
			system("cls");
			runClient(clients[i]);
		}
	}
	if (!loggedIn) {
		system("cls");
		std::cout << "Senha ou login incorretos. Tente novamente.";
		Sleep(5000);
	}
}

void App::mainMenu() {
	int choice;
	std::string loginAttempt;
	std::string passwordAttempt;

	bool running = true;
	while (running) {
		std::cout << "Você deseja:\n1.Logar em uma conta existente.\n2.Criar uma nova conta.\n3.Sair.\n";
		std::cin >> choice; 
		if (choice == 1) {
			system("cls");
			std::cout << "Você deseja logar como:\n1.Usuário.\n2.Funcionário.\n";
			std::cin >> choice;
			switch (choice){
			case 1:
				loginAsClient();
				break;
			case 2: 
				loginAsEmployee();
				break;
			default:
				system("cls");
				std::cout << "Valor inválido. Tente novamente.";
				Sleep(5000);
				break;
			}
		} else if (choice == 2) {
			std::string firstName;
			std::cout << "\nInsira seu primeiro nome: ";
			std::cin >> firstName;

			std::string surname;
			std::cout << "\nInsira seu sobrenome: ";
			std::cin >> surname;

			std::string login;
			std::cout << "\nInsira seu login: ";
			std::cin >> login;

			std::string password;
			std::cout << "\nInsira sua senha: ";
			std::cin >> password;

			std::string email;
			std::cout << "\nInsira seu email: ";
			std::cin >> email;

			Client client(firstName, surname, login, password, email, 0, false);
			clients.push_back(client);
		}
		else if (choice == 3) {
			system("cls");
			std::cout << "Encerrando o programa.";
			Sleep(5000);
			running = false;
		} else {
			system("cls");
			std::cout << "Valor inválido. Tente novamente.";
			Sleep(5000);
		}
		system("cls");
	}
	
}