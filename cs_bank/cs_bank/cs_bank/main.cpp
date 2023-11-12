// CS ��������


#include <iostream>
#include <string>

using namespace std;

// ������� ó���ϴ� �⺻ Ŭ����
class Transaction
{
protected:
    double balance;  // �ܾ� �߰�

public:
    Transaction() : balance(0.0) {}

    // �Ա� �Լ�
    void deposit(double amount)
    {
        balance += amount;
        cout << amount << "�� �Ա� �Ϸ�. ���� �ܾ�: " << balance << endl;
    }

    // ��� �Լ�
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "�ܾ��� �����մϴ�." << endl;
        }
        else
        {
            balance -= amount;
            cout << amount << "�� ��� �Ϸ�. ���� �ܾ�: " << balance << endl;
        }
    }

    // �ܾ� ��ȸ �Լ�
    double getBalance() const
    {
        return balance;
    }
};

// �� ���� Ŭ����, ����� Ŭ������ ��ӹ���
class CustomerInfo : public Transaction
{
private:
    string name;
    string address;
    string phone_number;
    string PW;
    bool Islogin;  // ȸ������ ���θ� ��Ÿ���� �÷���

public:
    // ������
    CustomerInfo(double EarlyBalance = 0.0) : Transaction(), Islogin(false)
    {
        balance = EarlyBalance;
    }

    // ����ڷκ��� ���� �Է�
    void inputInfo()
    {
        cout << "�̸��� �Է��ϼ���: ";
        cin >> name;

        cout << "�ּҸ� �Է��ϼ���: ";
        cin >> address;

        cout << "��ȭ��ȣ�� �Է��ϼ���: ";
        cin >> phone_number;

        cout << "��й�ȣ�� �Է��ϼ���: ";
        cin >> PW;

        Islogin = true;  // ȸ������ �Ϸ� �� �÷��׸� true�� ����
    }

    // ��ü ����� �Է¹޴� �Լ�
    void inputTransferInfo()
    {
        cout << "��ü�� ����� �̸��� �Է��ϼ���: ";
        cin >> name;

        cout << "��ü�� ����� ��ȭ��ȣ�� �Է��ϼ���: ";
        cin >> phone_number;
    }

    // ���� ��� �Լ�
    void displayInfo() const
    {
        cout << "�� ����:" << endl;
        cout << "�̸�: " << name << endl;
        cout << "�ּ�: " << address << endl;
        cout << "��ȭ��ȣ: " << phone_number << endl;
        cout << "�ܾ�: " << balance << endl;
    }

    // ��ü ���� �Լ�
    void transfer(CustomerInfo recipient, double amount) //recipient ���� : �޴� ���
    {
        if (amount > balance)
        {
            cout << "��ü ����: �ܾ��� �����մϴ�." << endl;
        }
        else {
            // ��ü ��󿡰� �Ա�
            recipient.deposit(amount);

            // ��ü�ϴ� ������ ���
            withdraw(amount);

            cout << "��ü �Ϸ�: " << amount << "�� ��ü��." << endl;
        }
    }

    // ȸ������ ���� Ȯ�� �Լ�
    bool isRegisteredUser()
    {
        return Islogin;
    }
};

//////////////////////////////////////////�����Լ� ����//////////////////////////////////////////////////////////////////////

int main()
{
    cout << " =========================**cs �������࿡ ���� �� ȯ���մϴ�**=============================\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";

    int MenuChoice;

    CustomerInfo customer;  // �� ��ü ����

    while (1)
    {
        cout << "------------------------------------" << "\n";
        cout << "1. ȸ������" << endl;
        cout << "2. ���� �Ա�" << endl;
        cout << "3. ���� ���" << endl;
        cout << "4. ���� ��ü" << endl;
        cout << "5. ���� ��ȸ" << endl;
        cout << "6. ����" << endl;
        cout << "------------------------------------" << "\n";

        cout << "���Ͻô� �޴��� �Է��� �ּ��� >> ";
        cin >> MenuChoice;

        switch (MenuChoice)
        {
        case 1:
        {
            double EarlyBalance;
            cout << "�ʱ� �ܾ��� �Է��ϼ���: ";
            cin >> EarlyBalance;
            customer = CustomerInfo(EarlyBalance);  // ȸ������ �� �ʱ� �ܾ� ����
            customer.inputInfo();
        }
        break;
        case 2:
            if (!customer.isRegisteredUser())
            {
                cout << "ȸ�������� �ʿ��մϴ�." << endl;
                break;
            }

            double depositAmount;
            cout << "�Ա��� �ݾ��� �Է��ϼ���: ";
            cin >> depositAmount;
            customer.deposit(depositAmount);
            break;
        case 3:
            if (!customer.isRegisteredUser())
            {
                cout << "ȸ�������� �ʿ��մϴ�." << endl;
                break;
            }

            double withdrawAmount;
            cout << "����� �ݾ��� �Է��ϼ���: ";
            cin >> withdrawAmount;
            customer.withdraw(withdrawAmount);
            break;
        case 4:
            if (!customer.isRegisteredUser())
            {
                cout << "ȸ�������� �ʿ��մϴ�." << endl;
                break;
            }

            {
                CustomerInfo recipient;  // ��ü ��� �� ��ü ����
                customer.inputTransferInfo();  // ��ü ��� �Է� �ޱ�
                double transferAmount;

                cout << "��ü�� �ݾ��� �Է��ϼ���: ";
                cin >> transferAmount;

                // ��ü ����
                customer.transfer(recipient, transferAmount);
            }
            break;
        case 5:
            if (!customer.isRegisteredUser())
            {
                cout << "ȸ�������� �ʿ��մϴ�." << endl;
                break;
            }

            customer.displayInfo();
            break;
        case 6:
            cout << "���α׷��� �����մϴ�." << endl;
            return 0;
        default:
            cout << "�ùٸ� �޴��� �����ϼ���." << endl;
        }
    }

    return 0;
}
