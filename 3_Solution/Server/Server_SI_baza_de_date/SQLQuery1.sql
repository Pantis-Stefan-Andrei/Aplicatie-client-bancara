﻿ALTER TABLE IBANuri 
ADD CONSTRAINT fk_clientiban
foreign key (id_cont)
references conturi (id_cont)
on delete cascade
ALTER TABLE carduri 
ADD CONSTRAINT fsak_clientiban
foreign key (id_cont)
references conturi (id_cont)
on delete cascade
ALTER TABLE amenzi
ADD CONSTRAINT fdasdk_clientiban
foreign key (id_cont)
references conturi (id_cont)
on delete cascade
ALTER TABLE DEPOZITE
ADD CONSTRAINT fksada_clientiban
foreign key (id_cont)
references conturi (id_cont)
on delete cascade
ALTER TABLE Tranzactii
ADD CONSTRAINT sadad_clientiban
foreign key (id_iban1)
references IBANuri (id_iban)
on delete cascade
ALTER TABLE Tranzactii
ADD CONSTRAINT sadadsda_clientiban
foreign key (id_iban2)
references IBANuri (id_iban)
on delete cascade
delete from conturi
ALTER TABLE Conturi
ADD CONSTRAINT pk_telu
UNIQUE ( nr_telefon);
ALTER TABLE Conturi
ADD CONSTRAINT pk_cnp
UNIQUE ( cnp);
ALTER TABLE Conturi
ADD CONSTRAINT pk_email
UNIQUE ( email);
ALTER TABLE Conturi
ADD CONSTRAINT pk_user
UNIQUE ( username);
