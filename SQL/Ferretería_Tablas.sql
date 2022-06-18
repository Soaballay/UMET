CREATE DATABASE Ferreteria
GO

CREATE TABLE dbo.tbl_Articulo(
	idArticulo int IDENTITY(1,1) NOT NULL,
	Descripcion nvarchar(100) NOT NULL,
	FechaAlta smalldatetime NOT NULL,
	FechaBaja smalldatetime NULL,
 
	CONSTRAINT PK_idArticulo PRIMARY KEY (idArticulo)
);
GO

CREATE TABLE dbo.tbl_Proveedor(
	idProveedor int IDENTITY(1,1) NOT NULL,
	CUIT char(11) NOT NULL,
	RazonSocial nvarchar(50) NOT NULL,
	FechaAlta smalldatetime NOT NULL,
	FechaBaja smalldatetime NULL,
 
	CONSTRAINT PK_idProveedor PRIMARY KEY (idProveedor)
);
GO

CREATE TABLE dbo.tbl_ProveedorArticulo(
	idProveedor int NOT NULL,
	idArticulo int NOT NULL,
	FechaAlta smalldatetime NOT NULL,
	FechaBaja smalldatetime NULL,

	CONSTRAINT PK_idProveedoridArticulo PRIMARY KEY (idProveedor,idArticulo),

	CONSTRAINT FK_ArticuloProveedorArticulo
	FOREIGN KEY (idProveedor) REFERENCES tbl_Proveedor(idProveedor),

	CONSTRAINT FK_ProveedorProveedorArticulo
	FOREIGN KEY (idArticulo) REFERENCES tbl_Articulo(idArticulo)
);
GO

CREATE TABLE tbl_Empleado(
	Legajo int IDENTITY(1,1) NOT NULL,
	Apellido nvarchar(50) NOT NULL,
	Nombre nvarchar(50) NOT NULL,
	SueldoBruto smallmoney NOT NULL,
	FechaIngreso smalldatetime NOT NULL,
	FechaAlta smalldatetime NOT NULL,
	FechaBaja smalldatetime NULL,

	CONSTRAINT PK_Legajo PRIMARY KEY(Legajo)
)

CREATE TABLE dbo.tbl_Cliente(
	idCliente int IDENTITY(1,1) NOT NULL,
	CUIT char(11) NOT NULL,
	Apellido nvarchar(50) NOT NULL,
	Nombre nvarchar(50) NOT NULL,
	FechaAlta smalldatetime NOT NULL,
	FechaBaja smalldatetime NULL,
 
	CONSTRAINT PK_idCliente PRIMARY KEY (idCliente)
);
GO

CREATE TABLE dbo.tbl_FacturaEncabezado(
	NroFactura int IDENTITY(1,1) NOT NULL,
	Legajo int NOT NULL,
	idCliente int NOT NULL,
	Fecha datetime NOT NULL,
 
	CONSTRAINT PK_NroFactura PRIMARY KEY (NroFactura),

	CONSTRAINT FK_FacturaEncabezadoEmpleado
	FOREIGN KEY (Legajo) REFERENCES tbl_Empleado(Legajo),

	CONSTRAINT FK_FacturaEncabezadoCliente
	FOREIGN KEY (idCliente) REFERENCES tbl_Cliente(idCliente)
);
GO

CREATE TABLE dbo.tbl_FacturaRenglon(
	NroFactura int NOT NULL,
	idArticulo int NOT NULL,
	Cantidad int NOT NULL,
	PrecioUnit money NOT NULL,

	CONSTRAINT PK_NroFacturaidArticuloCantidadPrecioUnit PRIMARY KEY (NroFactura,idArticulo,Cantidad,PrecioUnit),

	CONSTRAINT FK_FacturaRenglonFacturaEncabezado
	FOREIGN KEY (NroFactura) REFERENCES tbl_FacturaEncabezado(NroFactura),

	CONSTRAINT FK_FacturaRenglonArticulo
	FOREIGN KEY (idArticulo) REFERENCES tbl_Articulo(idArticulo)
);
GO