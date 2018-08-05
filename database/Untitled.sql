-- MySQL dump 10.13  Distrib 5.7.17, for macos10.12 (x86_64)
--
-- Host: 127.0.0.1    Database: bookstore
-- ------------------------------------------------------
-- Server version	5.7.22

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `book`
--

DROP TABLE IF EXISTS `book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `book` (
  `book_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `title` varchar(50) NOT NULL,
  `author` varchar(30) NOT NULL,
  `price` int(10) unsigned NOT NULL,
  `inStock` bit(1) DEFAULT NULL,
  `discount` bit(1) DEFAULT NULL,
  PRIMARY KEY (`book_id`)
) ENGINE=InnoDB AUTO_INCREMENT=56 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book`
--

LOCK TABLES `book` WRITE;
/*!40000 ALTER TABLE `book` DISABLE KEYS */;
INSERT INTO `book` VALUES (1,'The Hunger Games','Suzanne Collins',50,'',''),(9,'Jane Eyre','Charlotte Brontë',60,'\0',''),(10,'Lord of the Flies','William Golding',30,'',''),(11,'Life of Pi','Yann Martel',100,'',''),(12,'Slaughterhouse-Five','Kurt Vonnegut',35,'',''),(13,'The Girl with the Dragon Tattoo','Stieg Larsson',20,'\0','\0'),(14,'A Game of Thrones','George R. R. Martin',15,'',''),(15,'The Little Prince','Antoine de Saint-Exupéry',15,'',''),(16,'The Handmaid\'s Tale','Margaret Atwood',80,'',''),(17,'Frankenstein','Mary Shelley',60,'\0',''),(18,'Harry Potter and the Philosopher\'s Stone','J. K. Rowling',30,'',''),(19,'Harry Potter and the Chamber of Secrets (Book 2)','J. K. Rowling',100,'','\0'),(20,'1984','George Orwell',35,'',''),(21,'The Da Vinci Code','Dan Brown',20,'\0',''),(22,'To Kill a Mockingbird','Harper Lee',15,'',''),(23,'The Great Gatsby','F. Scott Fitzgerald',15,'','\0'),(24,'Twilight','Stephenie Meyer',80,'',''),(25,'Northern Lights','Philip Pullman',125,'\0',''),(26,'Moby Dick','Herman Melville',115,'\0',''),(27,'The Silmarillion','J. R. R. Tolkien',55,'',''),(28,'The Complete Works of William Shakespeare','William Shakespeare',35,'',''),(29,'Charlotte\'s Web','E. B. White',25,'',''),(30,'Dracula','Bram Stoker',15,'',''),(31,'Eragon','Christopher Paolini',25,'\0',''),(32,'Water for Elephants: A Novel','Sara Gruen',35,'\0',''),(33,'Hamlet','William Shakespeare',25,'',''),(34,'The Girl Who Played with Fire','Stieg Larsson',55,'',''),(35,'The Secret Garden','Frances Hodgson Burnett',45,'',''),(36,'On the Road','Jack Kerouac',35,'\0','\0'),(37,'The Secret Life of Bees','Sue Monk Kidd',65,'',''),(38,'Atonement','Ian McEwan',15,'',''),(39,'Love in The Time of Cholera','Gabriel Garcia Marquez',25,'',''),(40,'The Subtle Knife','Philip Pullman',25,'',''),(41,'The Magician\'s Nephew','C. S. Lewis',55,'',''),(42,'Night','Elie Wiesel',15,'',''),(43,'Watership Down','Richard Adams',25,'',''),(44,'Macbeth','William Shakespeare',15,'',''),(45,'Angela\'s Ashes','Frank McCourt',22,'',''),(46,'Mere Christianity','C. S. Lewis',35,'',''),(47,'The Historian','Elizabeth Kostova',15,'',''),(48,'The Subtle Knife','Philip Pullman',25,'',''),(49,'The Magician\'s Nephew','C. S. Lewis',55,'',''),(50,'Night','Elie Wiesel',15,'',''),(51,'Watership Down','Richard Adams',25,'',''),(52,'Macbeth','William Shakespeare',15,'',''),(53,'Angela\'s Ashes','Frank McCourt',22,'',''),(54,'Mere Christianity','C. S. Lewis',35,'',''),(55,'The Historian','Elizabeth Kostova',15,'','');
/*!40000 ALTER TABLE `book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customer` (
  `customer_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `customer_name` varchar(50) NOT NULL,
  `customer_phone` varchar(15) NOT NULL,
  `customer_address` varchar(100) NOT NULL,
  `join_date` datetime DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`customer_id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (8,'shimron granot','0539487593','ben gurion 32 rishon','2018-07-28 18:22:19'),(9,'moniqe granot','0504445554','ben gurion 32 rishon','2018-07-28 18:22:19'),(10,'varda richer','0523456789','shaul zilberman 41 rehovut','2018-07-28 18:22:19'),(11,'michal richer','0666352453','shpinoza tel aviv','2018-07-28 18:22:19'),(12,'or kirshenbuim','0556677763','shpinuza tel aviv','2018-07-28 18:22:19'),(13,'ortal granot','0544334433','beer yaakov','2018-07-28 18:22:19'),(14,'adi cohen','0549384847','dizengoff tel aviv','2018-07-28 18:22:19'),(15,'eyal sussman','0554494949','arlozerov rishon lezion','2018-07-28 18:22:19'),(16,'moshe shalom','0554466447','yehuda halevi tel aviv','2018-07-31 19:22:46'),(17,'shaul onu','039651101','ben yehuda jerusalem','2018-07-31 19:22:46'),(18,'ben ben yossi','036554546','yarkon tel aviv','2018-07-31 19:22:46');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `disc_global`
--

DROP TABLE IF EXISTS `disc_global`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `disc_global` (
  `disc_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `info` varchar(50) DEFAULT NULL,
  `start_date` date NOT NULL,
  `end_date` date NOT NULL,
  `amount` decimal(3,2) DEFAULT NULL,
  PRIMARY KEY (`disc_id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `disc_global`
--

LOCK TABLES `disc_global` WRITE;
/*!40000 ALTER TABLE `disc_global` DISABLE KEYS */;
INSERT INTO `disc_global` VALUES (1,'Book Week','2018-07-05','2018-07-30',0.30),(2,'Rosh hashana','2018-01-30','2018-01-31',0.10),(3,'Purim','2018-02-28','2018-03-01',0.10),(4,'Passover','2018-03-30','2018-04-06',0.15),(5,'Jerusalem Day','2018-04-12','2018-04-13',0.15),(6,'Test Discount','2018-07-30','2018-08-30',0.00);
/*!40000 ALTER TABLE `disc_global` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orders` (
  `order_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `order_date` datetime DEFAULT CURRENT_TIMESTAMP,
  `_status` enum('ordered','arrived','noticed','sold') DEFAULT NULL,
  `book_id` int(10) unsigned DEFAULT NULL,
  `supplier_id` int(10) unsigned DEFAULT NULL,
  `customer_id` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`order_id`),
  KEY `book_id` (`book_id`),
  KEY `supplier_id` (`supplier_id`),
  KEY `customer_id` (`customer_id`),
  CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`book_id`) REFERENCES `book` (`book_id`),
  CONSTRAINT `orders_ibfk_2` FOREIGN KEY (`supplier_id`) REFERENCES `supplier` (`supplier_id`),
  CONSTRAINT `orders_ibfk_3` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES (4,'2018-07-27 19:15:18','ordered',10,6,8),(5,'2018-07-28 12:50:45','ordered',9,10,9),(6,'2018-07-28 12:50:45','ordered',22,11,15),(7,'2018-07-28 12:50:45','ordered',13,10,12),(8,'2018-07-28 12:50:45','sold',21,10,14),(9,'2018-07-31 19:29:42','ordered',33,15,14),(10,'2018-07-31 19:29:42','noticed',26,12,18),(11,'2018-07-31 19:29:42','sold',19,13,17),(12,'2018-07-31 19:29:42','arrived',39,10,15),(13,'2018-07-31 19:29:42','arrived',29,12,10),(14,'2018-07-31 19:29:42','noticed',31,15,16),(15,'2018-08-04 19:55:44','noticed',24,13,13);
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `purchase`
--

DROP TABLE IF EXISTS `purchase`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `purchase` (
  `purchase_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `purchase_date` datetime DEFAULT CURRENT_TIMESTAMP,
  `customer_id` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`purchase_id`),
  KEY `customer_id` (`customer_id`),
  CONSTRAINT `purchase_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `purchase`
--

LOCK TABLES `purchase` WRITE;
/*!40000 ALTER TABLE `purchase` DISABLE KEYS */;
INSERT INTO `purchase` VALUES (1,'2018-07-27 17:58:38',8),(2,'2018-07-27 18:35:58',13),(3,'2018-07-27 19:10:08',10),(4,'2018-07-31 19:30:47',18),(5,'2018-07-31 19:30:47',14),(6,'2018-07-31 19:30:47',12),(7,'2018-07-31 19:30:47',16),(8,'2018-07-31 19:30:47',11),(9,'2018-07-31 19:30:47',9),(10,'2018-07-31 19:31:02',8);
/*!40000 ALTER TABLE `purchase` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `purchase_info`
--

DROP TABLE IF EXISTS `purchase_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `purchase_info` (
  `isCanceled` bit(1) DEFAULT NULL,
  `purchase_id` int(10) unsigned NOT NULL,
  `book_id` int(10) unsigned NOT NULL,
  `employee_id` int(11) DEFAULT '1',
  `disc` decimal(3,2) DEFAULT '0.00',
  PRIMARY KEY (`book_id`,`purchase_id`),
  KEY `purchase_id` (`purchase_id`),
  CONSTRAINT `purchase_info_ibfk_1` FOREIGN KEY (`purchase_id`) REFERENCES `purchase` (`purchase_id`),
  CONSTRAINT `purchase_info_ibfk_2` FOREIGN KEY (`book_id`) REFERENCES `book` (`book_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `purchase_info`
--

LOCK TABLES `purchase_info` WRITE;
/*!40000 ALTER TABLE `purchase_info` DISABLE KEYS */;
INSERT INTO `purchase_info` VALUES ('\0',2,9,1,0.00),('\0',1,10,2,0.00),('\0',2,10,1,0.15),('\0',3,10,2,0.15),('',1,11,1,0.00),('\0',1,12,1,0.00),('\0',9,13,1,0.00),('\0',3,14,1,0.00),('\0',3,15,1,0.00),('\0',3,16,1,0.10),('\0',10,19,2,0.00),('\0',7,21,2,0.10),('',6,22,1,0.00),('\0',5,25,1,0.00),('\0',8,27,2,0.00),('\0',4,31,2,0.00),('',6,32,1,0.00),('\0',4,33,2,0.10);
/*!40000 ALTER TABLE `purchase_info` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `supplied_by`
--

DROP TABLE IF EXISTS `supplied_by`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `supplied_by` (
  `book_id` int(10) unsigned NOT NULL,
  `supplier_id` int(10) unsigned NOT NULL,
  `price` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`book_id`,`supplier_id`),
  KEY `supplier_id` (`supplier_id`),
  CONSTRAINT `supplied_by_ibfk_1` FOREIGN KEY (`book_id`) REFERENCES `book` (`book_id`),
  CONSTRAINT `supplied_by_ibfk_2` FOREIGN KEY (`supplier_id`) REFERENCES `supplier` (`supplier_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `supplied_by`
--

LOCK TABLES `supplied_by` WRITE;
/*!40000 ALTER TABLE `supplied_by` DISABLE KEYS */;
INSERT INTO `supplied_by` VALUES (9,6,10),(9,7,10),(9,10,25),(10,6,10),(10,7,12),(10,10,12),(11,7,12),(12,7,5),(12,10,5),(13,8,8),(13,10,10),(14,9,12),(21,10,10),(22,11,5);
/*!40000 ALTER TABLE `supplied_by` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `supplier`
--

DROP TABLE IF EXISTS `supplier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `supplier` (
  `supplier_id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `supplier_name` varchar(50) NOT NULL,
  `supplier_phone` varchar(15) NOT NULL,
  `supplier_address` varchar(100) NOT NULL,
  PRIMARY KEY (`supplier_id`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `supplier`
--

LOCK TABLES `supplier` WRITE;
/*!40000 ALTER TABLE `supplier` DISABLE KEYS */;
INSERT INTO `supplier` VALUES (6,'david ben gurion','086554343','somwhere across the street'),(7,'shimi tavori','036676654','in tel aviv'),(8,'or maman','088766544','rishon'),(9,'shay habet','045575854','haifa'),(10,'eyal dotan','028876653','jerusalem'),(11,'piipi vekaki','066747483','beer sheva'),(12,'shalom shalom','027767643','eilat'),(13,'yossi cohen','031234456','tel aviv'),(14,'beni hasha','039656565','rehovut'),(15,'eli cohen','039987887','ramat gan'),(16,'ayelet shon','046645456','or yehuda');
/*!40000 ALTER TABLE `supplier` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-08-04 20:03:06
