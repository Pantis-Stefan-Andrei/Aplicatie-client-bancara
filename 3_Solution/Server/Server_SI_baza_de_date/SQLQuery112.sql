CREATE TRIGGER TR_adaugaBani
ON DEPOZITE
AFTER INSERT
AS
BEGIN
	UPDATE CO
	SET CO.sold_curent = CO.sold_curent + I.suma
	FROM Conturi AS CO
	INNER JOIN inserted as I
	ON I.id_cont=CO.id_cont
END



CREATE TRIGGER TR_scadeVirament
ON Tranzactii
AFTER INSERT
AS
BEGIN
	UPDATE CO
	SET	CO.sold_curent=CO.sold_curent+I.suma
	FROM Conturi AS CO
	INNER JOIN IBANuri AS IB
	ON IB.id_cont=CO.id_cont
	INNER JOIN inserted as I
	ON I.id_iban2=IB.id_iban
END


IF OBJECT_ID('TR_adaugaVirament','TR') IS NOT NULL
DROP TRIGGER TR_adaugaVirament

CREATE TRIGGER TR_adaugaVirament
ON Tranzactii
INSTEAD OF INSERT
AS 
BEGIN
	DECLARE @SUMA int=(SELECT suma
						FROM inserted )
	DECLARE @Bani int=(SELECT CO.sold_curent
						FROM inserted AS I
						INNER JOIN IBANuri AS IB
						ON IB.id_iban=I.id_iban1
						INNER JOIN Conturi as CO
						ON CO.id_cont=IB.id_cont
						)
	IF(@SUMA>@Bani)
	BEGIN
		THROW 4004,'Nu sunt destui bani',0
	END
	ELSE 
	BEGIN
		INSERT INTO Tranzactii(id_iban1,id_iban2,suma)
		SELECT I.id_iban1,I.id_iban2,I.suma
		FROM inserted AS I

		UPDATE CO
		SET CO.sold_curent=CO.sold_curent-I.suma
		FROM Conturi as CO
		INNER JOIN IBANuri AS IB
		ON IB.id_cont=CO.id_cont
		INNER JOIN inserted AS I
		ON I.id_iban1=IB.id_iban
	END
END



