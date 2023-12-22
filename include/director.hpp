#ifndef __DIRECTOR_HPP__
#define __DIRECTOR_HPP__

#include <string>
#include <iostream>
#include <actividad.hpp>

using std::cout;
using std::cin;
using std::getline;

class DirectorAcademico: public UsuarioRegistrado{

public:

	// Constructores
	DirectorAcademico(){};

	DirectorAcademico(UsuarioRegistrado user)
	{
		set_username(user.username());
		set_dni(user.dni());
	};

	void modificarInfoActividad(Actividad &a){
			//HACER UN SWITCH CASE PARA PREGUNTAR QUE HAY QUE MODIFICAR
		std::string titulo, ubicacion, tematica, descripcion, ponente;
		int fecha_inicio,fecha_fin,duracion, selec_po, n_ponentes, eleccion,aforo,status;
		float precio;

		cout << "\n\n\t---------------------------------------" << endl;
		cout << "\t\t\tMENU" << endl;
		cout << "\t---------------------------------------" << endl;
		cout<<"\n\t1. Título:"<<endl;
		cout<<"\t2. Ubicación"<<endl;
		cout<<"\t3. Descripción"<<endl;
		cout<<"\t4. Ponentes"<<endl;
		cout<<"\t5. Temática"<<endl;
		cout<<"\t6. Fecha de inicio"<<endl;
		cout<<"\t7. Fecha final"<<endl;
		cout<<"\t8. Duración:"<<endl;
		cout<<"\t9. Precio"<<endl;
		cout<<"\t10. Aforo"<<endl;
		cout<<"\t11. Estado"<<endl;
		cout<<"\t0. Salir"<<endl;
		cout<<"\n\t ¿Qué desea modificar?: ";

		std::cin >> eleccion;
		cin.clear();
		cin.ignore();

		switch (eleccion)
		{
			case 1:
				cout<<"\n\tIntroduzca el título de la actividad: ";
				getline(cin, titulo);
				a.setTitulo(titulo);
				break;

			case 2:
				cout<<"\n\tIntroduzca la ubicación de la actividad: ";
				getline(cin, ubicacion);
				a.setUbicacion(ubicacion);
				break;

			case 3:
				cout<<"\n\tIntroduzca la descripcion de la actividad:";
				getline(cin, descripcion);
				a.setDescripcion(descripcion);
				break;

			case 4:
				cout<<"1. Añadir"<<endl;
				cout<<"2. Borrar"<<endl;
				std::cin>>selec_po; //para seleccionar opcion
				switch (selec_po)
				{
					case 1:
						cout<<"Cuantos ponentes va a añadir:"<<endl;
						std::cin>>n_ponentes;

						for (int i = 0; i < n_ponentes; i++)
						{
							cout<<"Nombre del ponente:"<<endl;
							std::cin>>ponente;
							a.setPonentes(ponente);
						}

					break;

					case 2:
						cout<<"Que ponente desea eliminar:"<<endl;
						std::cin>>ponente;
						a.deletePonentes(ponente);
					break;

				default:
					break;
				}

			break;

			case 5:
				cout<<"\n\tIntroduzca la tematica de la actividad:";
				getline(cin, tematica);
				a.setTematica(tematica);
			break;

			case 6:
				cout<<"\n\tIntroduzca la fecha del final de la actividad"<<endl;
				std::cin>>fecha_inicio;
				a.setFechaInicio(fecha_inicio);
			break;

			case 7:
				cout<<"\n\tIntroduzca la fecha del final de la actividad"<<endl;
				std::cin>>fecha_fin;
				a.setFechaFin(fecha_fin);
			break;

			case 8:
				cout<<"\n\tIntroduzca la duración de la actividad"<<endl;
				std::cin>>duracion;
				a.setDuracionMinutos(duracion);
			break;

			case 9:
				cout<<"\n\tIntroduzca el nuevo precio de la actividad"<<endl;
				std::cin>>precio;
				a.setPrecio(precio);
			break;

			case 10:
				cout<<"\n\tIntroduzca el nuevo aforo de la actividad"<<endl;
				std::cin>>aforo;
				a.setAforo(aforo);
			break;

			case 11:
				cout<<"\n\tIntroduzca el nuevo estado de la actividad:"<<endl;
				cout<<"1. PENDIENTE"<<endl;
				cout<<"2. PASADA"<<endl;
				cout<<"3. CANCELADA"<<endl;
				std::cin>>status;
				switch (status)
				{
				case 1:
					a.setEstado(PENDIENTE);
					break;
				case 2:
					a.setEstado(PASADA);
				break;
				case 3:
					a.setEstado(CANCELADA);
				break;

				default:
					cout<<"ERROR"<<endl;
				}

				case 0:
					cout << "Ha seleccionado salir" << endl;
					break;
			default:
				cout<<"ERROR!"<<endl;
			break;

		}
	}
};

#endif
