CREATE TRIGGER TR_updateamenzi
ON amenzi
AFTER DELETE 
AS
BEGIN
    DECLARE @sum DECIMAL(10, 2);
    SELECT @sum = SUM(valoare) FROM deleted;
    
    UPDATE Conturi
    SET sold_curent = sold_curent - @sum;
END;