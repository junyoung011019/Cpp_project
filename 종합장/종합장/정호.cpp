#include <iostream>
#include <string>
#include <vector>

// ����� ������ ������ ����ü
struct UserInfo {
    std::string juminNumber;
    std::string name;
    int age;
};

// ����� ������ ������ ����
std::vector<UserInfo> userDatabase;

int main() {
    // ����� ���� �Է�
    UserInfo user;
    std::cout << "�ֹε�Ϲ�ȣ: ";
    std::cin >> user.juminNumber;
    std::cout << "�̸�: ";
    std::cin >> user.name;
    std::cout << "����: ";
    std::cin >> user.age;

    // ����� ������ �����ͺ��̽��� �߰�
    userDatabase.push_back(user);

    // ����� ���� ���
    std::cout << "�ֹε�Ϲ�ȣ: " << userDatabase[0].juminNumber << std::endl;
    std::cout << "�̸�: " << userDatabase[0].name << std::endl;
    std::cout << "����: " << userDatabase[0].age << std::endl;

    return 0;
}