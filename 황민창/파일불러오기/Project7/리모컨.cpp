// �輺ö ��ǻ�� - ����Ʈ���� �а� - 20102049 

#include <iostream>
#include <windows.h>
using namespace std;



class TV
{
    bool on;
    int channel;
    int volume;

public:
    void powerOn()
    {
        on = true;
        cout << "TV�� �׽��ϴ�" << endl;
    }
    void powerOFF()
    {
        on = false;
        cout << "TV�� �����ϴ�" << endl;
    }
    void menu() // �޴� ����
    {
        cout << "==================" << endl;
        cout << "1. ä�� ����" << endl;
        cout << "2. ���� ����" << endl;
        cout << "3. ä�� �� ����" << endl;
        cout << "4. TV ����" << endl;
        cout << "==================" << endl;
    }
    void pyeonseongpyo() // ä�� ��ǥ
    {
        cout << "==================" << endl;
        cout << "1�� SBS" << endl;
        cout << "2�� KBS" << endl;
        cout << "3�� MBC" << endl;
        cout << "4�� EBS" << endl;
        cout << "5�� SPORT TV" << endl;
        cout << "==================" << endl;


    }
    void setChannel(int choiceChl)
    {
      

            while (1)
            {
                if (choiceChl == 1)
                {
                    cout << "SBS ä���� ��û ���Դϴ� !!";
                    break;
                }
                if (choiceChl == 2)
                {
                    cout << "KBS ä���� ��û ���Դϴ� !!";
                    break;
                }
                if (choiceChl == 3)
                {
                    cout << "MBC ä���� ��û ���Դϴ� !!";
                    break;
                }
                if (choiceChl == 4)
                {
                    cout << "EBS ä���� ��û ���Դϴ� !!";
                    break;
                }
                if (choiceChl == 5)
                {
                    cout << "SPORT TV ä���� ��û ���Դϴ� !!";
                    break;
                }
               

            }
        
    }

    void incVol();

    void decVol();

    void setVol(int vol);

};


int main()
{
    TV tv; // Ŭ���� ��ü ����
    int menuCho; // �޴� ����
    int choiceChl = 0; // ä�� ����


    tv.powerOn(); // TV ���� ON

    tv.menu();
    cout << "�޴��� ���� ���ּ��� >> ";
    cin >> menuCho;

    if (menuCho == 1)
    {
        tv.pyeonseongpyo();
        cout << "������� ä���� �Է��ϼ��� >> ";
        tv.setChannel(choiceChl);
        cin >> choiceChl;

        Sleep(800);
        system("cls");
    }

    tv.menu();
    cout << "�޴��� ���� ���ּ��� >> ";
    cin >> menuCho;


   







    if (menuCho == 4)
    {
        tv.powerOFF();
    }
}