CREATE DATABASE photojournalist;

CREATE TABLE if not exists services(
    type_service varchar(32) NOT NULL,
    name_service varchar(32) NOT NULL,
    service_price decimal NOT NULL,
    commentary text,
    PRIMARY KEY(name_service)
);

CREATE TABLE if not exists users(
    users_ID INT NOT NULL AUTO_INCREMENT,
    users_surname varchar(32) NOT NULL,
    users_name varchar(32) NOT NULL,
    users_middle_name varchar(32) NOT NULL,
    phone_number char(13) NOT NULL,
    PRIMARY KEY(ID)
);

CREATE TABLE if not exists order_data(
    order_ID INT NOT NULL AUTO_INCREMENT,
    creation_date date NOT NULL,
    finalization_date date NOT NULL,
    order_amount int,
    orders text,
    adress text,
    order_price decimal,
    order_status varchar(16),
    PRIMARY KEY(order_ID)
);