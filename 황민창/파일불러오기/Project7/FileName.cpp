#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filepath;
   ifstream file("C:\\Users\\hwmic\\source\\repos\\Project8\\Project8\\hwmich030520"); // �ؽ�Ʈ ���� ����

    if (!file) { // ������ ���������� ���ȴ��� Ȯ��
        cout << "���� �� �� ����";
        return 1;
    }
    char str[50];
    char i ;

    file >> str >> i;
    cout << str << i << endl;
    file.close();
    return 0;
}