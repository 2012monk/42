#include "hexdump.h"

int	is_eof(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == EOF)
			return (i);
	}
	return (0);
}
void	put_str(int fd, char *msg)
{
	while (*msg)
		write(fd, msg++, 1);
}

void    f_print(char *msg)
{
    put_str(F_STDOUT, msg);
}

void	throw_err(char *prog, char *path)
{
	if (errno == 0)
		return ;
	put_str(F_STDERR, basename(prog));
	put_str(F_STDERR, ": ");
    if (errno != -1)
    {

        put_str(F_STDERR, path);
        put_str(F_STDERR, ": ");
	    put_str(F_STDERR, strerror(errno));
    }
    else
    {
        put_str(F_STDERR, "illegal offset -- ");
    }
	put_str(F_STDERR, "\n");
	errno = 0;
}

int	is_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
int	batch_file(int fd, char buf[], int size)
{
	if (fd < 0)
		return (-1);
	return (read(fd, buf, size));
}