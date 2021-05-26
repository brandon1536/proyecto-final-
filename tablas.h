
#include <iostream>
#include <string.h>
#include <mysql.h>
#include "conexion.h"
using namespace std;
int q_estado=0;
class tablas
{
	//tabla clientes.
public:
	string nombre, apellido, genero,correo;
	int telefono,nit;
public:
	  tablas(string,string,string,string,int,int);
	  int ingresar();
	  int eliminar();
	 void  mostrar();
	  void actualizar();
	  void pedir();
};
tablas::tablas(string _nombre,string _apellido,string _genero,string _correo,int _telefono,int _nit) {
	nombre = _nombre;
	apellido = _apellido;
	genero = _genero;
	correo = _correo;
	telefono = _telefono;
	nit = _nit;
}
void tablas::pedir() {
	cout << "INGRESE DATOS " << endl;
	cout << "Ingrese su nombre" << endl;cin >> nombre;
	cout << "Ingrese su apellido" << endl;cin >> apellido;
	cout << "Ingrese su genero" << endl;cin >> genero;
	cout << "Ingrese su correo" << endl;cin >> correo;
	cout << "Ingrese su telefono" << endl;cin >> telefono;
	cout << "Ingrese su nit" << endl;fflush(stdin);cin >> nit;
}
int  tablas::ingresar() {
	//se insertan los datos.
	conexion cn = conexion();
	if (cn.getconexion()) {
		fflush(stdin);
		string n = to_string(nit);
		string tel = to_string(telefono);
		string insert = "Insert into clientes(nombres,apellidos,nit,genero,telefon,correo,fecha)values('"+nombre+"','"+apellido+"','"+n+"','"+genero+"','"+tel+"','"+correo+"',current_timestamp())";
		const char* i = insert.c_str();
		q_estado = mysql_query(cn.getconexion(),i);
		if (!q_estado) {
			cout << "Datos insertados" << endl;
			return q_estado;
		}
		else {
			cout << "No se logro insertar datos" << endl;
			return 0;
		}
	}
	else
	{
		cout << "No se logro hacer la conexion" << endl;
		return 0;
	}
	
	cn.cerrarcone();
}
int tablas::eliminar() {
	conexion cn = conexion();
	if (cn.getconexion()) {
		cout << "Ingrese el nombre del cliente para eliminarlo" << endl;
		cin >> nombre;
		string eliminar = "Delete from clientes where nombres='" + nombre + "'";
		const char* i = eliminar.c_str();
		q_estado = mysql_query(cn.getconexion(), i);
		if (!q_estado) {
			cout << "Los datos se eliminaron con exito" << endl;
			
		}
		else 
		{
			cout << "No se lograron eliminar los datos" << endl;
		}
		return q_estado;
	}
	else
	{
		cout << "No se logro hacer la conexion" << endl;
		return 0;
	}
	cn.cerrarcone();
}
void tablas:: mostrar() {
	conexion cn =conexion();
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	if(cn.getconexion()) {
		string consulta = "select * from crud.clientes";
		const char* c = consulta.c_str();
		q_estado= mysql_query(cn.getconexion(), c);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getconexion());
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << endl;

			}
			
		}

		else {

			cout << " --- Error al Ingresar ---" << endl;

		}

		

	}

	else {

		cout << "Error en la Conexion" << endl;
		
	}

	cn.cerrarcone();



}
void tablas::actualizar() {

}


