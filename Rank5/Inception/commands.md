## Docker compose commands:

No rebuild: 
`docker-compose up -d` (`-d` is detached mode: runs container in background)

With rebuild:
`docker-compose up --build -d`

Stop Services, not volumes:
`docker-compose stop`

`docker-compose logs`\
`docker-compose restart`\
`docker-compose config`\
`docker network ls`\
`docker network inspect <network_name>`\
`docker network prune`\


## Docker Commands for Containers

View Running Containers:
`docker ps`\

List all containers (including stopped ones):
`docker ps -a`

`docker inspect <container_name>`\
`docker volume ls`\
`docker volume inspect <volume_name>`\
`docker volume prune`

## Debugging and Troubleshooting

`docker logs <container_name>`\
Attach your terminal to a running container:
`docker attach <container_name>`

`docker port <container_name>`\
`docker kill <container_name>`\
`docker image prune -a`\
`docker system df`\
`docker image prune`

### Mariadb
---
Enter Container and access MariaDB as root:
`exec -it mariadb mysql -u root` \
Verify Database
`SHOW DATABASES;`\
Verify user creation
`SELECT User, Host FROM mysql.user;`\
Check User permissions
`SHOW GRANTS FOR 'wp_user'@'%';`

### Misc
---
Ssh to VM:
`ssh -p <port> <username>@127.0.0.1`

Mount shared folder from host to vm:
`sudo mount -t vboxsf <foldername> /mnt`
then cp your file (e.g.) to /srcs