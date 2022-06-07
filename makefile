life: main.c game/life.c
	gcc $^ -o life

game: life
	./life

