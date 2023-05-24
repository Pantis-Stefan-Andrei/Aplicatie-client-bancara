CREATE TRIGGER repair_order_trigger
AFTER DELETE ON Conturi
FOR EACH ROW
BEGIN
  -- Variable to hold the next ID value
  DECLARE next_id INT;

  -- Find the maximum ID value in the table
  SELECT MAX(id) INTO next_id FROM orders;

  -- If there are no rows left in the table, set next_id to 1
  IF next_id IS NULL THEN
    SET next_id = 1;
  END IF;

  -- Update the auto-increment value to the next ID
  SET @sql = CONCAT('ALTER TABLE orders AUTO_INCREMENT = ', next_id + 1);
  PREPARE stmt FROM @sql;
  EXECUTE stmt;
  DEALLOCATE PREPARE stmt;
END;
INSERT INTO amenzi (nume,descriere,data_primirii,id_cont) values ('adsad','wdadsaadwa','12dqasd',1026);

INSERT INTO Tranzactii(id_iban1,id_iban2,suma,cheie) values (2031,2033,1992,'32deqwwsq');


SELECT C.nume,C.prenume,IA.iban,T.suma
FROM Tranzactii AS T
INNER JOIN IBANuri as I
ON I.id_iban=T.id_iban1
INNER JOIN IBANuri as IA
ON IA.id_iban=T.id_iban2
INNER JOIN Conturi AS C
ON IA.id_cont=C.id_cont
WHERE I.id_cont=1017;
  