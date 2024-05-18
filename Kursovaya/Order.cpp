#include"order.h"

int checkInterval(int min, int max)
{
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	int value;
	value = inputInt();
	while (value < min || value > max)
	{
		string str = "����� ������ ���� �� ";
		str += to_string(min);
		str += " �� ";
		str += to_string(max);
		str += ": ";
		cout << str;
		value = inputInt();
	}
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	return value;
}


int inputInt() {
	string str;
	while (true) {
		cin >> str;

		string::iterator it = str.begin();
		while (it != str.end())
		{
			if (*it < '0' || *it > '9') {
				cout << "������. ������� ����� ������������� �����!" << endl;
				break;
			}
			it++;

		}
		if (str.size() > 9) {
			cout << "����� �� ����� ���� ������� 9 ��������. ��������� ����" << endl;
			continue;
		}
		if (it == str.end())
			return stoi(str);
	}
}

string enterString() {
	string str;
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, str);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	return str;
}

Order doOrder(vector<Service> services,string login) {
		Order order;
		Date date;
		date = getCurrentDate();
		system("cls");
		order.login = login;
		cout << "������� ���� ���: ";
		order.nameConsumer = enterString();
		cout << endl;
		cout << "������� ��� ����� ��������: ";
		order.numberOfPhone = enterString();
		cout << endl;
		cout << "������� ���� � �����: ";
		order.Date = enterDate();
		order.Time = enterTime(date);
		cout << endl;
		cout << "������� ����� ";
		order.address = enterString();
		cout << endl;
		while (true) {
			cout << "�������� ������";
			order.Services.push_back(services.at(choiseService(services) - 1));
			cout << "1.������� ��� ���� ������\n"
				<< "2.��������� ���������� ������\n";
			int choise = 0;
			choise = checkInterval(1, 2);
			if (choise == 2) {
				break;
			}
		}
		return order;
	
}

void createService(vector<Service>& services) {
	Service service;
	cout << "������� �������� ������: ";
	service.name = enterString();
	cout << "������� ���� ���� ������: ";
	service.price = checkInterval(10,500);
	services.push_back(service);
	writeDataToFile(services);
}

void changeService(vector<Service>& services) {
	system("cls");
	if (services.size() != 0) {
		displayServices(services);
		cout << "������� ����� ������" << endl;
		int i = checkInterval(1, services.size());
		Service service;
		cout << "������� �������� ������: ";
		service.name = enterString();
		cout << endl;
		cout << "������� ���� ������: ";
		service.price = checkInterval(10, 500);
		services.at(i - 1) = service;
		writeDataToFile(services);
		system("pause");
		return;
	}
	else {
		cout << "������ ����� ����" << endl;
		system("pause");
		return;
	}
}


void deleteOrder(vector<Order>& orders) {
	if (orders.size() != 0) {
		system("cls");
		displayOrders(orders);
		cout << "������� ����� ������ ��� ��������: ";
		int i = checkInterval(1, orders.size());
		orders.erase(orders.begin() + i - 1);
		writeDataToFile(orders);
		cout << "\n����� ������� �����";
		system("pause");
	}
	else {
		system("cls");
		cout << "������ ������� ����"<<endl;
		system("pause");
	}
}

	void displayOrders( vector<Order> orders) {
		if (orders.size() != 0) {

			system("cls");
			std::cout << "================================================================================================================================"
				<< "\n|                                                  ������                                                                     |"
				<< "\n=============================================================================================================================="
				<< "\n|  �  |   ��� ���������   |        ����       |       �����       |   ����� ��������  | ���������� ������ |     ����� ����    |"
				<< "\n|=====|===================|===================|===================|===================|===================|===================|";

			for (size_t i = 0; i < orders.size(); ++i) {
				string time = to_string(orders.at(i).Date.year) + "." + to_string(orders.at(i).Date.month) + "." + to_string(orders.at(i).Date.day) + " : " + to_string(orders.at(i).Time.hour) + "." + to_string(orders.at(i).Time.minute);
				Order& order = orders.at(i);
				std::cout << "\n| " << std::setw(4) << std::left << (i + 1)
					<< "| " << std::setw(18) << std::left << order.nameConsumer
					<< "| " << std::setw(18) << std::left << time
					<< "| " << std::setw(18) << std::left << order.address
					<< "| " << std::setw(18) << std::left << order.numberOfPhone;

				for (const Service& service : order.Services) {
					std::cout << "| " << std::setw(18) << std::left << service.name;
				}
				cout << "| " << std::setw(18) << std::left << order.finalCost();
				cout << "|";
			}

			std::cout << "\n|-=-=-|-=-=-=-=-=-=-=-=-=-|=-=-=-=-=-=-=-=-=-=|-=-=-=-=-=-=-=-=-=-=|-=-=-=-=-=-=-=-=-=|=-=-=-=-=-=-=-=-=-=|-=-=-=-=-=-=-=-=-=-|\n";
			system("pause");
		}
		else {
			system("cls");
			cout << "������ ������� ����"<<endl;
			system("pause");
		}
	}

void displayOrder(const vector<Order> orders,string login) {
	system("cls");
	Order currentOrder;
	bool flag = false;
	for (int i = 0; i < orders.size(); i++) {
		if (orders.at(i).login == login) {
			currentOrder = orders.at(i);
			flag = true;
			cout << "���� ���: " << currentOrder.nameConsumer<<endl;
			cout << "��� ����� ��������: " << currentOrder.numberOfPhone << endl;
			cout << "��� �����: " << currentOrder.address<<endl;
			cout << "�����, �� ������� ���������� ������: " << currentOrder.Date.year << "." << currentOrder.Date.month << "." << currentOrder.Date.day << " : " << currentOrder.Time.hour << ":" << currentOrder.Time.minute << endl;
			cout << "���������� ������: " << endl;
			for (int j = 0; j < currentOrder.Services.size(); j++) {
				cout << currentOrder.Services.at(j).name << " " << currentOrder.Services.at(j).price << endl;
			}
			cout << endl << "------------------------------" << endl;
		}
	}
	if (flag == false) {
		cout << "�� ��� �� ������ �����!";
	}
	system("pause");
}

void changeOrder(vector<Order>& orders,vector<Service>services,string login) {
	system("cls");
	if (orders.size() != 0) {
		displayOrders(orders);
		cout << "������� ����� ������";
		int i = checkInterval(1, orders.size());
		Order order=doOrder(services,login);
		orders.at(i-1) = order;
		writeDataToFile(orders);
		return;
	}
	else {
		cout << "������ ������� ����" << endl;
		system("pause");
		return;
	}

}

void displayServices(vector<Service> services)
{
	cout << "================================================"
		<< "\n|                  ������                     |"
		<< "\n=============================================="
		<< "\n|  �  |      ��������     |       ����        |"
		<< "\n|=====|===================|===================|";
	for (int i = 0; i < services.size(); i++) {
		cout << "\n| " << setw(4) << left << (i + 1)
			<< "| " << setw(18) << left << services.at(i).name
			<< "| " << setw(18) << left << services.at(i).price;
		cout << "\n|-=-=-|-=-=-=-=-=-=-=-=-=-|=-=-=-=-=-=-=-=-=-=|-=-=-=-=-=-=-=-=-=-=-|";

	}
	cout << endl;
}

void readDataFromFile(vector<Order>& orders) {
	ifstream inputFile("Orders.txt");

	if (!inputFile.is_open()) {
		cout << "������ �������� ����� Orders.txt" << endl;
		return;
	}

	Order currentOrder;
	Service currentService;

	string line;
	while (getline(inputFile, line)) {
		if (line.find("Concumer name: ") != string::npos) {
			if (!currentOrder.nameConsumer.empty()) {
				orders.push_back(currentOrder);
				currentOrder = Order();
			}
			currentOrder.nameConsumer = line.substr(15);
		}
		else if (line.find("Login: ") != string::npos) {
			currentOrder.login = line.substr(7);
		}
		else if (line.find("Year: ") != string::npos) {
			currentOrder.Date.year = stoi(line.substr(6));
		}
		else if (line.find("Month: ") != string::npos) {
			currentOrder.Date.month = stoi(line.substr(7));
		}
		else if (line.find("Day: ") != string::npos) {
			currentOrder.Date.day = stoi(line.substr(5));
		}
		else if (line.find("Hour: ") != string::npos) {
			currentOrder.Time.hour = stoi(line.substr(6));
		}
		else if (line.find("Minute: ") != string::npos) {
			currentOrder.Time.minute = stoi(line.substr(8));
		}
		else if (line.find("Phone number: ") != string::npos) {
			currentOrder.numberOfPhone = line.substr(14);
		}
		else if(line.find("Address: ") != string::npos){
			currentOrder.address = line.substr(9);
		}
		else if (line.find("Service name: ") != string::npos) {
			currentService.name = line.substr(14);
		}
		else if(line.find("Price: ") != string::npos) {
			currentService.price = stoi(line.substr(7));
		}
		else if (line.find("------------------------") != string::npos) {
			currentOrder.Services.push_back(currentService);
		}
		else if (line.find("========================") != string::npos) {
			orders.push_back(currentOrder);
			currentOrder = Order();
			currentService = Service();
		}
	}
	inputFile.close();
}

void writeDataToFile(const vector<Order>& orders) {
	ofstream outputFile("Orders.txt", ios::out);


	if (!outputFile.is_open()) {
		cout << "������ �������� ����� Orders.txt" << endl;
		return;
	}

	for (const auto& order : orders) {
		outputFile << "Concumer name: " << order.nameConsumer << endl;
		outputFile << "Login: " << order.login << endl;
		outputFile << "Year: " << order.Date.year << endl;
		outputFile << "Month: " << order.Date.month << endl;
		outputFile << "Day: " << order.Date.day << endl;
		outputFile << "Hour: " << order.Time.hour << endl;
		outputFile << "Minute: " << order.Time.minute << endl;
		outputFile << "Phone number: " << order.numberOfPhone << endl;
		outputFile << "Address: " << order.address << endl;

		for (const auto& service : order.Services) {
			outputFile << "Service name: " << service.name << endl;
			outputFile << "Price: " << service.price << endl;
			outputFile << "------------------------" << endl;

		}
		outputFile << "========================" << endl;

	}
	outputFile.close();
}

void writeDataToFile(const vector<Service>& services) {
	ofstream outputFile("Services.txt", ios::out);

	if (!outputFile.is_open()) {
		cout << "������ �������� ����� Orders.txt" << endl;
		return;
	}

	for (const auto& service : services) {
		outputFile << "Service name: " << service.name << endl;
		outputFile << "Service price: " << service.price << endl;
		outputFile << "========================" << endl;

	}
	outputFile.close();
}

void readDataFromFile(vector<Service>& services) {
	ifstream inputFile("Services.txt");

	if (!inputFile.is_open()) {
		cout << "������ �������� ����� Services.txt" << endl;
		return;
	}

	Service currentService;

	string line;
	while (getline(inputFile, line)) {
		if (line.find("Service name: ") != string::npos) {
			if (!currentService.name.empty()) {
				services.push_back(currentService);
				currentService = Service();
			}
			currentService.name = line.substr(14);
		}
		else if (line.find("Service price: ") != string::npos) {
			currentService.price = stoi(line.substr(15));
		}
		else if (line.find("========================") != string::npos) {
			services.push_back(currentService);
			currentService = Service();

		}
	}
	inputFile.close();
}


int choiseService(const vector<Service>services) {
	system("cls");
	displayServices(services);
	cout << "�������� ����� ������: ";
	return checkInterval(1, services.size());
}


void deleteService(vector<Service>& services) {
	system("cls");
	displayServices(services);
	if (services.size() == 0) {
		cout << "������ ����� ����" << endl;
	}
	else {
		int i = choiseService(services);
		services.erase(services.begin() + i - 1);
		writeDataToFile(services);
		cout << "\n������ ������� �������";
	}
	system("pause");
}



bool sortServiceByPriceComp(const Service RHS, const Service LHS) {
	return RHS.price > LHS.price;
}

void  sortServiceByPrice(vector<Service> services) {
	system("cls");
	sort(services.begin(), services.end(), sortServiceByPriceComp);
	cout << "���������������� ������ �� ����" << endl;
	displayServices(services);
	system("pause");
	return;
}

bool sortOrderByConsNameComp(const Order RHS, const Order LHS) {
	return RHS.nameConsumer < LHS.nameConsumer;
}

void sortOrderByConsName(vector<Order> orders) {
	system("cls");
	sort(orders.begin(), orders.end(), sortOrderByConsNameComp);
	cout << "���������������� ������ �� �������� �� ������ ����������" << endl;
	displayOrders(orders);
	system("pause");
	return;
}

bool sortOrderByAdrressComp(const Order RHS, const Order LHS) {
	return RHS.address > LHS.address;
}

void  sortOrderByAdrress(vector<Order> orders) {
	system("cls");
	sort(orders.begin(), orders.end(), sortOrderByAdrressComp);
	cout << "���������������� ������ �� �������� �� ������" << endl;
	displayOrders(orders);
	system("pause");
	return;
}

bool sortOrderBySizeComp(const Order RHS, const Order LHS) {
	return RHS.Services.size() > LHS.Services.size();
}

void  sortOrderBySize(vector<Order> orders) {
	system("cls");
	sort(orders.begin(), orders.end(), sortOrderBySizeComp);
	cout << "���������������� ������ �� ���-�� �����" << endl;
	displayOrders(orders);
	system("pause");
	return;
}

