#ifndef __CERTIFICADO_HPP__
#define __CERTIFICADO_HPP__

#include <iostream>

using std::string;

class Certificado {
public:
	// Constructores
	Certificado(){};

	// Sustituye una cadena (from) dentro de una cadena más grande (str) por otr cadena
	// especificada por el usuario (to)
	bool replace(std::string& str, const std::string& from, const std::string& to) {
	    size_t start_pos = str.find(from);
	    if(start_pos == std::string::npos)
	        return false;
	    str.replace(start_pos, from.length(), to);
	    return true;
	}

	// Imprimir certificado
	void imprimir(){}

	// Getters

	inline uint32_t id() const {
		return _id_certificado;
	}

	inline string actividad() const {
		return _actividad;
	}

	inline string texto() const {
		return _texto;
	}

	inline string titulo() const {
		return _titulo;
	}

	inline tm* fecha() const{
		// TODO: devolver en forma de cadena
		return _fecha;
	}

	// Setters

	inline void set_id(const uint32_t &nuevo_id) {
		_id_certificado = nuevo_id;
	}

	inline void set_actividad(const string &actividad) {
		_actividad = actividad;
	}

	inline void set_texto(const string &texto) {
		_texto = texto;
	}

	inline void set_titulo(const string &nuevo_titulo) {
		_titulo = nuevo_titulo;
	}

	inline void set_fecha(int dia, int mes, int anio) {
		// TODO: convertir enteros a fecha
	}

private:
	uint32_t _id_certificado = 0; // Identificador del certificado
	string _actividad;			  // Título de la actividad asociada
	string _texto;				  // Texto del certificado
	string _titulo;				  // Título del certificado
	tm *_fecha = nullptr;		  // Fecha de creación del certificado
};

#endif
