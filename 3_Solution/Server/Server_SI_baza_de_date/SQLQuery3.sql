CREATE TRIGGER TR_adaugaVirament
ON amenzi
AFTER DELETE 
AS 
BEGIN
	
    
    DECLARE sum DECIMAL(10, 2);
    SELECT sum(SUM(suma)) INTO sum FROM deleted;

    -- Update the 'sold' column in 'Conturi' table by subtracting the sum of 'suma'
    UPDATE Conturi
    SET sold_curent = sold_curent- sum;
    -- Replace 'Conturi' with the appropriate table name for your case

END
