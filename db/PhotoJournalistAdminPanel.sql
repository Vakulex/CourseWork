DROP DATABASE photojournalist;
CREATE DATABASE photojournalist;
USE photojournalist;

CREATE TABLE if not exists users(
    users_ID INT NOT NULL AUTO_INCREMENT ,
    users_surname varchar(32) character set utf8 NOT NULL,
    users_name varchar(32) character set utf8 NOT NULL,
    users_middle_name varchar(32) character set utf8 NOT NULL,
    phone_number varchar(13) NOT NULL,
    PRIMARY KEY(users_ID)
);

CREATE TABLE if not exists order_data(
    order_ID INT NOT NULL AUTO_INCREMENT,
    creation_date date NOT NULL,
    finalization_date date,
    img VARCHAR(128),
    orders varchar(64) character set utf8 NOT NULL,
    adress varchar(128) character set utf8 NOT NULL,
    order_price INT NOT NULL,
    order_status boolean NOT NULL,
    users_ID INT NOT NULL,
    PRIMARY KEY(order_ID),
    FOREIGN KEY(users_ID) REFERENCES users(users_ID) ON DELETE CASCADE
);

CREATE TABLE if not exists services(
    service_id INT NOT NULL AUTO_INCREMENT,
    name_service varchar(32) character set utf8 NOT NULL,
    type_service varchar(32) character set utf8 NOT NULL,
    service_price decimal NOT NULL,
    commentary text,
    PRIMARY KEY(service_id)
);

CREATE TABLE if not exists orders_services(
    order_ID INT NOT NULL,
    service_ID INT NOT NULL,
    FOREIGN KEY(order_ID) REFERENCES order_data(order_ID),
    FOREIGN KEY(service_ID) REFERENCES services(service_ID)
);

BEGIN; 
INSERT INTO users(users_name, users_middle_name, users_surname, phone_number)
VALUES('Олексій', 'Дмитрович', 'Вакуленко', "+380965221763");
INSERT INTO order_data 
(creation_date, finalization_date, img, orders, adress, order_price, order_status, users_ID) 
VALUES('2022–10–23', '2022–11–23', LOAD_FILE('C:\Users\Dnipro\Pictures\90cc7ab9fc169b689442cfb0dd02cd68.jpg'), 'Портрет', 'Тополя', "15000", false, (SELECT users_ID from users WHERE users_ID = LAST_INSERT_ID()));
COMMIT;