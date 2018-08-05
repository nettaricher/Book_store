#include "Database.h"

Database *Database::instance = 0;

Database::Database() : driver(get_driver_instance()) {
	connection_properties["hostName"] = DB_HOST;
	connection_properties["port"] = DB_PORT;
	connection_properties["userName"] = DB_USER;
	connection_properties["password"] = DB_PASS;
	connection_properties["OPT_RECONNECT"] = true;
	
	// use database
	try {
		Connection *con = driver->connect(connection_properties);
		try {
			con->setSchema("bookstore");
		}
		catch (SQLException &e) {
			Statement *stmt = con->createStatement();
			stmt->execute(
				"CREATE DATABASE IF NOT EXISTS bookstore");
			con->setSchema("bookstore"); // switch database
			stmt->execute("CREATE TABLE IF NOT EXISTS book( "
				"book_id int unsigned auto_increment, "
				"title varchar(50) not null, "
				"author varchar(30) not null, "
				"price int unsigned not null, "
				"inStock BIT, "
				"PRIMARY KEY(book_id) "
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS customer("
				"customer_id int unsigned auto_increment, "
				"customer_name varchar(50) not null, "
				"customer_phone varchar(15) not null, "
				"customer_address varchar(100) not null, "
                "join_date DATETIME default NOW(), "
				"PRIMARY KEY(customer_id) "
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS supplier( "
				"supplier_id int unsigned auto_increment, "
				"supplier_name varchar(50) not null, "
				"supplier_phone varchar(15) not null, "
				"supplier_address varchar(100) not null, "
				"PRIMARY KEY(supplier_id) "
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS purchase( "
				"purchase_id int unsigned auto_increment, "
				"purchase_date DATETIME default NOW(), "
				"customer_id int unsigned, "
				"PRIMARY KEY(purchase_id), "
				"PRIMARY KEY(phone, country_code), "
				"FOREIGN KEY (customer_id) REFERENCES customer(customer_id) "
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS purchase_info("
				"purchase_id int unsigned, "
				"purchase_date DATETIME, "
				"book_id int unsigned, "
				"employee_id int unsigned not null, "
				"isCanceled BIT "
				"FOREIGN KEY purchase_date REFERENCES purchase(purchase_date), "
				"FOREIGN KEY purchase_id REFERENCES purchase(purchase_id), "
				"FOREIGN KEY book_id REFERENCES book(book_id), "
				"PRIMARY KEY(book_id,purchase_id) "
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS orders( "
				"order_id int unsigned auto_increment, "
				"order_date DATETIME default NOW(), "
				"_status ENUM('ordered','arrived','noticed','sold'), "
				"book_id int unsigned, "
				"supplier_id int unsigned, "
				"customer_id int unsigned, "
				"FOREIGN KEY (book_id) REFERENCES book(book_id), "
				"FOREIGN KEY (supplier_id) REFERENCES supplier(supplier_id), "
				"FOREIGN KEY (customer_id) REFERENCES customer(customer_id), "
				"PRIMARY KEY(order_id) "
				")");
            stmt->execute("CREATE TABLE IF NOT EXISTS supplied_by( "
                  "book_id int unsigned, "
                  "supplier_id int unsigned, "
                  "price int unsigned, "
                  "FOREIGN KEY (book_id) REFERENCES book(book_id), "
                  "FOREIGN KEY (supplier_id) REFERENCES supplier(supplier_id), "
                  "PRIMARY KEY (book_id, supplier_id) "
                  ")");
            stmt->execute("CREATE TABLE IF NOT EXISTS disc_global( "
                  "disc_id int unsigned auto_increment, "
                  "info varchar(50), "
                  "start_date DATE not null, "
                  "end_date DATE not null, "
                  "amount decimal(3,2), "
                  "PRIMARY KEY (disc_id) "
                  ")");
			delete stmt;
		}

		delete con;
	}
	catch (SQLException &e) {
		cout << e.getErrorCode() << " " << e.what() << " " << e.getSQLState();
	}
}

Database & Database::getInstance() {
	if (Database::instance == 0) {
		instance = new Database();
	}
	return *instance;
}

Connection * Database::getConnection() {
	try {
		Connection *con = driver->connect(connection_properties);
		con->setSchema(DB_NAME);
		return con;
	} catch (SQLException &e) {
		cout << e.what();
	}
	return 0;
}
