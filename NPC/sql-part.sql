CREATE TABLE `current_event` (
id TINYINT ( 2 ) NOT NULL AUTO_INCREMENT,
event VARCHAR ( 30 ) NOT NULL DEFAULT 'No events',
PRIMARY KEY ( `id` )
);

INSERT INTO current_event ( id, event ) VALUES ( 1, 'No Event' );

CREATE TABLE `daily_winners` (
id TINYINT ( 2 ) NOT NULL AUTO_INCREMENT,
event VARCHAR ( 30 ) NOT NULL DEFAULT 'event',
winner VARCHAR ( 30 ) NOT NULL DEFAULT 'winner',
PRIMARY KEY ( `id` )
);

INSERT INTO daily_winners ( event, winner ) VALUES ( 'RFYL', '' );