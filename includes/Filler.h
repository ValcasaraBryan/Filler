/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:51:59 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/16 18:26:46 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct			s_file
{
	char				*file;
	struct s_file		*next;
}						t_file;

typedef struct			s_tailles_map
{
	int					x_map;
	int					y_map;
	int					**map_chaleur;
	char				me;
	char				ennemi;
	char				**map;
	int					**me_list;
	int					**ennemi_list;
}						t_coor;

typedef struct			s_tailles_piece
{
	int					x_piece;
	int					y_piece;
	int					x_best_pos;
	int					y_best_pos;
	int					x_final_pos;
	int					y_final_pos;
	int					**last_best_pos;
	int					**pos_stars;
	int					**final_pos;
	char				**piece;
}						t_coor_piece;
/*
**          mappage.c
*/
int						val_around(t_coor *map, int val, int x, int y);
int						check_position_right_down(t_coor *map);
int						check_position_left_up(t_coor *map);
int						check_position_right_up(t_coor *map);
int						check_position_left_down(t_coor *map);
/*
**          before_mappage.c
*/
int						chaleur_down(t_coor *map, int y);
int						chaleur_up(t_coor *map, int y);
int						chaleur_right(t_coor *map, int x);
int						chaleur_left(t_coor *map, int x);
int						after_mappage(t_coor *map);
/*
**          map_chaleur.c
*/
int						val_player_fct(t_coor *map, int x, int y);
int						map_chaleur_vertical(t_coor *map);
int						map_chaleur_horizontal(t_coor *map);
/*
**          genere_list.c
*/
char					**tab_char(size_t len);
int						check_tab(char **tab);
int						check_char_piece(char *str);
int						check_char(char *str);
int						check_y_map(char *str, size_t len);
/*
**          utils.c
*/
int						nb_tab(t_coor *map, int **tab);
int						nb_tab_str(char **tab);
int						ft_print(int x, int y);
/*
**          allocation.c
*/
int						tab_int(t_coor *map, char char_of_player);
int						init_last_best_pos(t_coor *map, t_coor_piece *piece);
int						final_pos_piece(t_coor *map, t_coor_piece *piece);
int						pos_piece(t_coor_piece *piece);
/*
**          check_chaleur.c
*/
int						next_pos_stars(t_coor *map, t_coor_piece *piece);
int						check_chaleur_piece(t_coor *map, t_coor_piece *piece,
						int x, int y);
int						check_pos_final(t_coor *map, t_coor_piece *piece);
/*
**          check_pos_map.c
*/
int						best_position(t_coor *map, int x, int y, int val);
int						check_overflow(t_coor *map, t_coor_piece *piece,
						int best_pos);
int						check_around_pos(t_coor *map, t_coor_piece *piece);
int						check_arount_best_pos_piece(t_coor *map,
						t_coor_piece *piece, int x, int y);
int						check_around_best_pos(t_coor *map, t_coor_piece *piece);
/*
**          norm_init_val.c
*/
t_file					*free_init_map_piece(t_coor *map, t_coor_piece *piece,
						t_file **file, char **line);
t_file					*free_init_val(t_coor *map, t_coor_piece *piece,
						t_file **file, char **line);
t_file					*norm_pars(t_file *file, char **line);

/*
**          init_val.c
*/
int						init_list_filler(t_coor *map,
						t_coor_piece *piece, int player);
int						error(char **line);
t_file					*new_file(char *line);
t_file					*add_file(t_file *file, char *line);
t_file					*read_fd(t_coor *map, t_coor_piece *piece);
/*
**          liberation.c
*/
int						free_tab_int(int ***tab, int size);
int						free_line(char **line);
int						free_tab_str(char ***str);
int						erase_file(t_file *file);
/*
**          parsing_map.c
*/
int						plateau_val(t_coor *map, char *line);
int						norm(char ***tab);
int						norm_two(char ***tab);
int						parsing_map(t_coor *map, char *line);
/*
**          parsing_piece.c
*/
int						parsing_piece(t_coor_piece *piece, char *line);
int						alloc_first_step(t_coor *map);
int						alloc_second_step(t_coor *map, t_coor_piece *piece);
/*
**          norm_main.c
*/
int						norm_main_alloc(t_coor *map, t_coor_piece *piece);
void					norm_main_while(t_coor *map, t_coor_piece *piece);
int						put_solve(t_coor *map, t_coor_piece *piece);
/*
**          main.c
*/
int						erase_all_malloc(t_coor *map,
						t_coor_piece *piece);
int						first_step(t_coor *map);
int						second_step(t_coor *map, t_coor_piece *piece);
int						read_player(t_coor *map, t_coor_piece *piece,
						char *argv);
#endif
