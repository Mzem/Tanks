QT += widgets

TEMPLATE = app
TARGET = Tanks
INCLUDEPATH += .
DESTDIR = bin		#Destination du fichier TARGET "Tanks"
OBJECTS_DIR = bin	#Destination des fichiers objet
RCC_DIR = bin		#Destination des fichiers qrc


SOURCES += \
    src/main.cpp \
    src/Tank.cpp \
    src/Jeu.cpp \
    src/Terrain.cpp \
    src/Point.cpp \
    src/Segment.cpp \
    src/Canon.cpp \
    src/Obstacle.cpp \
    src/Obus.cpp \
	src/Menu.cpp

HEADERS += \
    head/Tank.h \
    head/Jeu.h \
    head/Terrain.h \
    head/Point.h \
    head/Segment.h \
    head/Canon.h \
    head/Obstacle.h \
    head/Obus.h \
	head/Menu.h

RESOURCES += \
    img/tank1.qrc \
    img/canon1.qrc \
    img/bg.qrc \
    img/logo.qrc
