#include "Framework.h"


MYSQL Conn;                //mysql ���� ���� ����ü
MYSQL* ConnPtr = NULL;    //mysql �ڵ�
MYSQL_RES* Result;        //���� ������ ����� ��� ����ü ������
MYSQL_ROW Row;            //���� ������ ����� ���� ���� ������ ��� ����ü
int Stat;                 //���� ��û �� ��� (����, ����)

int EndCode = 0;


class Login {
public:
    string Input_ID, Input_PW;
    int missing = 0, error = 0;
    int MemberNo = 0;
protected:
    void login() {}
};

void Login::login() {
    system("cls");
    cout << "---------------�α���---------------" << "\n";
    while (1) {
        cout << "���̵� �Է��ϼ���. >";
        cin >> Input_ID;
        cout << "��й�ȣ�� �Է��ϼ���. >";
        cin >> Input_PW;
        //���̵� ��й�ȣ�� sql���� Ȯ���ϴ� ����
        if (1) {
            cout << "ȯ���մϴ�!";
                //MemberNo ������ ������� Ű ���� ����
            break;
        }
        else {
            missing += 1;
            cout << "��й�ȣ�� �����ʽ��ϴ�.";
            cout << "���� ��й�ȣ" << missing << "ȸ �����Դϴ�.";
            if missing < 5{
                error = 1;
                break;
            }
            cout << "�α��� 5ȸ ���н� �α����� ���ѵ˴ϴ�.";
        }
    }

}

class SignUp {
public:
    string ID, PW, NAME;
    int PhoneNumber = 0;
    string AcccountNumber;
protected:
    void signup();
};

void SignUp::signup() {
    system("cls");
    cout << "---------------ȸ������---------------" << "\n";
    cout << "�̸��� �Է��ϼ���. (����� ������ ����) >";
    cin >> NAME;
    while (1) {
        cout << "����Ͻ� ���̵� �Է��ϼ���. (���� 2��)";
        cin >> ID;
        char idcheck[] = "SELECT ID FROM customer_table";
        cout << idcheck << endl;
        if (idcheck[0] == NULL) {
            break;
        }
        cout << "�̹� �����ϴ� ���̵��Դϴ�!\n";
        break;
    }
    cout << "����Ͻ� ��й�ȣ�� �Է��ϼ���. (���� 2��)";
    cin >> PW;
    while (1) {
        cout << "��ȭ��ȣ�� �Է��ϼ���.";
        cin >> PhoneNumber;
        char phonenumcheck[] = "SELECT PhoneNumber FROM customer_table";
        if (phonenumcheck[0] == NULL) {
            break;
        }
        cout << "�̹� ���Ե� ȸ���Դϴ�!\n";
        break;
    }
    cout << "������ ���� ��ȣ��" << PhoneNumber << "0 �Դϴ�!\n";
    AcccountNumber = PhoneNumber;
    stringstream AcccountNumber;
    cout << "������ �������� ȯ���մϴ�!!!\n";
    "INSERT INTO `cs_bank`.`customer_table` (`ID`, `Name`, `Phone`, `Password`, `ACCOUNTNUMBER`) VALUES(ID, NAME, PhoneNumber, PW, AcccountNumber)";
    int a;
    cin >> a;
}

class Start : public Login, public SignUp {
public:
    int StartMenuNum = 0;
    void start();
};

class User : public Start {
public:
    int UserMenuNum = 0;
    void UserFunction();
    //������ ������ �޾ƿ��� ����
    string UserName;


    deposit();
    withdraw();
    transfer();
    AccountCheck();
    TransferCheck(); break;
}

void User::deposit() {
    int InputDeposit;
    cout << "�Ա� �Ͻ� �ݾ��� �Է��ϼ���.";
    cin >> InputDeposit;

}

void User::withdraw() {

}

void User::transfer() {

}

void User::AccountCheck() {

}

void User::TransferCheck() {

}

void User::UserFunction() {
    system("cls");
    cout << "---------------ȯ���մϴ�!" << UserName << "��!---------------" << "\n";
    cout << "1. ���� �Ա�" << endl;
    cout << "2. ���� ���" << endl;
    cout << "3. ���� ��ü" << endl;
    cout << "4. ���� ���� ��ȸ" << endl;
    cout << "5. ��ü ���� Ȯ��" << endl;
    cout << "6. �α׾ƿ�" << endl;
    cout << "7. ���α׷� ����" << endl
        cin >> UserMenuNum;
    switch (UserMenuNum) {
    case 1:
        deposit();  break;
    case 2:
        withdraw();  break;
    case 3:
        transfer(); break;
    case 4:
        AccountCheck(); break;
    case 5:
        TransferCheck(); break;
    case 6:
        MemberNo = 0;
        break;
    case 7:
        EndCode = 1; break;
    default:
        system("cls");
        cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n";
        UserFunction();
    }
}

void Start::start() {

    cout << "------------------------------------" << "\n";
    cout << "1. ȸ������" << endl;
    cout << "2. �α���" << endl;
    cout << "3. ����" << endl;
    cout << "------------------------------------" << "\n";
    cin >> StartMenuNum;
    switch (StartMenuNum) {
    case 1:
        signup();  break;
    case 2:
        login();  break;
    case 3:
        EndCode = 1; break;
    default:
        system("cls");
        cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n";
        start();
    }
    if (error = 1) {
        cout << "���� �ڵ� 1";
        cout << "�α��ο� 5ȸ �����߽��ϴ�.";
        cout << "���α׷��� ����˴ϴ�";
        EndCode = 1; break;
    }
    if (MemberNo != 0) {
        //�α��� �Ϸ�
        break;
    }
}

int main()
{
    //////////////////////////////////////MYSQL ����//////////////////////////////////////



    mysql_init(&Conn);         //mysql ���� �ʱ�ȭ

    //�����ͺ��̽��� ����
    ConnPtr = mysql_real_connect(&Conn, "localhost", "root", "1q2w3e4r!", "cs_bank", 3306, (char*)NULL, 0);

    //���� ��� Ȯ��. null�ϰ�� ����
    if (ConnPtr == NULL)
    {
        fprintf(stderr, "Mysql query error:%s", mysql_error(&Conn));
        return 1;
    }

    //�����ͺ��̽��� ��������
    char Query[] = "SELECT * FROM customer_table";    //�����ݷ��� �����ϰ� ������ �ۼ�
    Stat = mysql_query(ConnPtr, Query);           //���� ��û �� �������� �޾ƿ���
    if (Stat != 0)                                //���� ��û ���� �� ���� ó��
    {
        fprintf(stderr, "Mysql query error:%s\n", mysql_error(&Conn));
        return 1;
    }
    Result = mysql_store_result(ConnPtr);          //���Ȯ��
    while ((Row = mysql_fetch_row(Result)) != NULL) //��� ���
    {
        printf("%s %s %s %s %s %s\n", Row[0], Row[1], Row[2], Row[3], Row[4], Row[5]);
    }
    mysql_free_result(Result);                         //��� ����

    mysql_close(ConnPtr);

    //////////////////////////////////////���� ���� ����//////////////////////////////////////
    while (1) {
        system("cls");
        cout << " =========================**cs �������࿡ ���� �� ȯ���մϴ�**=============================\n\n";
        Start customer;
        if (customer.MemberNo == 0) {
            customer.start();

        }
        else {
            User user;
            user.UserFunction();
        }
        if (EndCode == 1) {
            cout << "���α׷��� ���� �˴ϴ�!";
            return 0;
        }



    }
}