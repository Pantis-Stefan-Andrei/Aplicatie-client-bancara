create trigger adaugaSold
on Conturi
after insert
as 
begin
	
	update Conturi
	set sold_curent=0
	where id_cont=(select I.id_cont from inserted as I)
END


UPDATE Conturi
SET sold_curent=100