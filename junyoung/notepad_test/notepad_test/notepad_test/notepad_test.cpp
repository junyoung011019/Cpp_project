#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;


struct UserInfo {
    string name;
    string id;
    string pw;
};

UserInfo signup_function() {
    UserInfo user;
    cout << "�̸� �Է�>>";
    cin >> user.name;
    cout << "id �Է�>>";
    cin >> user.id;
    cout << "pw �Է�>>";
    cin >> user.pw;

    return user;
}



void file_input() {
    ofstream fout;
    fout.open("file.txt", std::ios_base::app);
    UserInfo userInfo = signup_function();
    fout << userInfo.name << " "<< userInfo.id << " " << userInfo.pw << "\n";
    fout.close();
}

void file_output() {
    ifstream fin;
    fin.open("file.txt");
    string number[100];
    int time = 0;
    for (int a = 0; a < 100; a++) {
        fin >> number[a];
    }
   
    for (int i = 1; i < 100; i++) {
        cout << number[i-1] << number[i]<< number[i +1]<<"\n";
    }

    cout << "\n";
}



int main()
{
    while (1) {
        int num;
        cout << "������ ��ȣ �Է� 1.�Է� 2.��� 3.�ʱ�ȭ>>";
        cin >> num;
        if (num == 1) {
            file_input();
        }else if(num == 2) {
            file_output();
        }
        else if (num == 3) {
            cout << "������ ���� �ʱ�ȭ �Ͻðڽ��ϱ�? Ȯ�� 1, ��� 2>>";
            int check;
            cin >> check;
            if (check == 1) {
                std::remove("file.txt");
            }
        }
        
    }

}