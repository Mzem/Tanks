QT += widgets

TEMPLATE = app
TARGET = Tanks
INCLUDEPATH += .
DESTDIR = bin		#Destination du fichier TARGET "Tanks"
OBJECTS_DIR = bin	#Destination des fichiers objet

SOURCES += \
    src/main.cpp \
    src/Tank.cpp \
    src/Fenetre.cpp \
    src/Terrain.cpp \
    src/Point.cpp \
    src/Segment.cpp \
    src/Canon.cpp \
    src/Obstacle.cpp \
    src/Obus.cpp

HEADERS += \
    head/Tank.h \
    head/Fenetre.h \
    head/Terrain.h \
    head/Point.h \
    head/Segment.h \
    head/Canon.h \
    head/Obstacle.h \
    head/Obus.h
