/*
** EPITECH PROJECT, 2023
** B-NWP-400-MAR-4-1-myteams-niels.ouvrard
** File description:
** command_handler
*/

#include "my_server.h"

void command_handler(server **serv, client **cli_list,
client *current_client, int sd)
{
    if (!(*serv)->command || !(*serv)->command[0])
        return;
    for (int i = 0; i < NB_COMMANDS; i++) {
        if (strcmp((*serv)->fct[i].name, (*serv)->command[0]) == 0) {
            (*serv)->fct[i].fct(serv, cli_list, current_client, sd);
            return;
        }
    }
    send(sd, "590 Invalid command.\n", 21, 0);
}

char **get_command(int sd)
{
    char buffer[1024] = {0};
    recv(sd, buffer, 1024, 0);
    char **command = my_str_to_word_array(buffer);
    return command;
}

void error_sql(server *serv, char *error)
{
    fprintf(stderr, error, sqlite3_errmsg(serv->users_db));
    exit (84);
}

void change_status_user (server **serv, const char *uuid_text, int status)
{
    char request[1024];
    sprintf(request, "UPDATE users SET connected = %d WHERE uuid = %s",
    status, uuid_text);
    sqlite3_prepare_v2((*serv)->users_db, request, -1, &(*serv)->stmt, NULL);
}
