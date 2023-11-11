/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderugo <aderugo@42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:21:14 by aderugo           #+#    #+#             */
/*   Updated: 2022/06/30 20:57:03 by aderugo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

int		pipex(char **argv, char **envp);
void	child_process_1(int *end, char **argv, char **envp);
void	child_process_2(int *end, char **argv, char **envp);
void	error_pipe(int *end);
void	error_pid(int *end);
void	error_file(int file, int *end);
void	error_path(char *path, int end);
void	error_execve(char *path, int end);
void	args_check(char *str);
void	pipex_free_1(char *path, char *path_command, char *all_paths);
void	pipex_free_2(char **all_paths, char **command);
char	*get_path(char	*argv, char **envp);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);

#endif