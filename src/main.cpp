#include <iostream>
#include <usuarioregistrado.hpp>

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
	UsuarioRegistrado user;

	try {
		user.set_dni("31019261N");
		user.set_sexo("HoMbre");

		cout << user.sexo() << endl;
	}
	catch(AppException &e) {
		cerr << e.what() << endl;
	}

	return 0;
}
