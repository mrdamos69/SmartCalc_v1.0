#ifndef SRC_S21_SMART_CALC_H_
#define SRC_S21_SMART_CALC_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    NUMBER = 1,
    X = 2,
    PLUS = 3,
    MINUS = 4,
    DIV = 5,
    MULT = 6,
    POW = 7,
    MOD = 8,
    COS = 11,
    SIN = 12,
    TAN = 13,
    ACOS = 14,
    ASIN = 15,
    ATAN = 16,
    SQRT = 17,
    LN = 18,
    LOG = 19,
    LEFT = 20,
    RIGHT = 21
} type_act;

typedef enum {
    HIGH_PR = 3,
    MEDIUM_PR = 2,
    LOW_PR = 1,
    LLOW_PR = -1
} type_priority;

typedef struct list_calc {
    type_priority priority;
    double in_num;
    struct list_calc *next;
    type_act type;
} list_calc;

double input_parsing(char* input, double x);

void push_back(list_calc **head, double in_num, int priority, int type);

void read_num(list_calc** input_calc, char* temp_str, int* flag, int* x);

double calculation(list_calc* head);

double arichmetics (double a, double b, int sumbol);

double triganimetric (double a, int sumbol);

list_calc sort_station(list_calc* head);

list_calc coup_list(list_calc* head);

list_calc pop_back(list_calc **head);

int check_input(const char* input, int size);

// void print_list(const list_calc *head);

#endif  // SRC_S21_SMART_CALC_H_
