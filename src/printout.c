#include "../inc/pathfinder.h"

void mx_output(t_data* data) {
    t_output *output = (t_output *)malloc(sizeof(t_output));

    output->path = (int *)malloc(sizeof(int) * (data->num_of_islands + 1));
    for (int i = 0; i < data->num_of_islands; i++) {
        for ( int j = i + 1; j < data->num_of_islands; j++) {
            output->value = 1;
            output->path[0] = j;
            output->path[1] = i;
            shortest_path(data, output);
        }
    }
    free(output->path);
    free(output);

    clean_memory(data);
}

void shortest_path(t_data* data, t_output *output) {
    int i = output->path[output->value];
    int j = output->path[0];

    for (int k = 0; k < data->num_of_islands; k++) {
        if (k != output->path[output->value]
            && (data->original_matrix[i][k] == data->matrix[i][j] - data->matrix[k][j])) {
            output->value++;
            output->path[output->value] = k;
            shortest_path(data, output);
            output->value--;
        }
    }
    if (output->path[output->value] != output->path[0])
        return;
    print_output_path(data, output);
    print_output_value(data, output);
}

void print_output_path(t_data* data, t_output *output) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(data->islands[output->path[1]]);
    mx_printstr(" -> ");
    mx_printstr(data->islands[output->path[0]]);
    mx_printstr("\n");
    mx_printstr("Route: ");
    for (int i = 1; i < output->value + 1;) {
        mx_printstr(data->islands[output->path[i]]);
        if (++i < output->value + 1)
            mx_printstr(" -> ");
    }
    mx_printstr("\n");
}

void print_output_value(t_data* data, t_output *output) {
    int sum = 0;

    mx_printstr("Distance: ");
    for (int i = 1; i < output->value; i++) {
        mx_printint(data->original_matrix[output->path[i]][output->path[i + 1]]);
        sum += data->original_matrix[output->path[i]][output->path[i + 1]];
        if (i < output->value - 1)
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
    mx_printstr("========================================\n");
}
