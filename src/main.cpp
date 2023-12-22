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
			throw AppException("No se encuentra un usuario registrado con esas credenciales");

		// Mostramos menús
		char opcion[10];
		do{

			switch(user.tipo()[0]) {
				// Menú para los usuarios registrados
				case 'u':
				{
					cout << "\n\n\t---------------------------------------" << endl;
					cout << "\t\t\tMENU" << endl;
					cout << "\t---------------------------------------" << endl;
					cout << "\n\t1. Consultar preinscripciones" << endl;
					cout << "\t0. Salir" << endl;

					cout << "\n\n\t¿Qué desea hacer?: ";
					std::cin >> opcion;

					switch(opcion[0]){
						case '1':
						{
							uint16_t cont;
							sql::Statement *query;
							query = con->createStatement();//	1		2			3			4		5			6			7			8		9
							res = query->executeQuery("SELECT titulo, descripcion, tematica, ubicacion, aforo, fecha_inicio, fecha_fin, duracion, precio FROM ACTIVIDAD WHERE estado = 'activa'");

							for(cont = 0; res->next(); cont++){
								cout << "\n\t\tPRÓXIMOS EVENTOS\n" << endl
									 << ((res->getString(1) == "")? "N/A" : res->getString(1)) << endl		// Mostramos título
									 <<	((res->getString(2) == "")? "N/A" : res->getString(2)) << endl		// Mostramos descripción
									 << "\nTendrá lugar en " + ((res->getString(4) == "")? "N/A" : res->getString(4))
									 << ", Aforo: " << res->getInt(5) << endl
									 << "Fecha de inicio: " << ((res->getString(6) == "")? "N/A" : res->getString(6)) << endl
									 << "Fecha de clausura: " << ((res->getString(7) == "")? "N/A" : res->getString(7)) << endl
									 << "Duración: " << res->getInt(8) << " minutos" << endl
									 << "Precio: " << ((res->getDouble(9) == 0)? "gratuíto" : std::to_string(res->getDouble(9))) << endl;
							}

							if(cont == 0)
								cout << "\n\tNo hay actividades/eventos que mostrar" << endl;
						}
						break;
						default:
							cout << "\nLa opción escogida no es válida" << endl;
					}
				}
				break;

				// Menú para los organizadores
				case 'o':
				{
					cout << "\n\n\t---------------------------------------" << endl;
					cout << "\t\t\tMENU" << endl;
					cout << "\t---------------------------------------" << endl;
					cout << "\n\t1. Crear actividad" << endl;
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

							delete pst;
						}
						break;

						case '0':
							cout << "\nHa escogido salir";

						default:
							cerr << "\nLa opción escogida no es válida" << endl;
					}
				}
				break;

				case 'd':
				{
					cout << "\n\n\t---------------------------------------" << endl;
					cout << "\t\t\tMENU" << endl;
					cout << "\t---------------------------------------" << endl;
					cout << "\n\t1. Consulta tus actividades/eventos" << endl;
					cout << "\t2. Modifica/rellena una actividad/evento" << endl;
					cout << "\t0. Salir" << endl;

					cout << "\n\n\t¿Qué desea hacer?: ";
					std::cin >> opcion;

					switch(opcion[0]){
						// Consultar eventos asignados
						case '1':
						{
							uint16_t cont;
							//										1		2			3			4		5			6			7			8		9	  10		11
							pst = con->prepareStatement("SELECT titulo, descripcion, tematica, ubicacion, aforo, fecha_inicio, fecha_fin, duracion, precio, estado, id_actividad FROM ACTIVIDAD WHERE director = ?");
							pst->setString(1, user.username());
							res = pst->executeQuery();

							for(cont = 0; res->next(); cont++){
								cout << "\n\t\tEVENTOS ASIGNADOS\n" << endl
									 << "IDENTIFICADOR: " << res->getInt(11) << endl
									 << ((res->getString(1) == "")? "N/A" : res->getString(1)) << endl		// Mostramos título
									 <<	((res->getString(2) == "")? "N/A" : res->getString(2)) << endl		// Mostramos descripción
									 << "\nTendrá lugar en " + ((res->getString(4) == "")? "N/A" : res->getString(4))
									 << ", Aforo: " << res->getInt(5) << endl
									 << "Fecha de inicio: " << ((res->getString(6) == "")? "N/A" : res->getString(6)) << endl
									 << "Fecha de clausura: " << ((res->getString(7) == "")? "N/A" : res->getString(7)) << endl
									 << "Duración: " << res->getInt(8) << " minutos" << endl
									 << "Precio: " << ((res->getDouble(9) == 0)? "gratuíto" : std::to_string(res->getDouble(9))) << endl
									 << "Estado/visibilidad: " << res->getString(10);
							}

							if(cont == 0)
								cout << "\n\tNo hay actividades/eventos que mostrar" << endl;
						}
						break;

						// Modificar eventos
						case '2':
						{
							string id;

							cout << "\n\nIntroduce el identificador del evento a modificar: ";
							std::cin >> id;


						}
						break;

						case '0':
							cout << "\nHa escogido salir";

						default:
							cerr << "\nLa opción escogida no es válida" << endl;
					}
				}
				break;
			}
		}while(opcion[0] != '0');

	}
	// Atrapamos excepciones propias
	catch(AppException &e) {
		cerr << e.what() << endl;
	}
	// Atrapamos excepciones de SQL
	catch(sql::SQLException & e){
		cerr << "# ERR: SQLException in " << __FILE__;
		cerr << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cerr << "# ERR: " << e.what();
		cerr << " (MySQL error code: " << e.getErrorCode();
		cerr << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	return 0;
}
