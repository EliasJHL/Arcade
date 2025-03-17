##
## run.sh for B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen in /home/elias/Documents/Epitech/Arcade/B-OOP-400-MPL-4-1-arcade-elias-josue.hajjar-llauquen
##
## Made by Elias Josué HAJJAR LLAUQUEN
## Login   <elias-josue.hajjar-llauquen@epitech.eu>
##
## Started on  Mon Mar 17 15:53:40 2025 Elias Josué HAJJAR LLAUQUEN
## Last update Tue Mar 17 16:30:12 2025 Elias Josué HAJJAR LLAUQUEN
##

xhost +local:

docker-compose -f dockerfiles/docker-compose-prod.yml up --build --force-recreate