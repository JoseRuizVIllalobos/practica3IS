#ifndef ESTADISTICAS_H
    #define ESTADISTICAS_H
    #include <actividad.hpp>
    class Estadisticas{

        private:
            int numero_inscripciones_;
            int asistencia_;
            float recaudacion_;
            float valoracion_;
        public:
            //he tenido que borrar algunas funciones como la de valoracion, quitaria tambien recaudacion total, ya que en el momento en el que te inscribes pagas

            Estadisticas(int numero_inscripciones, int asistencia, float recaudacion, float valoracion){
                numero_inscripciones_=numero_inscripciones;
                asistencia_=asistencia;
                recaudacion_=recaudacion;
                valoracion_=valoracion;
            }


            void setInscripciones(int n){
                numero_inscripciones_=n;
            }
            void setAsistencia(int a){
                asistencia_=a;
            }
            void addRecaudacion(Actividad a){
                
                recaudacion_=(numero_inscripciones_*a.getPrecio());
            }

            int getPorcentajeAsistencia(){
                float porcent=0;
                porcent=(asistencia_/numero_inscripciones_)*100;
                return porcent;
            }

            int getRecaudacionTotal(){
                return recaudacion_;
            }

            int getInscripciones(){
                return numero_inscripciones_;
            }

            int getAsistencia(){
                return asistencia_;
            }

            std::string getEstadisticas(Actividad a){
                return std::string("Estadisticas de: ") + a.getNombre() + "\n" + "Inscripciones: " + std::to_string(numero_inscripciones_) + "Asistencia: " + std::to_string(asistencia_) + "Recaudación: " + std::to_string(recaudacion_);  
            }

    };


#endif
