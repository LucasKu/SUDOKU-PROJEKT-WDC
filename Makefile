final:
	gcc $(shell pkg-config gtk+-3.0 --cflags) -o Sudoku aux_funcs.c board.c interactions.c main.c menu.c sample_sudokus.c solver.c $(shell pkg-config gtk+-3.0 --libs)