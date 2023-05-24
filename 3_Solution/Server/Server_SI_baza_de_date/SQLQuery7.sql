insert into CARDURI(CVV,nr_card,data_expirare,id_cont) values('323','231das1','22/05/2020',1017);
insert into CARDURI(CVV,nr_card,data_expirare,id_cont) values('323','231das1','22/05/2020',1018);


alter table IBANuri
add constraint iban_2 
unique(iban);