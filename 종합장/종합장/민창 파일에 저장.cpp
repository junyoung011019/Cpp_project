//////////////////////////// �Է�////////////////////////////
#include<iostream>
#include <fstream>
#include <string>
using namespace std; 
int main() {
	string line;
	ifstream file("example. txt");
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "unable to open file";
		return 1;
	}
	return 0;
}
////////////////////////////���////////////////////////////
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char x;
	cout << "���ϸ��� �Է��ϼ���";
	cin >> x;
	string line;
	ofstream file(x);
	if (!file) {
		cout << "���� �� �� ����";
		return 1;
	}
	file << "whangmin\n";
	file.close();
	return 0;
}