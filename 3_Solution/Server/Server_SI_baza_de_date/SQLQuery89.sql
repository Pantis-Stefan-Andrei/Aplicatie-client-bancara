DROP TRIGGER  TR_updateamenzi
CREATE TRIGGER TR_updateamenzi
ON amenzi
AFTER DELETE 
AS
BEGIN
    DECLARE @sum DECIMAL(10, 2);
    SELECT @sum = SUM(valoare) FROM deleted;
    DECLARE @id DECIMAL(10, 2);
    SELECT @id = SUM(id_cont) FROM deleted;
    
    UPDATE Conturi
    SET sold_curent = sold_curent - @sum
    where @id=id_cont;
END;

 UPDATE Conturi
    SET sold_curent =1000

