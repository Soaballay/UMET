CREATE PROCEDURE dbo.sp_Articulo_INS
@Descripcion nvarchar(100)
AS
INSERT INTO tbl_Articulo
    VALUES(
		@Descripcion,
        getdate(),
		NULL
	)	  
GO

CREATE PROCEDURE sp_Articulo_SEL
AS
SELECT
	idArticulo,
	Descripcion,
	FechaAlta,
	FechaModificacion,
	FechaBaja
FROM
	tbl_Articulo
GO

CREATE PROCEDURE sp_Articulo_UPD
	@idArticulo int,
	@Descripcion nvarchar(100)
AS
	UPDATE tbl_Articulo
	SET 
		Descripcion = @Descripcion
	WHERE idArticulo =  @idArticulo
GO

CREATE PROCEDURE sp_Articulo_DEL
	@idArticulo int
AS
	DELETE FROM tbl_ProveedorArticulo
	WHERE idArticulo = @idArticulo
	DELETE FROM tbl_Articulo
	WHERE idArticulo = @idArticulo
GO

CREATE PROCEDURE dbo.sp_Proveedor_INS
@CUIT [char](11),
@RazonSocial [nvarchar](50)
AS	
INSERT INTO tbl_Proveedor
    VALUES(
		@CUIT,
		@RazonSocial,
        getdate(),
		NULL
	)	  
GO

CREATE PROCEDURE sp_Proveedor_SEL
AS
SELECT
	idProveedor,
	CUIT,
	RazonSocial,
	FechaAlta,
	FechaModificacion,
	FechaBaja
FROM
	tbl_Proveedor
GO

CREATE PROCEDURE sp_Proveedor_UPD
	@idProveedor int,
	@CUIT [char](11),
	@RazonSocial [nvarchar](50)
AS
	UPDATE tbl_Proveedor
	SET 
		CUIT = @CUIT,
		RazonSocial = @RazonSocial
	WHERE idProveedor =  @idProveedor
GO

CREATE PROCEDURE sp_Proveedor_DEL
	@idProveedor int
AS
	DELETE FROM tbl_ProveedorArticulo
	WHERE idProveedor = @idProveedor

	DELETE FROM tbl_Proveedor
	WHERE idProveedor = @idProveedor
GO

CREATE PROCEDURE dbo.sp_ProveedorArticulo_INS
@idProveedor int,
@idArticulo int
AS
INSERT INTO tbl_ProveedorArticulo
    VALUES(
		@idProveedor,
		@idArticulo,
        getdate(),
		NULL
	)	  
GO

CREATE PROCEDURE sp_Empleado_INS
	@Apellido nvarchar(50),
	@Nombre nvarchar(50),
	@SueldoBruto smallmoney,
	@FechaIngreso smalldatetime
AS
INSERT INTO tbl_Empleado
    VALUES(
		@Apellido,
		@Nombre,
		@SueldoBruto,
		@FechaIngreso,
        GETDATE(),
		NULL
	)	  
GO

CREATE PROCEDURE sp_Empleado_UPD
	@Legajo int,
	@Apellido nvarchar(50),
	@Nombre nvarchar(50),
	@SueldoBruto smallmoney,
	@FechaIngreso smalldatetime
AS
UPDATE tbl_Empleado
    SET
		Apellido = @Apellido,
		Nombre = @Nombre,
		SueldoBruto = @SueldoBruto,
		FechaIngreso = @FechaIngreso,
	WHERE Legajo = @Legajo
GO