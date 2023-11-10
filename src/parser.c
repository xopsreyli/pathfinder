#include "../inc/pathfinder.h"

void get_data_from_file(char* filename, t_data* data) {
    char* result = mx_file_to_str(filename);

    if (!result) {
        file_not_exist(filename);
    } else if (!mx_strlen(result)) {
        file_is_empty(filename);
    }

    validate(result, data);
}

void validate(char* str, t_data* data) {
    char** lines = mx_strsplit(str, '\n');

    if (!is_number(lines[0])) {
        throw_error(FIRST_LINE_NOT_VALID);
    }
    data->num_of_islands = mx_atoi(lines[0]);

    for (int i = 1; lines[i]; i++) {
        if (!is_line_valid(lines[i])) {
            invalid_line_error(i + 1);
        }
    }

    if (number_of_islands(lines, data) != mx_atoi(lines[0]) || mx_atoi(lines[0]) < 2) {
        throw_error(INVALID_NUMBER_OF_ISLANDS);
    }

    if (check_duplicates(lines) == 1) {
        throw_error(DUPLICATE_BRIDGES);
    }

    if (is_sum_of_bridges_less_int_max(lines) == 0) {
        throw_error(SUM_OF_BRIDGES_TOO_BIG);
    }

    data->lines = lines;
}

int is_line_valid(char* str) {
    if (mx_count_substr(str, ",") != 1) {
        return 0;
    }

    char** splited_info = mx_strsplit(str, ',');

    if (!splited_info[1] || !is_number(splited_info[1])) {
        mx_del_strarr(&splited_info);
        return 0;
    }
    if (mx_count_substr(splited_info[0], "-") != 1) {
        mx_del_strarr(&splited_info);
        return 0;
    }

    char** islands = mx_strsplit(splited_info[0], '-');

    if (!islands[0] || !islands[1] || mx_strcmp(islands[0], islands[1]) == 0) {
        mx_del_strarr(&splited_info);
        mx_del_strarr(&islands);
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        if (!is_alphabetic_only(islands[i])) {
            mx_del_strarr(&splited_info);
            mx_del_strarr(&islands);
            return 0;
        }
    }

    mx_del_strarr(&splited_info);
    mx_del_strarr(&islands);

    return 1;
}

int number_of_islands(char** lines, t_data* data) {
    int size = mx_atoi(lines[0]);

    if (size == 0 && lines[1]) {
        return 1;
    } else if (size > 0 && !lines[1]) {
        return 0;
    }

    char** islands = (char**)malloc(sizeof(char*) * (size + 1));
    int index = 0;

    for (int i = 0; i < size; i++) {
        islands[i] = NULL;
    }

    for (int i = 1; lines[i] ; i++) {
        char** splited_info = mx_strsplit(lines[i], ',');
        char** names = mx_strsplit(splited_info[0], '-');
        for (int j = 0; j < 2; j++) {
            if (island_exist(islands, size, names[j]) == 0) {
                if (index == size) {
                    mx_del_strarr(&splited_info);
                    mx_del_strarr(&names);
                    mx_del_strarr(&islands);
                    return size + 1;
                }
                islands[index++] = mx_strdup(names[j]);
            }
        }
        mx_del_strarr(&splited_info);
        mx_del_strarr(&names);
    }

    data->islands = islands;

    return index;
}

int check_duplicates(char** lines) {
    int size = 0;

    for (int i = 1; lines[i]; i++) {
        size++;
    }

    char*** island_pairs = (char***)malloc((size + 1) * sizeof(char**));
    for (int i = 0; i < size; i++) {
        island_pairs[i] = (char**)malloc(2 * sizeof(char*));
        island_pairs[i][0] = NULL;
        island_pairs[i][1] = NULL;
    }

    int index = 0;

    for (int i = 1; lines[i] ; i++) {
        char** splited_info = mx_strsplit(lines[i], ',');
        char** names = mx_strsplit(splited_info[0], '-');
        mx_bubble_sort(names, 2);
        if (pair_exist(island_pairs, size, names) == 0) {
            island_pairs[index][0] = mx_strdup(names[0]);
            island_pairs[index][1] = mx_strdup(names[1]);
            index++;
        } else {
            for (int j = 0; j < size; j++) {
                free(island_pairs[j][0]);
                free(island_pairs[j][1]);
                free(island_pairs[j]);
            }
            free(island_pairs);

            return 1;
        }
    }

    for (int i = 0; i < size; i++) {
        free(island_pairs[i][0]);
        free(island_pairs[i][1]);
        free(island_pairs[i]);
    }
    free(island_pairs);

    return 0;
}

int is_sum_of_bridges_less_int_max(char** lines) {
    int sum = 0;

    for (int i = 1; lines[i]; i++) {
        char** splited_info = mx_strsplit(lines[i], ',');
        int value = mx_atoi(splited_info[1]);
        if (sum > INT_MAX - value) {
            return 0;
        }
        sum += value;
    }

    return 1;
}
