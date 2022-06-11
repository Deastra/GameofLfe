life: main.c game/life.c gui/life_gui.c
	gcc $^ -o life -lSDL2 

game: life
	./life