/*
** EPITECH PROJECT, 2023
** B-NWP-400-MAR-4-1-myteams-niels.ouvrard
** File description:
** load_infos
*/

#include "my_server.h"

char *filepath_to_str(char *filepath)
{
    int fp = open(filepath, O_RDONLY);
    if (!fp)
        return NULL;
    int buff_size = 32000, offset = 0, len = 0;
    char *buff = malloc(sizeof(char) * buff_size);
    while ((len = read(fp, buff + offset, buff_size - offset)) > 0)
        offset += len;
    close(fp);
    if (len < 0)
        return NULL;
    buff[offset] = '\0';
    return buff;
}

char **load_infos(char *file_path)
{
    char *line = NULL;
    size_t len = 0;
    FILE *fd = fopen(file_path, "r");
    char **infos = NULL;
    int i = 0;
    while (getline(&line, &len, fd) != -1) {
        char *tmp = strdup(line);
        infos = realloc(infos, sizeof(char *) * (i + 1));
        infos[i] = tmp;
        i++;
    }
    infos = realloc(infos, sizeof(char *) * (i + 1));
    infos[i] = NULL;
    fclose(fd);
    return infos;
}

char **find_content(char *file_path, char *loking_for)
{
    char *line = NULL;
    size_t len = 0;
    char **infos = NULL;
    FILE *fd = fopen(file_path, "r");
    if (fd == NULL) {
        return NULL;
    }
    while (getline(&line, &len, fd) != -1) {
        if (strstr(line, loking_for) != NULL) {
            infos = load_infos(file_path);
            break;
        }
    }
    fclose(fd);
    return infos;
}
