#include <iostream>
#include <string>
#include <map>

using namespace std;

struct User {
	string name;
	string phoneNumber;
	string Security;
	string id;
	string password;
};

map<string, User> users; // ȸ�� ������ ������ ��

void Register() {
	string name, phoneNumber, Security, id, password;

	cout << "�̸�: ";
	getline(cin >> ws, name);

	cout << "��ȭ��ȣ: ";
	getline(cin >> ws, phoneNumber);

	cout << "�ֹι�ȣ ���ڸ� 7�ڸ�: ";
	cin >> Security;

	cout << "���ο� ���̵�: ";
	cin >> id;

	cout << "���ο� ��й�ȣ: ";
	cin >> password;

	User newUser = { name, phoneNumber,Security, id, password };
	// �ֹι�ȣ�� Ű�� �Ͽ� ȸ�� ���� ����
	users[id] = newUser;

	cout << "ȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
}

void Login() {
	string idInput, passwordInput;

	cout << "���̵�:";
	cin >> idInput;

	cout << "��й�ȣ:";
	cin >> passwordInput;


	for (auto& user : users) {
		if (user.second.id == idInput && user.second.password == passwordInput) {
			cout << user.second.name << "������ �α��εǾ����ϴ�." << endl;
			return;
		}
	}

	cout << "��ġ�ϴ� ȸ�� ������ �����ϴ�." << endl;
}

void FindID() {
	string nameInp, numberInp, SecurityInp;

	cout << "�̸�:";
	getline(cin >> ws, nameInp);

	cout << "��ȭ��ȣ:";
	getline(cin >> ws, numberInp);

	cout << "�ֹε�� ��ȣ ���ڸ� 7�ڸ�:";
	getline(cin >> ws, SecurityInp);


	for (auto& user : users) {
		if (user.second.Security == SecurityInp && user.second.phoneNumber == numberInp && user.second.name == nameInp) {
			cout << "����� ���̵�� " << user.second.id << endl;
			return;
		}
	}

	cout << "��ġ�ϴ� ����ڸ� ã�� ���߽��ϴ�." << endl;


}


void FindPassword() {
	string namefn, numberfn, Securityfn;

	cout << "�̸�:";
	getline(cin >> ws, namefn);

	cout << "��ȭ��ȣ:";
	getline(cin >> ws, numberfn);

	cout << "�ֹε�� ��ȣ ���ڸ� 7�ڸ�:";
	getline(cin >> ws, Securityfn);


	for (auto& user : users) {
		if (user.second.Security == Securityfn && user.second.phoneNumber == numberfn && user.second.name == namefn) {
			cout << "����� �н������ " << user.second.password << endl;
			return;
		}
	}

	cout << "��ġ�ϴ� ����ڸ� ã�� ���߽��ϴ�." << endl;

	}

int main() {
	int choice;

	while (true) {
		cout << "\n[1] ȸ�� ���� [2] �α��� [3] ���̵� ã�� [4] ��й�ȣ ã�� [5] ����" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cin.ignore();
			Register();
			break;

		case 2:
			Login();
			break;

		case 3:
			cin.ignore();
			FindID();
			break;

		case 4:
			cin.ignore();
			FindPassword();
			break;

		case 5:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;

		default:
			cout << "�߸��� �����Դϴ�. �ٽ� �������ּ���." << endl;
			break;
		}

		// ���� ����
		cin.clear();

	}

	return 0;
}