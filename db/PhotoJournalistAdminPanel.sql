DROP DATABASE photojournalist;
CREATE DATABASE photojournalist;
USE photojournalist;
CREATE TABLE if not exists users(
    users_ID INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT ,
    users_surname varchar(32) NOT NULL,
    users_name varchar(32) NOT NULL,
    users_middle_name varchar(32) NOT NULL,
    phone_number varchar(13) NOT NULL
);

CREATE TABLE if not exists services(
    service_ID INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT,
    name_service varchar(32) NOT NULL,
    type_service varchar(32) NOT NULL,
    service_price decimal NOT NULL,
    commentary text
);

CREATE TABLE if not exists order_data(
    order_ID INTEGER NOT NULL PRIMARY KEY AUTO_INCREMENT,
    creation_date date NOT NULL,
    finalization_date date DEFAULT NULL,
    img VARCHAR(128) DEFAULT NULL,
    adress varchar(128) NOT NULL,
    order_price INT NOT NULL,
    order_status BOOLEAN NOT NULL,
    users_ID INT NOT NULL,
    service_ID INT NOT NULL,
    FOREIGN KEY(users_ID) REFERENCES users(users_ID) ON DELETE CASCADE,
    FOREIGN KEY(service_ID) REFERENCES services(service_ID) ON DELETE CASCADE
);
