#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>

using std::string;

enum ActividadStatus{
	PENDIENTE,
	PASADA,
	CANCELADA
};

class Actividad{

	private:
		int id_ = 0;
		string titulo_;
		string descripcion_;
		string ubicacion_;
		string tematica_;
		tm *fecha_inicio_ = nullptr;
		tm *fecha_fin_ = nullptr;
		int duracion_minutos_ = -1;
		int aforo_ = -1;
		float precio_entrada_ = 0;
		std::list<std::string> ponentes_;
		ActividadStatus estado_ = PENDIENTE;
		string director_;
	public:
		//CONSTRUCTORES:
		Actividad(){};

		Actividad(int id, string titulo, string descripcion, string ubicacion, string tematica, int duracion_minutos, int aforo, float precio_entrada, ActividadStatus estado, string director)
		:id_(id), titulo_(titulo), descripcion_(descripcion), ubicacion_(ubicacion), tematica_(tematica), duracion_minutos_(duracion_minutos), aforo_(aforo), precio_entrada_(precio_entrada), estado_(estado), director_(director)
		{};


		//SETTERS:

			void setID(int i){
				id_=i;
			}

			void setTitulo(std::string s1){
				titulo_=s1;
			}

			void setTematica(std::string s2){
				tematica_=s2;
			}

			void setDescripcion(std::string s3){
				descripcion_=s3;
			}

			void setUbicacion(std::string s4){
				ubicacion_=s4;
			}

			void setFechaFin(int i2){
				//TODO
				//fecha_fin_=i2;
			}

			void setFechaInicio(int i3){
				//TODO
				//fecha_inicio_=i3;
			}

			void setDuracionMinutos(int i4){
				duracion_minutos_=i4;
			}

			void setAforo(int i5){
				aforo_=i5;
			}

			void setPrecio(int i6){
				precio_entrada_=i6;
			}

			void setPonentes(std::string s){
				ponentes_.push_back(s);
			}
			void deletePonentes(std::string s){

				for (auto i = ponentes_.begin(); i != ponentes_.end(); i++)
				{
					if(*i == s){
						i=ponentes_.erase(i);
						break;
					}
				}

			}
			void setEstado(ActividadStatus e){
				estado_=e;
			}

			void setDirector(std::string d) {
				director_ = d;
			}

		//GETTERS:

			int getID(){
				return id_;
			}

			std::string getTitulo(){
				return titulo_;
			}

			std::string getDescripcion(){
				return descripcion_;
			}

			std::string getPonentes(){
				for (auto i=ponentes_.begin(); i!=ponentes_.end(); i++)
				{
					return (*i);
				}

			}

			int getAforo(){
				return aforo_;
			}

			std::string getUbicacion(){
				return ubicacion_;
			}

			std::string getTematica(){
				return tematica_;
			}

			float getPrecio(){
				return precio_entrada_;
			}

			string getFechaInicio(){
				string fecha;

				// TODO: pasar fecha a string

				return fecha;
			}

			string getFechaFin(){
				string fecha;

				//TODO: pasar fecha a string

				return fecha;
			}

			int getDuracion(){
				return duracion_minutos_;
			}
			ActividadStatus getEstado(){
				return estado_;
			}

			string getDirector() {
				return director_;
			}

			std::string getDatos(){
				std::string estadostring;
				switch (estado_)
				{
				case PENDIENTE:
					estadostring="Pendiente";
					break;

				case PASADA:
					estadostring="Pasada";
					break;

				case CANCELADA:
					estadostring="Cancelada";
					break;
				}

				return std::string("Actividad: \n") + "Estado: " + estadostring + "Aforo: " + std::to_string(aforo_) + "Precio: " +  std::to_string(precio_entrada_) + "Fecha inicio: " + getFechaInicio() + "Fecha final: " + getFechaFin() + "Titulo: " + titulo_ + "Descripcion: " + descripcion_ + "Ubicacion: " + ubicacion_;
			}
};

#endif
