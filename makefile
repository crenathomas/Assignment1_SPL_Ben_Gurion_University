# All Targets
all: cyber

# Tool invocations
# Executable "cyber" depends on the files cyber.o 
cyber: bin/cyber.o
	@echo 'Building target: cyber'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/cyber bin/cyber.o
	@echo 'Finished building target: cyber'
	@echo ' '

# Depends on the source and header files
bin/cyber.o: src/main.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -I/usr/local/Cellar/boost/1.59.0/include -o bin/cyber.o src/main.cpp

#Clean the build directory
clean: 
	rm -f bin/*
