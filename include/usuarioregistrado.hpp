#ifndef __USUARIO_REGISTRADO__
#define __USUARIO_REGISTRADO__

#include <iostream>
#include <algorithm>
#include <ctime>

#include <appexceptions.hpp>

using std::string;
using std::cerr;
using std::endl;

class UsuarioRegistrado {

private:
	string _nombre_usuario = "";
	string _dni = "";
	string _nombre = "";
	string _apellidos = "";
	tm *_fecha_nacimiento = nullptr;
	tm *_fecha_registro = nullptr;
	string _sexo = "";
	string _correo = "";

public:

	// Constructores
	UsuarioRegistrado(){};

	UsuarioRegistrado(const string &username, const string &dni, const string &nombre, const string &apellidos, tm *nacimiento, tm *registro, const string &sexo, const string &correo)
	:_nombre_usuario(username), _dni(dni), _nombre(nombre), _apellidos(apellidos),_fecha_nacimiento(nacimiento), _fecha_registro(registro), _sexo(sexo), _correo(correo) {};

	/*------------- GETTERS ------------------------------*/

	// Devuelve el nombre del usuario
	inline string username() const {
		return _nombre_usuario;
	}

	// Devuelve el DNI del usuario
	inline string dni() const {
		return _dni;
	}

	// Devuelve el nombre completo del usuario
	inline string nombre_completo() const {
		return (_nombre + " " + _apellidos);
	}

	// Devuelve la fecha de nacimiento del usuario
	inline string fecha_nacimiento() const {
		// Comprobamos que hay una fecha almacenada
		if(_fecha_nacimiento != nullptr){
			int dia = _fecha_nacimiento->tm_mday;
			int mes = 1 + _fecha_nacimiento->tm_mon;
			int anio = 1900 + _fecha_nacimiento->tm_year;

			string dia_str = (dia < 10)? "0" + std::to_string(dia) : std::to_string(dia);
			string mes_str = (mes < 10)? "0" + std::to_string(mes) : std::to_string(mes);
			string anio_str = std::to_string(anio);

			return (dia_str + "/" + mes_str + "/" + anio_str);
		}
		else
			return "N/A";
	}

	// Devuelve la fecha de nacimiento del usuario
	inline string fecha_registro() const {
		// Comprobamos que hay una fecha almacenada
		if(_fecha_registro != nullptr){
			int dia = _fecha_registro->tm_mday;
			int mes = 1 + _fecha_registro->tm_mon;
			int anio = 1900 + _fecha_registro->tm_year;

			string dia_str = (dia < 10)? "0" + std::to_string(dia) : std::to_string(dia);
			string mes_str = (mes < 10)? "0" + std::to_string(mes) : std::to_string(mes);
			string anio_str = std::to_string(anio);

			return (dia_str + "/" + mes_str + "/" + anio_str);
		}
		else
			return "N/A";
	}

	// Devuelve el sexo biologico del usuario
	inline string sexo() const {
		return _sexo;
	}

	// Devuelve el correo del usuario
	inline string correo() const {
		return _correo;
	}

	/*-------------- SETTERS ----------------------------*/

	// Establece el username del usuario
	inline void set_username(const string &nuevo_usuario) {
		//TODO: comprobar que no se encuentra en la BD
		_nombre_usuario = nuevo_usuario;
	}

	// Establece el DNI del usuario
	inline void set_dni(const string &dni) {
		// Comprobamos que el DNI tiene una longitud igual a 9 (8 dígitos y una letra)
		if(dni.length() != 9)
			throw AppException("La longitud del DNI es incorrecta");

		// Separamos el número de la letra
		string dni_num = dni.substr(0, 8);
		string dni_letra = dni.substr(8, 1);

		// Comprobamos que el número sean solo dígitos
		string::const_iterator it = dni_num.begin();
		while (it != dni_num.end() && std::isdigit(*it)) ++it;

		if(dni_num.empty() || it != dni_num.end())
			throw AppException("Formato incorrecto. El DNI consiste de 8 números y 1 letra");

		// Comprobamos que la letra sea una letra
		if(!std::isalpha(dni_letra.c_str()[0]))
			throw AppException("Formato incorrecto. El DNI consiste de 8 números y 1 letra");
	}


	// Establece el nombre del usuario
	inline void set_nombre(const string &nuevo_nombre){
		_nombre = nuevo_nombre;
	}

	inline void set_nombre(const char *nuevo_nombre){
		_nombre = static_cast<string>(nuevo_nombre);
	}

	// Establece los apellidos del usuario
	inline void set_apellidos(const string &nuevos_apellidos){
		_apellidos = nuevos_apellidos;
	}

	inline void set_apellidos(const char *nuevos_apellidos){
		_apellidos = static_cast<string>(nuevos_apellidos);
	}

	// Establece la fecha de nacimiento del usuario
	inline void set_nacimiento(int dia, int mes, int anio){
		//TODO: COMPROBAR QUE ES VALIDA
		if(_fecha_nacimiento == nullptr)
			_fecha_nacimiento = new tm;

		_fecha_nacimiento->tm_mday = dia;
		_fecha_nacimiento->tm_mon = mes;
		_fecha_nacimiento->tm_year = anio;
	}

	// Establece el sexo del usuario
	inline void set_sexo(string &sexo){
		std::transform(sexo.begin(), sexo.end(), sexo.begin(), [](unsigned char c) { return std::tolower(c);});
		_sexo = sexo;
	}

	inline void set_sexo(const char *sexo){
		// Convertimos el const char* a string
		string sex(sexo);
		set_sexo(sex);
	}

	// Destructor de la clase
	~UsuarioRegistrado(){
		if(_fecha_nacimiento != nullptr)
			delete _fecha_nacimiento;

		if(_fecha_registro != nullptr)
			delete _fecha_registro;
	}
};

#endif
