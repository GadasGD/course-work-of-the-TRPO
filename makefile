TARGET = main
CFLAGS = -Wall -Wextra -Werror 

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

PREF_SRC = ./src/
PREF_OBJ = ./obj/

$(TARGET): $(OBJ)
	cc $(CFLAGS) -o $(TARGET) $(OBJ)
	./main
	
$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm $(TARGET) $(PREF_OBJ)*.o