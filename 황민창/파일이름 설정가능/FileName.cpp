#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath;

    std::cout << "���ο� ���� ��ο� �̸��� �Է��ϼ���: ";
    std::getline(std::cin >> std::ws, filePath);

    std::ofstream file(filePath); // ���ο� ���� ����

    if (file.is_open()) { // ������ ���������� ���ȴ��� Ȯ��
        std::string content;
        std::cout << "���Ͽ� ������ ������ �Է��ϼ���. (�����Ϸ��� 'q'�� �Է��ϼ���)" << std::endl;

        while (true) {
            std::getline(std::cin >> std::ws, content); // �� �پ� �о����

            if (content == "q") { // 'q'�� �ԷµǸ� ����
                break;
            }

            file << content << "\n"; // �о�� ������ ���Ͽ� ����
        }

        file.close(); // ���� �ݱ�
        std::cout << "������ ���������� ����Ǿ����ϴ�." << std::endl;
    }
    else {
        std::cout << "������ �� �� �����ϴ�." << std::endl;
    }

    return 0;
}