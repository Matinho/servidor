
#include <server.h>

int main(void)
{
	int sockfd, new_fd;  // escucha en sock_fd, nueva conexión en new_fd
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_storage their_addr; // informacion de la direccion del que se conecta
	socklen_t sin_size;
	struct sigaction sa;
	int yes=1;
	char s[INET6_ADDRSTRLEN], usuario[40], clave[40];
	int rv;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // uso mi IP

	if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "Info de conexion: %s\n", gai_strerror(rv));
		return 1;
	}

	// Circular a traves de los resultados y unir al primero que podamos
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("servidor: socket");
			continue;
		}

		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
				sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("servidor: enlazado");
			continue;
		}

		break;
	}

	freeaddrinfo(servinfo); // todo hecho con esta estructura

	if (p == NULL)  {
		fprintf(stderr, "servidor: falla al enlazar\n");
		exit(1);
	}

	if (listen(sockfd, BACKLOG) == -1) {
		perror("listen");
		exit(1);
	}

	sa.sa_handler = sigchld_handler; // limpiamos los preoceso muertos - reap all dead processes
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	printf("servidor: esperando conexiones...\n");

/* De acá empieza la lógica del servidor */

/*
	OPCIONES DEL SISTEMA
		sin parametros hace el Login
		-R -r registrarse al sistema
		-H -h ayuda
		-Q -q desloguearse
		-B -b bitacora
			-t bitacora total
			-u bitacora del Usuario logueado
			-u "nombreUsuario" bitacora del usuario "nombreUsuario"
*/

	while(1) {  // bucle accept() principal
		sin_size = sizeof their_addr;
		new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		if (new_fd == -1) {
			perror("accept");
			continue;
		}

		inet_ntop(their_addr.ss_family,get_in_addr((struct sockaddr *)&their_addr),s, sizeof s);
		printf("servidor: conexion entrante de %s\n", s);

		if (!fork()) { // este es el proceso hijo
			close(sockfd); // el hijo no necesita el escuchador

			/*Ingreso de usuario*/
			if (send(new_fd, "Ingrese Usuario: ", 17, 0) == -1)
				perror("Error en el Usuario");
			if (recv(new_fd, usuario, sizeof(usuario), 0) == -1) //usar read()
				perror("Error en el ingreso de Usuario");
			if (strncmp(usuario, "usuario", 40)==0){
				puts("Se ingresó el Usuario:");
	    		puts(usuario);

				/*Ingreso la clave*/
				if (send(new_fd, "Ingrese Clave: ", 15, 0) == -1)
					perror("Error en el clave");
				if (recv(new_fd, clave, sizeof(clave), 0) == -1)
					perror("Error en el ingreso de clave");
				if (strncmp(clave, "clave")){
					puts("Se ingresó la Clave:");
		    	puts(clave);

					if (send(new_fd, "Hola, Mundo!\n", 13, 0) == -1)
						perror("send");
					}
				}
			close(new_fd);
			exit(0);
		}
		close(new_fd);  // el padre no necesita esto
	}

	return 0;
}
