#pragma once
#include <iostream>
#include <string.h>
#include <mysql.h>

using namespace std;
class conexion
{
private:
	MYSQL *con;

public:
	MYSQL* getconexion() {
		con = mysql_init(0);
		con = mysql_real_connect(con, "localhost", "root", "12345", "crud", 3306, NULL, 0);
		return con;
	}
	void cerrarcone() {
		mysql_close(con);
	}
};




