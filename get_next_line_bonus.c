/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:27:17 by jmatheis          #+#    #+#             */
/*   Updated: 2022/05/16 13:24:13 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*singleline(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (text[i] == '\0')
		return (NULL);
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*nexttext(char *text)
{
	char	*newtext;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	newtext = malloc((ft_strlen(text) - i + 1) * sizeof(char));
	if (newtext == NULL)
		return (NULL);
	i++;
	while (text[i] != '\0')
		newtext[j++] = text[i++];
	newtext[j] = '\0';
	free(text);
	return (newtext);
}

static char	*readingtext(int fd, char *text)
{
	int		readtext;
	char	*buffer;

	readtext = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (readtext != 0 && ft_strchr(text, '\n') == NULL)
	{
		readtext = read(fd, buffer, BUFFER_SIZE);
		if (readtext == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[readtext] = '\0';
		text = ft_strjoin(text, buffer);
	}
	free(buffer);
	return (text);
}

//taking the text from the specific fd
//static char is up to date
char	*get_next_line(int fd)
{
	static char	*text[OPEN_MAX];
	char		*returnline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	text[fd] = readingtext(fd, text[fd]);
	if (text[fd] == NULL)
		return (NULL);
	returnline = singleline(text[fd]);
	text[fd] = nexttext(text[fd]);
	return (returnline);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*line;
// 	int		fd1;
// 	int		fd2;
// 	char	*filename1 = "../getnextline/file1";
// 	char	*filename2 = "../getnextline/file2";

// 	fd2 = open(filename2, O_RDONLY);
// 	line = get_next_line(fd1);
// 	printf("%s\n", line);
// 	line = get_next_line(fd1);
// 	printf("%s\n", line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("%s\n", line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("%s\n", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("%s\n", line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("%s\n", line);
// 	free(line);
// 	line = get_next_line(fd1);
// 	printf("%s\n", line);
// 	free(line);
// 	line = get_next_line(fd2);
// 	printf("%s\n", line);
// 	free(line);
// 	system("leaks a.out");
//  	return (0);
// } 