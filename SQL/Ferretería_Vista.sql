CREATE VIEW vw_ArticulosPorProveedor
AS
SELECT
	art.idArticulo 'Id Articulo',
	art.Descripcion 'Desc. Art.',
	prv.idProveedor 'Id Proveedor',
	prv.RazonSocial 'Razón Social',
	prv.CUIT 'CUIT',
	prv.FechaAlta 'Alta Proveedor'
FROM
	tbl_Articulo art
		INNER JOIN tbl_ProveedorArticulo ap ON art.idArticulo = ap.idArticulo
		INNER JOIN tbl_Proveedor prv ON prv.idProveedor = ap.idProveedor

GO