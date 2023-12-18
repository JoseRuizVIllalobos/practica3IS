#ifndef __ASISTENCIA_HPP__
#define __ASISTENCIA_HPP__

#include <certificado.hpp>

class CertificadoAsistencia: public Certificado {
	CertificadoAsistencia(const string &alumno, const string &titulo_actividad)
	: _alumno(alumno) {

		set_titulo("Certificado de Asistencia");
		set_texto("Entregamos el presente a " + alumno + " por asistir a la actividad " + titulo_actividad);

		// TODO: terminar clase

	};

private:
	string _alumno;
};

#endif
