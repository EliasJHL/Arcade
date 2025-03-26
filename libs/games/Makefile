##
## Makefile for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen/libs/games
##
## Made by Elias Josué HAJJAR LLAUQUEN
## Login   <elias-josue.hajjar-llauquen@epitech.eu>
##
## Started on  Thu Mar 20 15:23:45 2025 Elias Josué HAJJAR LLAUQUEN
## Last update Sat Mar 21 15:00:22 2025 Elias Josué HAJJAR LLAUQUEN
##

GAMES_SRC	=	$(wildcard libs/games/src/*.cpp)

GAMES_LIBS := $(GAMES_SRC:.cpp=.so)

all:	$(GAMES_LIBS)
	mv *.so ../

clean:
	@$(RM) ../*.so

fclean: clean
	@$(RM) *~
	@echo "\033[31m= = = = = =   CLEAR COMPLETED   = = = = = =\033[0m"

re: fclean all