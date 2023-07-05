/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:58:22 by sabrifer          #+#    #+#             */
/*   Updated: 2023/06/25 16:07:03 by sabrifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_LIB_H
# define FUNCTIONS_LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strchar(char *str, char to_find);
char	*ft_strstr(char *str, char *to_find);
char	*store_zeros(char *str, int size);
char	*ft_strdup(char *src);
char	*ft_numtostr(int num);
int		ft_atoi(char *str);
int		ft_is_spaced(char c);
int		ft_strlen(char *str);
int		ft_power(int nb, int power);
void	ft_strrev(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	create_matrix(int **matrix, char *argv);
void	print_matrix(int is_empty, int **matrix, int dict_file, char *indict);
void	print_num(char *argv, int fd, char *indict);
int		row_sum(int *row);
void	ft_print(char *end);
void	print_col_zero(int num, int dict_file, char *in_dict);
void	print_to_20(int **matrix, int row, int dict_file, char *in_dict);
void	print_starting_20(int **matrix, int row, int dict_file, char *in_dict);
void	print_other_cols(int **matrix, int row, int dict_file, char *in_dict);

#endif