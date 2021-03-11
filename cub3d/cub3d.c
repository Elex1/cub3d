/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melghoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:41:12 by melghoud          #+#    #+#             */
/*   Updated: 2021/03/11 11:41:15 by melghoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
    int fd;
    char *line;
    int ret;

    if (argc < 2 || argc > 3)
    {
        printf ("Error\n error in args\n");
        exit (0);
    }
    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            printf("Error\n error in mapfile\n");
            exit(0);
        }
        if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
        {
            printf("Error\n mapfile doesnt end with ".cub"\n");
            exit (0);
        }
        while ((ret = get_next_line(fd, &line)) > 0)
        {
            
        }

    }


}


int     check_resolution(char *line, t_args *args)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != ' ' && !ft_isdigit(line[i]))
            return (-1);
        i++;
    }
    i = 0;
    line = ft_strtrim(line + 2, " ");
    while (line[i])
    {
        if (ft_isdigit(line[i]) && line[i] != ' ')
            args->width.res = ft_atoi(line + i);
        i += num_lenght(line);
        args->height.res = ft_atoi(line + i);
    }
    
}

int		num_lenght(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		if (str[i] == ',')
			break ;
		if (str[i] == ' ')
		{
			i++;
			if (ft_isdigit(str[i]))
				return (i);
		}
	}
	return (i);
}