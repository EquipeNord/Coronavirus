CREATE TABLE `humain`(`humId` INTEGER,`humPseudo` VARCHAR(50),`humRue` VARCHAR(50),`humVille` VARCHAR(50),`humPays` VARCHAR(50),`humCP` VARCHAR(12),`humEmail` VARCHAR(70),`humTelephone` VARCHAR(15),`humMDP` VARCHAR(500),`humLatitude` VARCHAR(100),`humLongitude` VARCHAR(100),primary key(`humId`));

CREATE TABLE `symptome`(`symptId` INTEGER,`symptLibelle` VARCHAR(50),`symptGravite` INTEGER,primary key(`symptId`));


CREATE TABLE `avoir`(`symptId` INTEGER NOT NULL,`humId` INTEGER NOT NULL,`date` DATE NOT NULL, foreign key (`symptId`) references symptome(`symptId`), foreign key (`humId`) references humain(`humId`),primary key(`symptId`,`humId`,`date`));

CREATE TABLE `etat`(`etatId` INTEGER,`etatLibelle` VARCHAR(25),primary key(`etatId`));

CREATE TABLE `aide`(`aideId` INTEGER,`aideEffectue` BOOL,`aideDate` DATETIME,`aideDescription` VARCHAR(500),`aideLibelle` VARCHAR(50),`humId` INTEGER NOT NULL, foreign key (`humId`) references humain(`humId`),primary key(`aideId`));

CREATE TABLE `stade`(`etatId` INTEGER NOT NULL,`humId` INTEGER NOT NULL,`date` DATE NOT NULL, foreign key (`etatId`) references etat(`etatId`), foreign key (`humId`) references humain(`humId`), primary key(`etatId`,`humId`,`date`));

