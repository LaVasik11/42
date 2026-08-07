NAME = inception

all:
	cd srcs && docker compose up --build -d

down:
	cd srcs && docker compose down

clean:
	cd srcs && docker compose down -v

fclean: clean
	docker system prune -af

re: clean all

.PHONY: all down clean fclean re
