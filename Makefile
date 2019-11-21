SOURCES = src/main.cpp src/Persona.cpp src/Ordine.cpp src/Menu.cpp
all: $(SOURCES)
	g++ -g -o Sushi $(SOURCES)
