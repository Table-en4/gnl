# Nom de l'exécutable
NAME = get_next_line

# Compilateur
CC = cc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

# Fichiers source
SRC = get_next_line.c get_next_line_utils.c

# Objets générés
OBJ = $(SRC:.c=.o)

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Nettoyer les fichiers objets
clean:
	rm -f $(OBJ)

# Nettoyer tout (objets + binaire)
fclean: clean
	rm -f $(NAME)

# Recompiler tout depuis zéro
re: fclean all

# Bonus (à adapter si tu fais get_next_line_bonus)
bonus:
	@echo "Aucune version bonus définie."

.PHONY: all clean fclean re bonus
