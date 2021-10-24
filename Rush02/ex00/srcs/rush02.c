#include "rush02.h"
// int ft_strlen(char *str)
// {
// 	int i;
// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return i;
// }

// int ft_atoi(char *str)
// {
// 	int result;
// 	int i;

// 	i = -1;
// 	while (++i < 3)
// 	{
// 		if (str[i] == ' ')
// 			continue;
// 		else
// 		{
// 			result = str[i] - '0';
// 			break;
// 		}
// 	}

// 	while (++i<3)
// 	{
// 		result *= 10;
// 		result += str[i] - '0';
// 	}
// 	printf("%d\n", result);
// 	return result;
// }

void clear_set(char *set) {
	int i;
	i = -1;
	while (++i < 3)
		set[i] = ' ';
}

int ft_digit(int len)
{
	int digit;

	if (len % 3 == 0)
		digit = len / 3;
	else
		digit = len / 3 + 1;

	return (digit);
}

void parse_print(int digit, int offset, char* set, char* str)
{
	int i;
	int j;

	j = 0;
	while (digit-- > 0)
	{
		clear_set(set);
		if (offset != 0)
		{
			i = offset - 1;
			offset = 0;
		}
		else
			i = -1;
		while (++i < 3)
		{	
			set[i] = str[j];
			j++;
		}
		// ft_atoi(set);
		//find_unique(ft_atoi(set));
		//find_digit(digit);
		// printf("index: %d\n", digit);

		// printf("%d", ft_atoi(set));
		printf("%s", g_unique_map[ft_atoi(set)]);
	}
}

void parsing(char *str)
{
	int len;
	int digit;
	int offset;
	char set[4];
	
	len = ft_strlen(str);
	offset = 3 - len % 3;
	digit = ft_digit(len);
	parse_print(digit, offset, set, str);
}

int	main()
{
	char	dict[] = "numbers.dict";
	if (init(dict) == -1)
	{
		printf("%s","eror");
		return 1;
	}
	parsing("12345678");
	// if (argc == 3)
	// {
	// 	// change dict
	// }	
	// else if (argc == 2)
	// {	
	// 	// need to check init func param
	// 	if(validate_input(argv[1]) && init(dict) != -1)
	// 	{
	// 		parsing(argv[1]);
	// 	}
	// 	else
	// 		return -1;
	// }
}