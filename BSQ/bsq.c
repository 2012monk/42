#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "bsq.h"
// typedef struct s_board
// {
// 	char	**board;
// 	int		height;
// 	int		width;
// 	char	obstacle;
// 	char	empty;
// 	char	fill;
// } t_board;

void    error_exit(void)
{
    write(2, "map error\n", 10);
    exit(0);
}

int count_size(char *argv)
{
    int     fd;
    int     i;
    int     size;
    char    buf[1000];

    size = 0;
    i = 1000;
    fd = open(argv, O_RDONLY);
    if (fd < 0)
    {
        return (-1);
    }
        // error_exit();
    while (i == 1000)
    {
        i = read(fd, buf, 1000);
        size += i;
    }
    close(fd);
    return (size);
}

char    *read_file(char *argv)
{
    int     fd;
    int     size;
    char    *buf;

    size = count_size(argv);
    if (size < 0)
        return (NULL);
    buf = (char *)malloc(sizeof(char) * (size + 1));
    if (!buf)
        exit(0); //이건 무슨 오류?
    fd = open(argv, O_RDONLY);
    if (fd < 0)
        error_exit();
    read(fd, buf, size);
    buf[size] = '\0';
    close(fd);
    return (buf);
}

int ft_atoi1(char *buf, int i)
{
    int result;
    int j;

    result = 0;
    j = 0;
    while (j < i)
    {
        if (buf[j] < 48 || buf[j] > 57)
            error_exit();
        result = (result * 10) + (buf[j] - '0');
        j++;
    }
    return (result);
}

void    redun_check(t_board *board_info)
{
    if (board_info -> fill == board_info -> obstacle)
        error_exit();
    if (board_info -> fill == board_info -> empty)
        error_exit();
    if (board_info -> obstacle == board_info -> empty)
        error_exit();
}

void    first_line(char *buf, t_board *board_info)
{
    int i;
    int j;
    int ht;
    int wt;

    i = 0;
    while (buf[i] != '\n')
    {
        if (buf[i] < 32 || buf[i] > 126)
            error_exit();
        i++;
    }
    j = i + 1;
    board_info -> fill = buf[--i];
    board_info -> obstacle = buf[--i];
    board_info -> empty = buf[--i];
    ht = ft_atoi1(buf, i);
    if (ht <= 0)
        error_exit();
    board_info -> height = ht;
    wt = 0;
    while (buf[j++] != '\n')
        wt++;
    board_info -> width = wt;
    redun_check(board_info);
}

void    into_board(char *buf, t_board *board_info, int idx)
{
    char    *line;
    int     i;

    line = (char *)malloc(sizeof(char) * (board_info -> width + 1));
    if (!line)
    {
        board_info = NULL;
        return ;
        // exit(0);
    }
    i = 0;
    while (*buf != '\n')
    {
        if (*buf == board_info -> obstacle)
            line[i] = *buf;
        else if (*buf == board_info -> empty)
            line[i] = *buf;
        else
        {
            board_info = NULL;
            return ;
            // error_exit();
        }
        buf++;
        i++;
    }
    if (i != board_info -> width)
    {
        board_info = NULL;
        return ;
    }
        // error_exit();
    line[i] = '\0';
    board_info -> board[idx] = line;
}

void    transfer_file(char *argv, t_board *board_info)
{
    char    *buf;
    int     idx;

    buf = read_file(argv);
    if (!buf)
    {
        board_info = NULL;
        return ;
    }
    first_line(buf, board_info);
    if (!board_info)
        return ;
    board_info -> board = (char **)malloc(sizeof(char *) * (board_info -> height + 1));
    if (!board_info -> board)
        exit(0);
    while (*buf != '\n')
        buf++;
    idx = 0;
    buf++;
    while (*buf != '\0')
    {
        into_board(buf, board_info, idx);
        buf = buf + board_info -> width + 1;
        idx++;
        if (idx > board_info -> height)
            error_exit();
    }
    board_info -> board[idx] = 0;
}

void    transfer_file_stdin(t_board *board_info, char *buff)
{
    char    *buf;
    int     idx;

    buf = buff;
    first_line(buf, board_info);
    board_info -> board = (char **)malloc(sizeof(char *) * (board_info -> height + 1));
    if (!board_info -> board)
        exit(0);
    while (*buf != '\n')
        buf++;
    idx = 0;
    buf++;
    while (*buf != '\0')
    {
        into_board(buf, board_info, idx);
        buf = buf + board_info -> width + 1;
        idx++;
        if (idx > board_info -> height)
            error_exit();
    }
    board_info -> board[idx] = 0;
}
void	solve_maps(int ac, char **av)
{
	int		i;
	t_board	*map;

    map = malloc(sizeof(t_board));
	i = -1;
	while (++i < ac)
	{
		// map = parse_map(av[i]);
        if (ac > 1 && i > 0)
            write(1, "\n", 1);
        transfer_file(av[i], map);
		if (!map)
		{
			throw_err();
			continue ;
		}
		solve(map);
	}
}

int main(int argc, char **argv)
{
    // int     i;
    // char    buf[1000];
    // t_board *board_info;

    // board_info = (t_board *)malloc(sizeof(t_board) * argc);
    // transfer_file(argv[1], &board_info[0]);
    // print_board(board_info);
    solve_maps(argc-1,&argv[1]);
    // i = 1;
    // solve_maps(argc - 1, &argv[1]);
    // if (argc > 1)
    // {
    //     while (i < argc)
    //     {
    //         transfer_file(argv[i], &board_info[i - 1]);
    //         i++;

    //     }
        /*i = 0;
        while (board_info[1].board[i] != 0)
        {
            printf("%s\n", board_info[1].board[i]);
            i++;
        }*/ //board 확인용
    // }
    // else
    // {
    //     i = 0;
    //     while (read(0, &buf[i], 1) > 0 && i < 1000)
    //         i++;
    //     buf[i] = '\0';
    //     transfer_file_stdin(&board_info[0], buf);
    //     // i = 0;
    //     // while (board_info[0].board[i] != 0)
    //     // {
    //     //     printf("%s\n", board_info[0].board[i]);
    //     //     i++;
    //     // }
    // }
}