CREATE DATABASE photojournalist;

CREATE TABLE if not exists services(
    type_service varchar(32) NOT NULL,
    name_service varchar(32) NOT NULL,
    service_price decimal NOT NULL,
    commentary text,
    FOREIGN KEY(name_service) REFERENCES order_data(orders)
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
    order_amount int NOT NULL,
    orders text NOT NULL,
    adress text NOT NULL,
    order_price decimal NOT NULL,
    order_status varchar(16) NOT NULL,
    PRIMARY KEY(order_ID)
);

CREATE TABLE if not exists unsers_services(
    users_ID INT NOT NULL,
    order_price INT NOT NULL,
    FOREIGN KEY(users_ID) REFERENCES users(users_ID),
    FOREIGN KEY(order_ID) REFERENCES order_data(order_ID)
);