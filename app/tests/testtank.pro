QT += testlib \
	core gui \
	widgets

TEMPLATE = app
TARGET = tests
INCLUDEPATH += .

# Input
SOURCES += testtank.cpp \
	../main/src/Point.cpp \
	../main/src/Canon.cpp \
	../main/src/Obstacle.cpp 

# Output
DESTDIR = bin
OBJECTS_DIR = bin
MOC_DIR = bin
