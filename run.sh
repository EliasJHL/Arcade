##
## run.sh for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
##
## Made by Elias Josué HAJJAR LLAUQUEN
## Login   <elias-josue.hajjar-llauquen@epitech.eu>
##
## Started on  Mon Mar 17 15:53:40 2025 Elias Josué HAJJAR LLAUQUEN
## Last update Fri Mar 20 11:12:35 2025 Elias Josué HAJJAR LLAUQUEN
##

xhost +local:

docker-compose -f dockerfiles/docker-compose.yaml up --build --force-recreate -d

docker exec -it Arcade bash
