
CREATE TABLE `humain`(`humId` INTEGER,`humPseudo` VARCHAR(50),`humRue` VARCHAR(50),`humVille` VARCHAR(50),`humPays` VARCHAR(50),`humCP` VARCHAR(5),`humEmail` VARCHAR(70),`humTelephone` VARCHAR(10),`humMDP` VARCHAR(500),primary key(`humId`));

CREATE TABLE `date`(`date` DATE,primary key(`date`));

CREATE TABLE `etat`(`etatId` INTEGER,`etatLibelle` VARCHAR(25),`date` DATE NOT NULL, foreign key (`date`) references date(`date`),primary key(`date`,etatId));

CREATE TABLE `aide`(`aideId` INTEGER,`aideEffectue` BOOL,`aideDate` DATE,`aideDescription` VARCHAR(500),`humId` INTEGER NOT NULL, foreign key (`humId`) references humain(`humId`),primary key(`aideId`));

CREATE TABLE `stade`(`date` DATE NOT NULL,`etatId` INTEGER NOT NULL,`humId` INTEGER NOT NULL, foreign key (`date`,etatId) references etat(`date`,etatId), foreign key (`humId`) references humain(`humId`),primary key(`date`,etatId,`humId`));

CREATE TABLE `symptome`(`symptId` INTEGER,`symptLibelle` VARCHAR(50),`symptGravite` INTEGER,`date` DATE NOT NULL, foreign key (`date`) references date(`date`),primary key(`date`,symptId));

CREATE TABLE `avoir`(`date` DATE NOT NULL,`symptId` INTEGER NOT NULL,`humId` INTEGER NOT NULL, foreign key (`date`,symptId) references symptome(`date`,symptId), foreign key (`humId`) references humain(`humId`),primary key(`date`,symptId,`humId`));
