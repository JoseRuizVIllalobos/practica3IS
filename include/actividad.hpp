#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>

using std::string;

enum class ActividadStatus{
	PENDIENTE,
	PASADA,
	CANCELADA
};

class Actividad{

	private:
		int id_ = 0;
		tm *fecha_inicio_ = nullptr; //no se que tipo de dato es date, lo he puesto con ints
		tm *fecha_fin_ = nullptr;
		int duracion_minutos_ = -1;
		int aforo_ = -1;
		std::string nombre_;
		std::string tematica_;
		std::string descripcion_;
		std::string ubicacion_;
		std::string titulo_;
		float precio_entrada_ = 0;
		std::list<std::string> ponentes_;
		ActividadStatus estado_;
	public:
		//CONSTRUCTORES:
		Actividad():estado_(ActividadStatus::PENDIENTE){};

		Actividad(int id, int fecha_fin, int fecha_inicio, int duracion_minutos, int aforo, std::string nombre, std::string tematica, std::string descripcion, std::string ubicacion, std::string titulo, float precio_entrada, ActividadStatus estado){
			id_=id;
			//fecha_fin_=fecha_fin;
			//fecha_inicio_=fecha_inicio;
			duracion_minutos_=duracion_minutos;
			aforo_=aforo;
			tematica_=tematica;
			descripcion_=descripcion;
			ubicacion_=ubicacion;
			titulo_=titulo;
			precio_entrada_=precio_entrada;
			nombre_=nombre;
			estado_=estado;
		}
		//SETTERS:

			void setID(int i){
				id_=i;
			}
			void setNombre(std::string s){
				nombre_=s;
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
		//GETTERS:

			int getID(){
				return id_;
			}

			std::string getNombre(){
				return nombre_;
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

			std::string getDatos(){
				std::string estadostring;
				switch (estado_)
				{
				case ActividadStatus::PENDIENTE:
					estadostring="Pendiente";
					break;
				case ActividadStatus::PASADA:
					estadostring="Pasada";
					break;
				case ActividadStatus::CANCELADA:
					estadostring="Cancelada";
					break;
				}

				return std::string("Actividad: \n")+ nombre_ + "\n" + "Estado: " + estadostring + "Aforo: " + std::to_string(aforo_) + "Precio: " +  std::to_string(precio_entrada_) + "Fecha inicio: " + getFechaInicio() + "Fecha final: " + getFechaFin() + "Titulo: " + titulo_ + "Descripcion: " + descripcion_ + "Ubicacion: " + ubicacion_;
			}
};

#endif