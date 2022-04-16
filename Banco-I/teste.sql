create table cliente (
    cpf varchar (11) not null,
    nome varchar (20) not null,
    email varchar (30) not null,
    ntel varchar (15) not null,
    constraint pk_cliente primary key (cpf)
);