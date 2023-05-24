insert into Tranzactii(id_iban1,id_iban2,suma,cheie) values(2024,2024,500,'212122dq');
insert into IBANuri(id_cont,iban) values(1014,'212122dq');
insert into CARDURI(CVV,nr_card,data_expirare,id_cont) values('212','212122dq','231saassa',1014);

update DEPOZITE set dobanda=10,
                  id_cont=1014
where(id_depozit=1003);

update amenzi set data_primirii='22/05/2020',
                  id_cont=1014
where(id_amenda=1008);