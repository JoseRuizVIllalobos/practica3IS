#include <iostream>

#include <appexceptions.hpp>
#include <usuarioregistrado.hpp>
#include <certificadoasistencia.hpp>
#include <actividad.hpp>

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
	string servidor = "tcp://127.0.0.1:3306";
	string username = "root";
	string password = "is2023";

	try {
		string usuario, pass;
		UsuarioRegistrado user;
		Actividad actividad;

		sql::Driver *driver = get_driver_instance();
		sql::Connection *con = driver->connect(servidor, username, password);

		con->setSchema("eventos_gestion");

		// Si no salta ninguna excepción, la conexión se habra creado con exito
		cout << "\nCONEXION CREADA CON EXITO" << endl;

		cout << "Intruduce tu usuario: ";
		std::cin >> usuario;

		cout << "Intruduce la clave: ";
		std::cin >> pass;

		sql::PreparedStatement *pst = con->prepareStatement("SELECT nombre_usuario, dni, nombre, apellidos, fecha_nacimiento, fecha_registro, sexo, correo, tipo FROM USUARIO WHERE nombre_usuario = ? AND password = ? AND estado = \'activo\'");

		pst->setString(1, usuario);
		pst->setString(2, pass);
		sql::ResultSet *res = pst->executeQuery();
		delete pst;

		// Si el usuario no está registrado
		if(res->next()){
			user.set_username(res->getString(1));
			user.set_dni(res->getString(2));
			user.set_nombre(res->getString(3));
			user.set_apellidos(res->getString(4));
			user.set_nacimiento(res->getString(5));
			user.set_registro(res->getString(6));
			user.set_sexo(res->getString(7));
			user.set_correo(res->getString(8));
			user.set_tipo(res->getString(9));

			cout << "\n\t¡Bienvenido " + user.nombre_completo() << "!" << endl;
		}
		else
			throw AppException("Usuario no existe");

		switch(user.tipo()[0]) {
			case 'u':
				cout << "USUARIO" << endl;
				break;

			case 'o':
				char opcion[10];

				cout << "\n\t\tMENU" << endl;
				cout << "\t1. Crear actividad" << endl;
				cout << "\t0. Salir" << endl;

				cout << "\n\n\t¿Qué desea hacer?: ";
				std::cin >> opcion;

				switch(opcion[0]){
					case '1':
					{
						string director;
						bool exito;

						cout << "\n\tIntroduce el nombre de usuario del director: ";
						std::cin >> director;

						//TODO: comprobar que el director está registrado y que su tipo de usuario es igual a 'director'

						pst = con->prepareStatement("INSERT INTO ACTIVIDAD(director) VALUES(?)");
						pst->setString(1, director);
						exito = pst->executeUpdate();

						if(exito)
							cout << "\n¡Actividad creada con éxito!" << endl;
						else
							throw AppException("Error al crear una nueva actividad");
					}
					break;

					default:
						cout << "\nLa opción escogida no es válida" << endl;
				}
				break;

			case 'd':
				cout << "DIRECTOR" << endl;
				break;
		}

	}
	catch(AppException &e) {
		cerr << e.what() << endl;
	}
	catch(sql::SQLException & e){
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	return 0;
}
