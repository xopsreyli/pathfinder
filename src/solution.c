#include "../inc/pathfinder.h"

void build_matrices(t_data* data) {
    data->original_matrix = (int **)malloc(sizeof(int *) * data->num_of_islands);

    for (int i = 0; i < data->num_of_islands; i++) {
        data->original_matrix[i] = (int *)malloc(sizeof(int *) * data->num_of_islands);
        for (int j = 0; j < data->num_of_islands; j++) {
            if (i == j) {
                data->original_matrix[i][j] = 0;
            } else {
                data->original_matrix[i][j] = INT_MAX;
            }
        }
    }

    for (int i = 1; data->lines[i] ; i++) {
        char** splited_info = mx_strsplit(data->lines[i], ',');
        char** islands = mx_strsplit(splited_info[0], '-');

        int island_1_index = get_index_of_island(data, islands[0]);
        int island_2_index = get_index_of_island(data, islands[1]);

        data->original_matrix[island_1_index][island_2_index] = mx_atoi(splited_info[1]);
        data->original_matrix[island_2_index][island_1_index] = mx_atoi(splited_info[1]);
    }

    duplicate_matrix(data);
}

void floyd_algo(t_data* data) {
    for (int k = 0; k < data->num_of_islands; k++) {
        for (int i = 0; i < data->num_of_islands; i++) {
            for (int j = i + 1; j < data->num_of_islands; j++) {
                if (data->matrix[k][j] != INT_MAX &&
                    data->matrix[i][k] != INT_MAX &&
                    data->matrix[i][k] + data->matrix[k][j] < data->matrix[i][j])
                {
                    data->matrix[i][j] = data->matrix[i][k] + data->matrix[k][j];
                    data->matrix[j][i] = data->matrix[i][k] + data->matrix[k][j];
                }
            }
        }
    }
}
