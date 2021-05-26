
#include <iostream>
#include <stdlib.h>
#include <mysql.h>
#include <string>
#include "conexion.h"
#include "tablas.h"
using namespace std;
int main()
{
	string nombre, apellido, genero,correo;
	int telefono=0, nit=0;
	conexion cn = conexion();
	if (cn.getconexion()) {
		cout <<"conexion exitosa"<<endl;	
		int opcion;
		cout << "QUE OPCIONES DESEA REALIZAR  EN LA TABLA CLIENTES" <<endl;
		 cout << "1. agregar datos" << endl;
		  cout << "2. borrar datos" << endl;
		   cout << "3. Ver datos actualizados de la tabla" << endl;
		    
		   cin >> opcion;
		   tablas tb = tablas(nombre, apellido, genero, correo, telefono, nit);
		switch (opcion)
		{
		case 1:
			
			tb.pedir();
			tb.ingresar();
			break;
		case 2: 
			tb.eliminar();
			break;
		case 3:
			tb.mostrar();
			break;
		
		default:
			cout << "opcion invalida " << endl;
			return main();
			break;
		}
	
	}
	else 
	{
		cout << "no conecto" << endl;
	}
	cn.cerrarcone();
	

   system("pause");
   return 0;
}

