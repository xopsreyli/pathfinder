#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        throw_error(USAGE_ERROR);
    }

    t_data* data = (t_data*)malloc(sizeof(t_data));

    get_data_from_file(argv[1], data);
    build_matrices(data);
    floyd_algo(data);
    mx_output(data);

    return 0;
}
