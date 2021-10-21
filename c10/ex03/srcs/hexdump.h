

#ifndef HEXDUMP_H
# define HEXDUMP_H



#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

# define F_STDIN 0

# define F_STDOUT 1

# define F_STDERR 2

# define LINE_SIZE 16
extern int is_dir; 
extern int cannonical;
void    f_print(char *msg);
int	is_eof(char *buf);
int	is_directory(char *file);
void	throw_err(char *prog, char *path);
int	batch_file(int fd, char buf[], int size);

void	print_dec_to_hex(unsigned long n, int size);
void	safe_print_char(char *str, int length);
void	print_ascii_hex(char *str, int size);
void	throw_err_custom(char *prog, char *path, int err);
#endif // !HEDUMP_H
