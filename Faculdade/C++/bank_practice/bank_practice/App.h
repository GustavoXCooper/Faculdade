#ifndef APP_H
#define APP_H
#include "Employee.h"
#include "Client.h"
#include <vector>

class App {
public:
	App();
	void loginAsEmployee();
	void loginAsClient();
	void runEmployee(Employee employee);
	void runClient(Client client);
	void mainMenu();
private:
	std::vector<Employee> employees;
	std::vector<Client> clients;
};

#endif