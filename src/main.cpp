#include <iostream>
#include <usuarioregistrado.hpp>
#include <certificadoasistencia.hpp>

// Para conectar con la base de datos local
#include <mysql/jdbc.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/build_config.h>
#include <jdbc/cppconn/callback.h>
#include <jdbc/cppconn/config.h>
#include <jdbc/cppconn/connection.h>
#include <jdbc/cppconn/datatype.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/metadata.h>
#include <jdbc/cppconn/parameter_metadata.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/resultset_metadata.h>
#include <jdbc/cppconn/sqlstring.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/variant.h>
#include <jdbc/cppconn/version_info.h>
#include <jdbc/cppconn/warning.h>

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
	UsuarioRegistrado user;

	string servidor = "tcp://127.0.0.1:3306";
	string username = "root";
	string password = "is2023";

	try {

	sql::Driver *driver = get_driver_instance();
	sql::Connection *con = driver->connect(servidor, username, password);

	// Si no salta ninguna excepción, la conexión se habra creado con exito
	cout << "\nCONEXION CREADA CON EXITO" << endl;

	sql::Statement *st;
	sql::PreparedStatement *pst;
	}
	catch(sql::SQLException & e){
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	try {
		user.set_dni("31019261N");
		user.set_sexo("HoMbre");

		cout << user.sexo() << endl;
	}
	catch(AppException &e) {
		cerr << e.what() << endl;
	}

	return 0;
}
