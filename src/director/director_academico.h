#include <string>
#include <iostream>
#include "actividad.h"
class DirectorAcademico{

    public:

        void modificarInfoActividad(Actividad a){
                //HACER UN SWITCH CASE PARA PREGUNTAR QUE HAY QUE MODIFICAR
            std::string nombre,ubicacion, tematica, descripcion,ponente;
            int fecha_inicio,fecha_fin,duracion, selec_po, n_ponentes, eleccion,aforo;
            float precio;



            std::cout<<"Seleccione lo que desea cambiar:"<<std::endl;
            std::cout<<"1. Nombre:"<<std::endl;
            std::cout<<"2.Ubicacion"<<std::endl;
            std::cout<<"3.Descripcion"<<std::endl;
            std::cout<<"4.Ponentes"<<std::endl;
            std::cout<<"5.Tematica"<<std::endl;
            std::cout<<"6.Fecha de inicio"<<std::endl;
            std::cout<<"7.Fecha final"<<std::endl;
            std::cout<<"8.Duracion:"<<std::endl;
            std::cout<<"9.Precio"<<std::endl;
            std::cout<<"10.Aforo"<<std::endl;

            std::cin>>eleccion;
            switch (eleccion)
            {
                case 1:
                    std::cout<<"Introduzca el nombre de la actividad"<<std::endl;
                    std::cin>>nombre;
                    a.setNombre(nombre);

                break;

                case 2:
                    std::cout<<"Introduzca la ubicación de la actividad"<<std::endl;
                    std::cin>>ubicacion;
                    a.setUbicacion(ubicacion);

                break;
                case 3:
                    std::cout<<"Introduzca la descripcion de la actividad"<<std::endl;
                    std::cin>>descripcion;
                    a.setDescripcion(descripcion);
                break;        
                case 4:
                    std::cout<<"1. Añadir"<<std::endl;
                    std::cout<<"2. Borrar"<<std::endl;                     
                    std::cin>>selec_po; //para seleccionar opcion
                    switch (selec_po)
                    {
                        case 1: 
                            std::cout<<"Cuantos ponentes va a añadir:"<<std::endl;
                            std::cin>>n_ponentes;
                            for (int i = 0; i < n_ponentes; i++)
                            {
                                std::cout<<"Nombre del ponente:"<<std::endl;
                                std::cin>>ponente;
                                a.setPonentes(ponente);
                            }
                            
                        break;

                        case 2:
                            std::cout<<"Que ponente desea eliminar:"<<std::endl;
                            std::cin>>ponente;
                            a.deletePonentes(ponente);
                        break;
                    
                    default:
                        break;
                    }
                    
                break;            
                case 5:
                    std::cout<<"Introduzca la tematica de la actividad"<<std::endl;
                    std::cin>>tematica;
                    a.setTematica(tematica);
                break;
                case 6:
                    std::cout<<"Introduzca la fecha del final de la actividad"<<std::endl;
                    std::cin>>fecha_inicio;
                    a.setFechaInicio(fecha_inicio);
                break;
                case 7:
                    std::cout<<"Introduzca la fecha del final de la actividad"<<std::endl;
                    std::cin>>fecha_fin;
                    a.setFechaFin(fecha_fin);
                break;
                case 8:
                    std::cout<<"Introduzca la duración de la actividad"<<std::endl;
                    std::cin>>duracion;
                    a.setDuracionMinutos(duracion);
                break;
                case 9:
                    std::cout<<"Introduzca el nuevo precio de la actividad"<<std::endl;
                    std::cin>>fecha_fin;    
                    a.setPrecio(precio);
                break;
                case 10:
                    std::cout<<"Introduzca el nuevo aforo de la actividad"<<std::endl;
                    std::cin>>aforo;    
                    a.setAforo(aforo);
                break;
                default:
                    std::cout<<"ERROR!"<<std::endl;

            }
                





            
            

            
            

            
            


            

            

        }



};