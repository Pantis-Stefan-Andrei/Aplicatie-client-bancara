GO
create trigger adaugadobanda
on DEPOZITE
after insert
as 
begin
	
	update DEPOZITE
	set dobanda=19
	where id_depozit=(select I.id_depozit from inserted as I)
END

update DEPOZITE
	set dobanda=19
	where id_depozit=2002


	GO
create trigger adaugaSold2
on Conturi
after insert
as 
begin
	
UPDATE Conturi
SET sold_curent = D.suma
FROM Conturi C
INNER JOIN DEPOZITE D ON C.id_cont = D.id_cont
WHERE C.id_cont = (SELECT I.id_cont FROM inserted AS I);
END

INSERT INTO Tranzactii (id_iban1,id_iban2,suma,cheie)values(2044,1,500,'sdaad');


SELECT *
FROM Tranzactii AS T
INNER JOIN IBANuri as I
ON I.id_iban=T.id_iban1
INNER JOIN IBANuri as IA
ON IA.id_iban=T.id_iban2
INNER JOIN Conturi AS C
ON IA.id_cont=C.id_cont
WHERE I.id_cont=1028;