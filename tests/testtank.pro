QT += testlib \
	core gui \
	widgets

TEMPLATE = app
TARGET = tests
INCLUDEPATH += .

# Input
SOURCES += testtank.cpp \
	../src/Point.cpp \
	../src/Canon.cpp \
	../src/Obstacle.cpp 

# Output
DESTDIR = ../bin
OBJECTS_DIR = ../bin
MOC_DIR = .
