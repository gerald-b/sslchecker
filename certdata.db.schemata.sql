BEGIN TRANSACTION;
CREATE TABLE "tbl_validdates" (
	`id_validdates`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`fk_certs`	INTEGER,
	`validfromy`	INTEGER,
	`validfromm`	INTEGER,
	`validfromd`	INTEGER,
	`validtoy`	INTEGER,
	`validtom`	INTEGER,
	`validtod`	INTEGER,
	`status`	INTEGER
);
CREATE TABLE "tbl_hosts" (
	`id_hosts`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`fk_certs`	INTEGER,
	`hostname`	TEXT,
	`status`	INTEGER
);
CREATE TABLE "tbl_domains" (
	`id_domains`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`fk_certs`	INTEGER,
	`domainname`	TEXT,
	`status`	INTEGER
);
CREATE TABLE "tbl_certs" (
	`id_cert`	INTEGER PRIMARY KEY AUTOINCREMENT,
	`certname`	TEXT,
	`status`	INTEGER
);
COMMIT;
