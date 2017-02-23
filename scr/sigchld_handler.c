
#include <server.h>

void sigchld_handler(int s)
{
	// waitpid() puede sobreescribir errno, por lo que debemos guardarlo y restaurarlo
	int saved_errno = errno;

	while(waitpid(-1, NULL, WNOHANG) > 0);

	errno = saved_errno;
}
