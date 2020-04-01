-- MySQL dump 10.16  Distrib 10.1.44-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: dbteamjerem
-- ------------------------------------------------------
-- Server version	10.1.44-MariaDB-0+deb9u1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `dbteamjerem`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `dbteamjerem` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;

USE `dbteamjerem`;

--
-- Table structure for table `aide`
--

DROP TABLE IF EXISTS `aide`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `aide` (
  `aideId` int(11) NOT NULL,
  `aideEffectue` tinyint(1) DEFAULT NULL,
  `aideDate` datetime DEFAULT NULL,
  `aideDescription` varchar(500) DEFAULT NULL,
  `aideLibelle` varchar(50) DEFAULT NULL,
  `humId` int(11) NOT NULL,
  PRIMARY KEY (`aideId`),
  KEY `humId` (`humId`),
  CONSTRAINT `aide_ibfk_1` FOREIGN KEY (`humId`) REFERENCES `humain` (`humId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `aide`
--

LOCK TABLES `aide` WRITE;
/*!40000 ALTER TABLE `aide` DISABLE KEYS */;
INSERT INTO `aide` VALUES (1,0,'2020-03-10 00:00:00','Faire mes course car je suis en fauteuil','Course',1),(2,0,'2020-03-10 00:00:00','Faire mes course car je suis en fauteuil','Course',2),(3,0,'2020-03-10 00:00:00','Faire mes course car je suis en fauteuil','Course',3);
/*!40000 ALTER TABLE `aide` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `avoir`
--

DROP TABLE IF EXISTS `avoir`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `avoir` (
  `symptId` int(11) NOT NULL,
  `humId` int(11) NOT NULL,
  `date` date NOT NULL,
  PRIMARY KEY (`symptId`,`humId`,`date`),
  KEY `humId` (`humId`),
  CONSTRAINT `avoir_ibfk_1` FOREIGN KEY (`symptId`) REFERENCES `symptome` (`symptId`),
  CONSTRAINT `avoir_ibfk_2` FOREIGN KEY (`humId`) REFERENCES `humain` (`humId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `avoir`
--

LOCK TABLES `avoir` WRITE;
/*!40000 ALTER TABLE `avoir` DISABLE KEYS */;
INSERT INTO `avoir` VALUES (1,1,'2020-03-10'),(2,1,'2020-03-11'),(2,2,'2020-03-15');
/*!40000 ALTER TABLE `avoir` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `etat`
--

DROP TABLE IF EXISTS `etat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `etat` (
  `etatId` int(11) NOT NULL,
  `etatLibelle` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`etatId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `etat`
--

LOCK TABLES `etat` WRITE;
/*!40000 ALTER TABLE `etat` DISABLE KEYS */;
INSERT INTO `etat` VALUES (1,'Infecte'),(2,'Suspect'),(3,'Gueri');
/*!40000 ALTER TABLE `etat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `humain`
--

DROP TABLE IF EXISTS `humain`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `humain` (
  `humId` int(11) NOT NULL,
  `humPseudo` varchar(50) DEFAULT NULL,
  `humRue` varchar(50) DEFAULT NULL,
  `humVille` varchar(50) DEFAULT NULL,
  `humPays` varchar(50) DEFAULT NULL,
  `humCP` varchar(12) DEFAULT NULL,
  `humEmail` varchar(70) DEFAULT NULL,
  `humTelephone` varchar(15) DEFAULT NULL,
  `humMDP` varchar(500) DEFAULT NULL,
  `humLatitude` float(9,6) DEFAULT NULL,
  `humLongitude` float(9,6) DEFAULT NULL,
  PRIMARY KEY (`humId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `humain`
--

LOCK TABLES `humain` WRITE;
/*!40000 ALTER TABLE `humain` DISABLE KEYS */;
INSERT INTO `humain` VALUES (1,'yohan','4 Chemin les Chrisolas','Gap','France','05000','yohan.salamone@outlook.com','0629351379','22c22895822830f4f128cd72863c08a2',44.533833,6.043515),(2,'Jerem','13 Rue Carnot','Gap','France','05000','mainard17@outlook.fr','0783676638','0cbc6611f5540bd0809a388dc95a615b',44.559780,6.080969),(3,'Nicoco','27 Rue du Plan de Gap','Gap','France','05000','granier.nicolas05@gmail.com','0683547896','71ec2af811cdf898bce6904a75a48d75',44.572193,6.097557),(4,'Valoche','34 Rue Jacqueline Auriol','Vendôme','France','411000','valdu41@gmail.com','0632313435','71ec2af811cdf898bce6904a75a48d75',47.787922,1.072285),(5,'Elisavet','22 Nileos','Athens','Greece','118 51','elisavet@gmail.com','+30684745236','0d35c1f17675a8a2bf3caaacd59a65de',37.975052,23.717424),(1585726805,'test1',NULL,NULL,NULL,NULL,'test1',NULL,'5a105e8b9d40e1329780d62ea2265d8a',NULL,NULL);
/*!40000 ALTER TABLE `humain` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stade`
--

DROP TABLE IF EXISTS `stade`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `stade` (
  `etatId` int(11) NOT NULL,
  `humId` int(11) NOT NULL,
  `date` date NOT NULL,
  PRIMARY KEY (`etatId`,`humId`,`date`),
  KEY `humId` (`humId`),
  CONSTRAINT `stade_ibfk_1` FOREIGN KEY (`etatId`) REFERENCES `etat` (`etatId`),
  CONSTRAINT `stade_ibfk_2` FOREIGN KEY (`humId`) REFERENCES `humain` (`humId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stade`
--

LOCK TABLES `stade` WRITE;
/*!40000 ALTER TABLE `stade` DISABLE KEYS */;
INSERT INTO `stade` VALUES (1,1,'2020-03-10'),(1,2,'2020-03-10'),(1,4,'2020-03-12'),(2,4,'2020-03-15'),(3,4,'2020-03-20');
/*!40000 ALTER TABLE `stade` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `symptome`
--

DROP TABLE IF EXISTS `symptome`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `symptome` (
  `symptId` int(11) NOT NULL,
  `symptLibelle` varchar(50) DEFAULT NULL,
  `symptGravite` int(11) DEFAULT NULL,
  PRIMARY KEY (`symptId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `symptome`
--

LOCK TABLES `symptome` WRITE;
/*!40000 ALTER TABLE `symptome` DISABLE KEYS */;
INSERT INTO `symptome` VALUES (1,'Toux',4),(2,'Problème respiratoire',8),(3,'Fièvre',2);
/*!40000 ALTER TABLE `symptome` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-04-01 10:41:08
