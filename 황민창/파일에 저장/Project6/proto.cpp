#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char x;
	cout << "���ϸ��� �Է��ϼ���";
	cin >> x;
	string line;
	ofstream file(x);
	if(!file){
		cout << "���� �� �� ����";
		return 1;
	}
	file << "whangmin\n";
	file.close();
	return 0;
}