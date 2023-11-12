#include "framework.h"

int main()
{
	struct DBConnection {
		const char* server = "localhost",
			* user = "root",
			* pw = "0000",
			* db = "market_db";
	}DbCon;

	MYSQL mysql;

	mysql_init(&mysql);  //����

	if (mysql_real_connect(&mysql, DbCon.server, DbCon.user, DbCon.pw, DbCon.db, 0, NULL, 0))
		cout << "MySQL ���� : " << mysql_get_client_info() << endl;
	else
		cout << "����" << endl;

	mysql_close(&mysql); //��ȯ

	system("Pause");
	return 0;
}

