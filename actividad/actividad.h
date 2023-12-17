#ifndef ACTIVIDAD_H
    #define ACTIVIDAD_H
    #include <stdio.h>
    #include <iostream>
    #include <string>
    #include <list>
    class Actividad{

        private:
            int id_;
            int fecha_inicio_; //no se que tipo de dato es date, lo he puesto con ints
            int fecha_fin_;
            int duracion_minutos_;
            int aforo_;
            std::string tematica_;
            std::string descripcion_;
            std::string ubicacion_;
            std::string titulo_;
            float precio_entrada_;
            std::list<std::string> ponentes_;
        public:
            //CONSTRUCTOR:
            Actividad(int id, int fecha_fin, int fecha_inicio, int duracion_minutos, int aforo, std::string tematica, std::string descripcion, std::string ubicacion, std::string titulo, float precio_entrada){
                id_=id;
                fecha_fin_=fecha_fin;
                fecha_inicio_=fecha_inicio;
                duracion_minutos_=duracion_minutos;
                aforo_=aforo;
                tematica_=tematica;
                descripcion_=descripcion;
                ubicacion_=ubicacion;
                titulo_=titulo;
                precio_entrada_=precio_entrada;
            }
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
                    fecha_fin_=i2;
                }

                void setFechaInicio(int i3){
                    fecha_inicio_=i3;
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

                int FechaInicio(){
                    return fecha_inicio_;
                }

                int getFechaFin(){
                    return fecha_fin_;
                }

                int getDuracion(){
                    return duracion_minutos_;
                }















    };

#endif