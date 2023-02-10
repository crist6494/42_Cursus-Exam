#include <unistd.h>
#include <stdlib.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif


int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

int ft_strchr(char *str, char c)
{
	int i = 0;

	if(!str)
		return (0);
	while (str[i])
	{
		if(str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int len; 
	char *str;
	 if (!s2)
        return (NULL);
    if (!s1)
    {
        s1 = malloc(1);
        s1[0] = '\0';
    }
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if(!str)
		return (NULL);

	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char *read_line(int fd, char *line)
{
		int		i;
	char	*buff;

	i = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (i != 0 && ft_strchr(line, '\n') == 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		if (i == 0)
			break ;
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i += (line[i] == '\n');
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = line[j];
		j++;
	}
	str[j] = '\0';
	if (str[0] == '\0')
		return (NULL);
	return (str);
}

char *remove_line(char *line)
{
	int i = 0;
	int j = 0;
	int len;
	char *str;

	while (line[i] && line[i] != '\n')
		i++;
	i += (line[i] == '\n');
	len = ft_strlen(line) - i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if(!str)
		return (NULL);
	while(line[i])
	{
		str[j] = line[i];
		j++;
		i++;
	}
	str[j]= '\0';
	free(line);
	if(str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char *get_next_line(int fd)
{
	char *line;
	static char *buff;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	buff = read_line(fd, buff);
	if(!buff)
		return (NULL);
	line = get_line(buff);
	buff = remove_line(buff);
	return (line);
}


#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		line;
	char	*string;
	line = 1;
	//string = NULL;
	fd = open("test.txt", O_RDONLY);
	//string = get_next_line(fd);
 	while (string != NULL)
	{
		string = get_next_line(fd);
		printf("Line %d - %s ", line, string);
		line++;
	} 
	if (!string)
		printf("Line %d - (null) EOF", line);
	close(fd);
	return (0);
}
