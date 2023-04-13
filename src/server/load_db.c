/*
** EPITECH PROJECT, 2023
** B-NWP-400-MAR-4-1-myteams-niels.ouvrard
** File description:
** load_db
*/

#include "my_server.h"

void initialize_message_db(server **serv)
{
    int result;
    if (sqlite3_open("data/messages.db", &(*serv)->messages_db) != SQLITE_OK)
        error_sql(*serv, "Can't open database: %s\n");
    result = sqlite3_prepare_v2((*serv)->messages_db, CREATE_MESSAGES_DB, -1,
    &(*serv)->stmt, NULL);
    if (result != SQLITE_OK)
        error_sql(*serv, "Failed to prepare statement: %s\n");
    result = sqlite3_step((*serv)->stmt);
    if (result != SQLITE_DONE)
        error_sql(*serv, "Failed to execute statement: %s\n");
    result = sqlite3_finalize((*serv)->stmt);
    if (result != SQLITE_OK)
        error_sql(*serv, "Failed to finalize statement: %s\n");
}

void initialize_user_db(server **serv)
{
    int result;
    if (sqlite3_open("data/users.db", &(*serv)->users_db) != SQLITE_OK)
        error_sql(*serv, "Can't open database: %s\n");
    result = sqlite3_prepare_v2((*serv)->users_db, CREATE_USER_DB, -1,
    &(*serv)->stmt, NULL);
    if (result != SQLITE_OK)
        error_sql(*serv, "Failed to prepare statement: %s\n");
    result = sqlite3_step((*serv)->stmt);
    if (result != SQLITE_DONE)
        error_sql(*serv, "Failed to execute statement: %s\n");
    result = sqlite3_finalize((*serv)->stmt);
    if (result != SQLITE_OK)
        error_sql(*serv, "Failed to finalize statement: %s\n");
}

void initialize_group_db(server **serv)
{
    int result;
    if (sqlite3_open("data/groups.db", &(*serv)->groups_db) != SQLITE_OK)
        error_sql(*serv, "Can't open database: %s\n");
    result = sqlite3_prepare_v2((*serv)->groups_db, CREATE_GROUP_DB, -1,
    &(*serv)->stmt, NULL);
    if (result != SQLITE_OK)
        error_sql(*serv, "Failed to prepare statement: %s\n");
    result = sqlite3_step((*serv)->stmt);
    if (result != SQLITE_DONE)
        error_sql(*serv, "Failed to execute statement: %s\n");
    result = sqlite3_finalize((*serv)->stmt);
    if (result != SQLITE_OK)
        error_sql(*serv, "Failed to finalize statement: %s\n");
}

void initialize_db(server **serv)
{
    initialize_user_db(serv);
    initialize_message_db(serv);
    initialize_group_db(serv);
}
