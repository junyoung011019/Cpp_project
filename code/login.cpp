#include <iostream>
#include <cstring>

using namespace std;

class user_info {
public:
    char user_name[5]; //�̸�
    string user_id; //���̵�
    string user_pw;
};

class admin_info {
public:
    char admin_name[5]; //�̸�
    string admin_id; //���̵�
    string admin_pw;
};



int main() {
    //�ӽ� ����
    user_info test_user_1;
    strcpy(test_user_1.user_name, "�׽�Ʈ_���ؿ�");
    test_user_1.user_id = "junyoung";
    test_user_1.user_pw = "1q2w3e4r!";

    admin_info test_admin1;
    strcpy(test_admin1.admin_name, "�׽�Ʈ_������1");
    test_admin1.admin_id = "admin";
    test_admin1.admin_pw = "1q2w3e4r!";

    //�α��� ����
    char login_state = '0';

    cout << "CS ���� ���࿡ ���Ű� ȯ���մϴ�!\n�α���\n";
    //�α��ν� �Է� �޴� id�� pw
    string input_id;
    string input_pw;
    //�α��� ����
    int login_error = 0;
    while (1) {
        //id �Է�
        cout << "���̵� �Է����ּ���.\n";
        cin >> input_id;
        //pw �Է�
        cout << "��й�ȣ�� �Է����ּ���.\n";
        cin >> input_pw;
        //�α��� ���� Ȯ��
        if ((input_id == test_user_1.user_id) && (input_pw == test_user_1.user_pw)) {
            cout << "���ؿ��� ȯ���մϴ�!\n";
            login_state = 'J';
            break;
        }
        else if ((input_id == test_admin1.admin_id) && (input_pw == test_admin1.admin_pw)) {
            cout << "�����ڴ� ȯ���մϴ�.\n";
            login_state = 'A';
            break;
        }
        else {
            cout << "���̵� Ȥ�� ��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n";
            login_error += 1;
        }

        if (login_error == 5) {
            cout << "�α��� 5ȸ ���з� ���� ���α׷��� ����˴ϴ�.";
            return 0;
        }
    }
    cout << "�� ������ ��µȴٸ�, ���� �α��� �Ȱ���. \n";
    if (login_state == 0) {
        cout << "�α����� ���������� ��������ʰ� �Ѿ��";
    }
    if (login_state == 'J') {
        cout << "���ؿ� �������� ���� �α��ε�";
    }
    if (login_state == 'A') {
        cout << "�׽�Ʈ_������1 �������� ���� �α��ε�";
    }




}

