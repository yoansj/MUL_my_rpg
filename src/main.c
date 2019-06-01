/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** main.c
*/

#include "my_rpg.h"

void destroy_game(game_t *game, object_t *obj)
{
    free_array(102, game->tab);
    sfRenderWindow_destroy(game->window);
    for (int i = 0; i <= 49; i++)
        sfSprite_destroy(obj[i].spr);
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->inv);
    sfMusic_destroy(game->step);
    sfMusic_destroy(game->bad);
    sfMusic_destroy(game->click);
    sfMusic_destroy(game->dmg);
    sfMusic_destroy(game->buy);
    sfMusic_destroy(game->fight);
}

int help(void)
{
    write(1, "A RPG game created with CSFML.\n\n\n", 33);
    write(1, "Z on keyboard : to move foreward\n", 33);
    write(1, "S on keyboard : to move backward\n", 33);
    write(1, "Q on keyboard : to move on the left\n", 36);
    write(1, "D on keyboard : to move on the right\n", 37);
    write(1, "I on keyboard : to open the inventory\n", 38);
    write(1, "Suppr to leave the game\n", 24);
    write(1, "Escape to pause the game\n\n", 26);
    write(1, "GOOD LUCK AND HAVE FUN!!\n", 25);
    return (0);
}

int main(int arc, char **arg, char **env)
{
    object_t *obj = malloc(sizeof(object_t) * 50);
    game_t *game = malloc(sizeof(game_t));

    if (arc == 2 && arg[1][0] == '-' && arg[1][1] == 'h' && !arg[1][2])
        return (help());
    if (arc != 1 || env[0] == NULL) {
        write(2, "Bad Argument\n", 13);
        return (84);
    }
    if (check_env(env) == 0)
        return (84);
    srand(time(NULL));
    load_window(game);
    obj = load_object(obj);
    init_game_variables(game, obj);
    game_loop(game, obj);
    destroy_game(game, obj);
    return (0);
}
