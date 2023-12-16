#ifndef __APP_EXCEPTIONS__
#define __APP_EXCEPTIONS__

#include <iostream>
#include <exception>

using std::string;

class AppException: public std::exception
{
private:
	string _mensaje = "";

public:

	inline AppException(const char *excepcion)
	:_mensaje(excepcion) {};

	inline AppException(const string &excepcion)
	:_mensaje(excepcion) {};


	inline const char *what() {
		_mensaje = "\nERROR EN LA APLICACIÓN\n" + _mensaje;
		return _mensaje.c_str();
	}
};

#endif
