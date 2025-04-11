##
## Makefile for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games
##
## Made by Elias Josué HAJJAR LLAUQUEN
## Login   <elias-josue.hajjar-llauquen@epitech.eu>
##
## Started on  Thu Mar 20 15:23:45 2025 Elias Josué HAJJAR LLAUQUEN
## Last update Sun Mar 29 01:29:49 2025 Elias Josué HAJJAR LLAUQUEN
##

SNAKE_SRC	=	./src/snake/arcade_snake.cpp
NIBBLER_SRC	=	./src/nibbler/arcade_nibbler.cpp
MENU_SRC	=	./src/menu/arcade_menu.cpp

REQUIRED_LIBS	=	../../include/Rect.cpp ../../include/Text.cpp ../../include/Color.cpp ../../include/AGameModule.cpp

all:	$(GRAPHICAL_LIBS)
	g++ -shared -fPIC $(SNAKE_SRC) $(REQUIRED_LIBS) -o arcade_snake.so -I ../../include
	g++ -shared -fPIC $(NIBBLER_SRC) $(REQUIRED_LIBS) -o arcade_nibbler.so -I ../../include
	g++ -shared -fPIC $(MENU_SRC) $(REQUIRED_LIBS) -o arcade_menu.so -I ../../include
	mv *.so ../

clean:
	@$(RM) *.so

fclean: clean
	@$(RM) *~
	@echo "\033[31m= = = = = =   CLEAR COMPLETED   = = = = = =\033[0m"

re: fclean all