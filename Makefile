#______________________________________//_______________________________________
SRC_DIR	=	./source
SRC		=	main.cpp

OBJ_DIR	=	./build
OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

INCD_DIR=	-I ./include
# INCD	=
#______________________________________//_______________________________________
vpath %.cpp $(SRC_DIR)
vpath %.hpp $(INCD_DIR)
#______________________________________//_______________________________________
TARGET	=	main

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

RM		=	rm -rf

CC		=	g++
#______________________________________//_______________________________________
all:			$(TARGET)

$(TARGET):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|          Executavel Criado           |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(OBJ_DIR)/%.o:	%.cpp #%.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(INCD_DIR) $(CFLAGS) $< -c -o $@
#______________________________________//_______________________________________
clean:
	$(RM) $(OBJ_DIR)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|        Arquivos .o Deletados         |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

fclean:		clean
	$(RM) $(TARGET)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|         Executavel Deletado          |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"
#______________________________________//_______________________________________
re:			fclean all

.PHONY:		all clean fclean re
