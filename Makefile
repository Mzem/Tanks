SRC=app
TARGET=bin

all:
	qmake -makefile -o MakefileMain $(SRC)/main/Tanks.pro
	make -f MakefileMain
	
run: all
	$(TARGET)/Tanks
	
tests: all
	qmake -makefile -o MakefileTests $(SRC)/tests/testtank.pro
	moc -o $(SRC)/$@/testtank.moc $(SRC)/$@/testtank.cpp 
	make -f MakefileTests
	
run-tests: tests
	$(TARGET)/tests

.PHONY: all clean tests

clean:
	find . -name "*.o" -type f -delete
	rm -rf $(TARGET)
	rm -f MakefileMain
	rm -f MakefileTests
	find . -name "*.moc" -type f -delete
