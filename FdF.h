/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:30:33 by vicgarci          #+#    #+#             */
/*   Updated: 2022/11/17 16:15:11 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft_def/libftprintf.h"

# define MAX_ARGS 2

int		parse(int argc, const char **argv);
char	**store_file(int fd);

#endif