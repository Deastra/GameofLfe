life: main.c game/life.c gui/life_gui.c
	gcc $^ -o life -lSDL2 -lSDL2main -Igame -Igui

game: life
	./life