/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** manage event
*/

#include "my_rpg.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void rand_combat(game_t *game, object_t *obj)
{
    int n = 0;

    if (game->stock == 'B' && game->screen == 1 && obj->quest >= 2) {
        n = randint(0, 100);
        if (n > 80) {
            find_randpoke(game);
            load_poke_sprites(game->combat);
            game->screen = 5;
        }
    }
}

void manage_events_2(game_t *game, object_t *obj, sfEvent *event)
{
    if (game->screen == 1) {
        game->time_2 = sfClock_getElapsedTime(game->clock_2);
        game->second_2 = game->time_2.microseconds / 50000;
        if (game->second_2 > 1) {
            move_hero_1(event, obj, game);
            sfClock_restart(game->clock_2);
        }
    }
    if (game->screen == 4)
        text_box_manager(game->cheatcode, game->window, event);
}

void manage_events(game_t *game, object_t *obj)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        game->mouse = sfMouse_getPositionRenderWindow(game->window);
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyDelete))
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtMouseButtonPressed) {
            obj->moused = 1;
            sfMusic_play(game->click);
        }
        else obj->moused = 0;
        if (event.type == sfEvtMouseButtonReleased)
            obj->clicked = 1;
        else obj->clicked = 0;
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->screen == 1)
            game->screen = 2;
        manage_events_2(game, obj, &event);
    }
}
