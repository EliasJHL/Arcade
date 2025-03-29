##
## Makefile for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
##
## Made by Elias Josué HAJJAR LLAUQUEN
## Login   <elias-josue.hajjar-llauquen@epitech.eu>
##
## Started on  Thu Mar 20 14:41:37 2025 Elias Josué HAJJAR LLAUQUEN
## Last update Sat Mar 28 19:05:35 2025 Elias Josué HAJJAR LLAUQUEN
##

NAME	=	arcade

CORE_SRC	=	$(wildcard src/*.cpp) $(wildcard include/*.cpp)

GRAPHICAL_SRC	=	$(wildcard libs/graphical/src/*.cpp)

GAMES_SRC	=	$(wildcard libs/games/src/*.cpp)

all: core graphical games

core:
	g++ -o $(NAME) $(CORE_SRC) -I ./include
	@echo "\033[32m= = = = =  CORE COMPILATION COMPLETED  = = = = =\033[0m"

games:
	@$(MAKE) -C libs/games/
	@echo "\033[32m= = = = =  GAMES COMPILATION COMPLETED  = = = = =\033[0m"

graphical:
	@$(MAKE) -C libs/graphical/
	@echo "\033[32m= = = =  GRAPHICAL COMPILATION COMPLETED  = = = =\033[0m"

clean:
	@$(RM) $(NAME)
	@$(RM) ./libs/*.so

fclean: clean
	@$(RM) $(NAME)
	@$(RM) *~
	@$(MAKE) -C libs/games/ clean
	@$(MAKE) -C libs/graphical/ clean
	@echo "\033[31m= = = = = =   CLEAR COMPLETED   = = = = = =\033[0m"

re: fclean all