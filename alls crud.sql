Create database crud;
use crud;
create table clientes(
Id_clientes int primary key auto_increment not null,
nombres varchar(50)not null,
apellidos varchar(50) not null,
nit int not null,
genero varchar(50)not null,
telefon varchar(50) not null,
correo varchar(50) not null,
fecha datetime not null
);
select *from clientes;

create table ventas(
Id_ventas int primary key auto_increment not null,
No_factura int not null,
serie varchar(20) not null,
fecha_factura date not null,
Id_clientes int, constraint FK_Id_clientes foreign key (Id_clientes) references clientes(Id_clientes) ,
fecha_ingreso datetime not null

);
select *from ventas;
create table empleados (
Id_empleado int primary key auto_increment not null,
nombre varchar(50) not null,
apellido varchar (50)not null,
direccion varchar (50)not null,
telefono int not null,
DPI int not null,
genero varchar(50) not null,
fecha_nacimiento date not null,
Id_puesto int,constraint FK_Id_puesto foreign key (Id_puesto) references puesto(Id_puesto),
fecha_inicio_labores date not null,
fecha_ingreso datetime not null
);
create table puesto(
Id_puesto int primary key auto_increment not null,
puesto varchar(50)not null
);
create table ventas_detalle(
Id_ventas_detalle int primary key auto_increment not null,
Id_ventas int, constraint FK_Id_ventas foreign key(Id_ventas) references ventas(Id_ventas),
cantidad varchar(50) not null,
precio_unitario decimal(8,2) not null
);
create table productos(
Id_productos int primary key auto_increment not null,
producto varchar(60)not null,
descripcion varchar(60)not null,
imagen varchar(50)not null,
precio_costo decimal(8,2) not null,
precio_venta decimal (8,2)not null,
existencia int not null,
fecha_ingreso datetime,
Id_marca int, constraint FK_Id_marca foreign key (Id_marca) references marcas(Id_marca)
);
create table marcas(
Id_marca int primary key auto_increment not null,
marca varchar(50) not null
);
create table compras(
Id_compras int primary key auto_increment not null,
no_orden_compra int not null,
fecha_orden date not null,
fecha_ingreso datetime not null,
Id_proveerdor int not null
);
create table compras_detalle(
Id_compras_detalle int primary key auto_increment not null,
Id_compra int not null,
Id_producto int, constraint FK_Id_producto foreign key (Id_producto) references productos(Id_productos),
cantidad int not null,
precio_costo_unitario decimal(8,2)not null
)