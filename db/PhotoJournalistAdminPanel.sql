CREATE DATABASE photojournalist;
USE photojournalist;

CREATE TABLE if not exists users(
    users_ID INT NOT NULL AUTO_INCREMENT,
    users_surname varchar(32) NOT NULL,
    users_name varchar(32) NOT NULL,
    users_middle_name varchar(32) NOT NULL,
    phone_number char(13) NOT NULL,
    PRIMARY KEY(users_ID)
);

CREATE TABLE if not exists users_login(
    users_ID INT NOT NULL AUTO_INCREMENT,
    users_mail varchar(320) NOT NULL,
    users_password varchar(64) NOT NULL,
    FOREIGN KEY(users_ID) REFERENCES users(users_ID)
);

CREATE TABLE if not exists order_data(
    order_ID INT NOT NULL AUTO_INCREMENT,
    creation_date date NOT NULL,
    finalization_date date,
    orders varchar(64) UNIQUE NOT NULL,
    adress text NOT NULL,
    order_price decimal NOT NULL,
    order_status varchar(16) NOT NULL,
    users_ID INT NOT NULL,
    PRIMARY KEY(order_ID),
    FOREIGN KEY(users_ID) REFERENCES users(users_ID)
);

CREATE TABLE if not exists services(
    service_id INT NOT NULL AUTO_INCREMENT,
    name_service varchar(32) NOT NULL,
    type_service varchar(32) NOT NULL,
    service_price decimal NOT NULL,
    commentary text,
    PRIMARY KEY(service_id),
    FOREIGN KEY(service_ID) REFERENCES order_data(order_ID)
);

CREATE TABLE if not exists orders_services(
    order_ID INT NOT NULL,
    service_ID INT NOT NULL,
    FOREIGN KEY(order_ID) REFERENCES order_data(order_ID),
    FOREIGN KEY(service_ID) REFERENCES services(service_ID)
);