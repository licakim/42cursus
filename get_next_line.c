
#include<stdlib.h>
#include<unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}


char *ft_strdup(char *src)
{
	int len = ft_strlen(src);
	char *dest = malloc(sizeof(char) *(len + 1));
	int i = 0;

	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return dest;
}

char *get_next_line(int fd)
{
	char buffer;
	char str[7000000] = {0,};
	int rsize;
	int i = 0;
	if (fd < 0)
		return 0;
	rsize = read(fd, &buffer, 1);
	while(rsize > 0)
	{
		str[i++] = buffer;
		if (buffer == '\n')
			break;
		rsize = read(fd, &buffer, 1);
	}
	if(rsize <= 0 && i == 0)
		return (0);
	return (ft_strdup(str));
}

// #include <fcntl.h>
// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	int fd = open(argv[1], O_RDONLY);
// 	char *str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// }