#include "../inc/pathfinder.h"

int is_number(char* num) {
    int i = 0;

    while (num[i]) {
        if (num[i] < '0' || num[i] > '9') {
            return 0;
        }
        i++;
    }

    return 1;
}

int is_alphabetic_only(char* str) {
    int i = 0;

    while (str[i]) {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
            return 0;
        }
        i++;
    }

    return 1;
}

int mx_atoi(const char* str) {
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        result = result * 10 + (str[i] - '0');
    }

    return result;
}

int island_exist(char** islands, int size, char* island) {
    for (int i = 0; i < size && islands[i]; i++) {
        if (mx_strcmp(islands[i], island) == 0) {
            return 1;
        }
    }

    return 0;
}

int pair_exist(char*** pairs, int size, char** pair) {
    for (int i = 0; i < size && pairs[i][0] && pairs[i][1]; i++) {
        if (mx_strcmp(pairs[i][0], pair[0]) == 0 && mx_strcmp(pairs[i][1], pair[1]) == 0) {
            return 1;
        }
    }

    return 0;
}

int get_index_of_island(t_data* data, char* island) {
    for (int i = 0; data->islands[i] ; i++) {
        if (mx_strcmp(island, data->islands[i]) == 0) {
            return i;
        }
    }

    return 0;
}

void duplicate_matrix(t_data* data) {
    data->matrix = (int **)malloc(sizeof(int *) * data->num_of_islands);

    for (int i = 0; i < data->num_of_islands; i++) {
        data->matrix[i] = (int *)malloc(sizeof(int *) * data->num_of_islands);
    }

    for (int i = 0; i < data->num_of_islands; i++) {
        for (int j = i; j < data->num_of_islands; j++) {
            data->matrix[i][j] = data->original_matrix[i][j];
            data->matrix[j][i] = data->original_matrix[j][i];
        }
    }
}

void clean_memory(t_data* data) {
    for (int i = 0; i < data->num_of_islands; i++) {
        free(data->original_matrix[i]);
        free(data->matrix[i]);
    }
    free(data->original_matrix);
    free(data->matrix);
    data->num_of_islands = 0;
    mx_del_strarr(&data->islands);
    mx_del_strarr(&data->lines);
}
