#ifndef OBOLTENKOV_PATHFINDER_H
#define OBOLTENKOV_PATHFINDER_H

#include "../libmx/inc/libmx.h"
#include "limits.h"

#define USAGE_ERROR "usage: ./pathfinder [filename]"
#define FIRST_LINE_NOT_VALID "error: line 1 is not valid"
#define INVALID_NUMBER_OF_ISLANDS "error: invalid number of islands"
#define DUPLICATE_BRIDGES "error: duplicate bridges"
#define SUM_OF_BRIDGES_TOO_BIG "error: sum of bridges lengths is too big"

typedef struct s_data {
    int num_of_islands;
    char** islands;
    char** lines;
    int** original_matrix;
    int** matrix;
} t_data;

typedef struct s_output {
    int value;
    int* path;
} t_output;

void throw_error(const char* error);
void file_not_exist(char* filename);
void file_is_empty(char* filename);
void invalid_line_error(int line_number);

void get_data_from_file(char* filename, t_data* data);
void validate(char* str, t_data* data);
int is_line_valid(char* str);
int number_of_islands(char** lines, t_data* data);
int check_duplicates(char** lines);
int is_sum_of_bridges_less_int_max(char** lines);

void build_matrices(t_data* data);
void floyd_algo(t_data* data);

void mx_output(t_data* data);
void shortest_path(t_data* data, t_output *output);
void print_output_path(t_data* data, t_output *output);
void print_output_value(t_data* data, t_output *output);

int is_number(char* num);
int is_alphabetic_only(char* str);
int mx_atoi(const char* str);
int island_exist(char** islands, int size, char* island);
int pair_exist(char*** pairs, int size, char** pair);
int get_index_of_island(t_data* data, char* island);
void duplicate_matrix(t_data* data);
void clean_memory(t_data* data);

#endif //OBOLTENKOV_PATHFINDER_H
