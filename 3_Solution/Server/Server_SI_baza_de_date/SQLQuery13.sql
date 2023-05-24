-- Add cascade delete to foreign key constraints
ALTER TABLE IBANuri
ADD CONSTRAINT fk_clientiban
FOREIGN KEY (id_cont)
REFERENCES conturi (id_cont)
ON DELETE CASCADE;

ALTER TABLE carduri
ADD CONSTRAINT fsak_clientiban
FOREIGN KEY (id_cont)
REFERENCES conturi (id_cont)
ON DELETE CASCADE;

ALTER TABLE amenzi
ADD CONSTRAINT fdasdk_clientiban
FOREIGN KEY (id_cont)
REFERENCES conturi (id_cont)
ON DELETE CASCADE;

ALTER TABLE DEPOZITE
ADD CONSTRAINT fksada_clientiban
FOREIGN KEY (id_cont)
REFERENCES conturi (id_cont)
ON DELETE CASCADE;

ALTER TABLE Tranzactii
ADD CONSTRAINT sadad_clientiban
FOREIGN KEY (id_iban1)
REFERENCES IBANuri (id_iban)
ON DELETE CASCADE;

ALTER TABLE Tranzactii
ADD CONSTRAINT sadadsda_clientiban
FOREIGN KEY (id_iban2)
REFERENCES IBANuri (id_iban)
ON DELETE CASCADE;

-- Delete from Conturi table (cascading delete will be triggered)
DELETE FROM Conturi;

CREATE TRIGGER verify_id_trigger
ON Conturi
AFTER INSERT, UPDATE
AS
BEGIN
  ALTER TABLE  Conturi
DROP CONSTRAINT PK_Conturi;
UPDATE Conturi
SET id_cont= 100
WHERE id_cont = 1;
ALTER TABLE Conturi
ADD CONSTRAINT PK_Conturi PRIMARY KEY (id_cont);
 
END;
DROP TRIGGER verify_id_trigger ;

DBCC CHECKIDENT ('Conturi', RESEED, 1);
DBCC CHECKIDENT ('TableName', RESEED, 1);


INSERT INTO IBANuri (id_cont,iban)values (1028,'asdad112321');
DELETE IBANuri

INSERT INTO IBANuri (id_cont,iban)values (1028,'asdad112321');