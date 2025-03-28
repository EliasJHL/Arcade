##
## Makefile for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games
##
## Made by Elias Josué HAJJAR LLAUQUEN
## Login   <elias-josue.hajjar-llauquen@epitech.eu>
##
## Started on  Thu Mar 20 15:23:45 2025 Elias Josué HAJJAR LLAUQUEN
## Last update Fri Mar 27 10:44:55 2025 Elias Josué HAJJAR LLAUQUEN
##

SNAKE_SRC	=	./src/snake/arcade_snake.cpp

REQUIRED_LIBS	=	../../include/Rect.cpp ../../include/Text.cpp ../../include/Color.cpp 

all:	$(GRAPHICAL_LIBS)
	g++ -shared -fPIC $(SNAKE_SRC) $(REQUIRED_LIBS) -o arcade_snake.so -I ../../include
	mv *.so ../

clean:
	@$(RM) *.so

fclean: clean
	@$(RM) *~
	@echo "\033[31m= = = = = =   CLEAR COMPLETED   = = = = = =\033[0m"

re: fclean all