Construction :

	Ajouter les chemins de tous les fichiers sources .cpp et headers .h du projet dans le fichier Tanks.pro. 

	Se positionner sur le répertoire du projet :

		- Pour générer un Makefile à partir du projet : 			$ qmake Tanks.pro
		- Pour compiler le projet à l'aide du Makefile :			$ make
		- Pour executer l'application :						$ ./bin/Tanks
		
Construction tests :

	Ajouter les chemins de tous les fichiers sources .cpp à tester dans le fichier testtank.pro. 

	Se positionner sur le répertoire "tests" :

		- Pour générer un Makefile : 			$ qmake testtank.pro
		- Pour compiler le projet à l'aide du Makefile :			$ make
		- Pour executer les tests :						$ ../bin/tests
