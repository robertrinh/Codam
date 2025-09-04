all: build

build:
	mkdir -p $(HOME)/data/mariadb
	docker-compose -f srcs/docker-compose.yml up --build

down:
	docker-compose -f srcs/docker-compose.yml down

clean:
	docker-compose -f srcs/docker-compose.yml down -v
	docker system prune -af

re: clean all

.PHONY: all build down clean re