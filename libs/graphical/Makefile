##
## Makefile for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games
##
## Made by Elias Josué HAJJAR LLAUQUEN
## Login   <elias-josue.hajjar-llauquen@epitech.eu>
##
## Started on  Thu Mar 20 15:23:45 2025 Elias Josué HAJJAR LLAUQUEN
## Last update Sun Mar 29 21:11:27 2025 Elias Josué HAJJAR LLAUQUEN
##

NCURSES_SRC	=	./src/ncurses/arcade_ncurses.cpp
SDL2_SRC	=	./src/sdl2/arcade_sdl2.cpp
IRRLICHT_SRC	=	./src/irrlicht/arcade_irrlicht.cpp

REQUIRED_LIBS	=	../../include/Rect.cpp ../../include/Text.cpp ../../include/Color.cpp

IRRLICHT_FLAGS	=	-lIrrlicht
SDL2_FLAGS	=	-lSDL2 -lSDL2_ttf -lSDL2_image
NCURSES_FLAGS	=	-lncurses

all:	$(GRAPHICAL_LIBS)
	g++ -shared -fPIC $(NCURSES_SRC) $(REQUIRED_LIBS) -o arcade_ncurses.so $(NCURSES_FLAGS) -I ../../include
	g++ -shared -fPIC $(SDL2_SRC) $(REQUIRED_LIBS) -o arcade_sdl2.so $(SDL2_FLAGS) -I ../../include
	g++ -shared -fPIC $(IRRLICHT_SRC) $(REQUIRED_LIBS) -o arcade_irrlicht.so $(IRRLICHT_FLAGS) -I ../../include
	mv *.so ../

clean:
	@$(RM) *.so

fclean: clean
	@$(RM) *~
	@echo "\033[31m= = = = = =   CLEAR COMPLETED   = = = = = =\033[0m"

re: fclean all