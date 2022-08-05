#include "s21_smart_calc.h"

double input_parsing(char* input, double load_x) {
    list_calc* input_calc = NULL;
    double result_output = 0;
    int size_input = strlen(input);
    char* temp_str = calloc(50, sizeof(char));
    int flag = 0;
    if (temp_str) {
        for (int i = 0, x = 0; i <= size_input; i++) {
            switch (input[i]) {
                case '+':
                    if (input[i-1] == '(') {
                        temp_str[x++] = input[i];
                    } else {
                        read_num(&input_calc, temp_str, &flag, &x);
                        push_back(&input_calc, 0, LOW_PR, PLUS);
                        temp_str = calloc(50, sizeof(char));
                    }
                    break;
                case '-':
                    if (input[i-1] == '(') {
                        temp_str[x++] = input[i];
                    } else {
                        read_num(&input_calc, temp_str, &flag, &x);
                        push_back(&input_calc, 0, LOW_PR, MINUS);
                        temp_str = calloc(50, sizeof(char));
                    }
                    break;
                case '*':
                    read_num(&input_calc, temp_str, &flag, &x);
                    push_back(&input_calc, 0, MEDIUM_PR, MULT);
                    temp_str = calloc(50, sizeof(char));
                    break;
                case '/':
                    read_num(&input_calc, temp_str, &flag, &x);
                    push_back(&input_calc, 0, MEDIUM_PR, DIV);
                    temp_str = calloc(50, sizeof(char));
                    break;
                case '^':
                    read_num(&input_calc, temp_str, &flag, &x);
                    push_back(&input_calc, 0, HIGH_PR, POW);
                    temp_str = calloc(50, sizeof(char));
                    break;
                case 'm':  // mod
                    if (input[i+1] == 'o' ? input[i+2] == 'd' ? 1 : 0 : 0) {
                        i+=2;
                        read_num(&input_calc, temp_str, &flag, &x);
                        push_back(&input_calc, 0, MEDIUM_PR, MOD);
                        temp_str = calloc(50, sizeof(char));
                    }
                    break;
                case 'c':  // cos(x)
                    if (input[i+1] == 'o' ? input[i+2] == 's' ? 1 : 0 : 0) {
                        i+=2;
                        push_back(&input_calc, 0, HIGH_PR, COS);
                    }
                    break;
                case 's':  // sin(x) // sqrt(x)
                    if (input[i+1] == 'i' ? input[i+2] == 'n' ? 1 : 0 : 0) {
                        i+=2;
                        push_back(&input_calc, 0, HIGH_PR, SIN);
                    }
                    if (input[i+1] == 'q' ? input[i+2] == 'r' ? input[i+3] == 't' ? 1 : 0 : 0 : 0) {
                        i+=3;
                        push_back(&input_calc, 0, HIGH_PR, SQRT);
                    }
                    break;
                case 't':  // tan(x)
                    if (input[i+1] == 'a' ? input[i+2] == 'n' ? 1 : 0 : 0) {
                        i+=2;
                        push_back(&input_calc, 0, HIGH_PR, TAN);
                    }
                    break;
                case 'a':  // acos(x) // asin(x) // atan(x)
                    if (input[i+1] == 'c' ? input[i+2] == 'o' ? input[i+3] == 's' ? 1 : 0 : 0 : 0) {
                        i+=3;
                        push_back(&input_calc, 0, HIGH_PR, ACOS);
                    }
                    if (input[i+1] == 's' ? input[i+2] == 'i' ? input[i+3] == 'n' ? 1 : 0 : 0 : 0) {
                        i+=3;
                        push_back(&input_calc, 0, HIGH_PR, ASIN);
                    }
                    if (input[i+1] == 't' ? input[i+2] == 'a' ? input[i+3] == 'n' ? 1 : 0 : 0 : 0) {
                        i+=3;
                        push_back(&input_calc, 0, HIGH_PR, ATAN);
                    }
                    break;
                case 'l':  // ln(x) // log(x)
                    if (input[i+1] == 'n' ?  1 : 0) {
                        i+=1;
                        push_back(&input_calc, 0, HIGH_PR, LN);
                    }
                    if (input[i+1] == 'o' ? input[i+2] == 'g' ? 1 : 0 : 0) {
                        i+=2;
                        push_back(&input_calc, 0, HIGH_PR, LOG);
                    }
                    break;
                case '(':
                    push_back(&input_calc, 0, LLOW_PR, LEFT);
                    break;
                case ')':
                    read_num(&input_calc, temp_str, &flag, &x);
                    push_back(&input_calc, 0, LLOW_PR, RIGHT);
                    temp_str = calloc(50, sizeof(char));
                    break;
                case 'x': push_back(&input_calc, load_x, 0, 0); break;
                case '.': temp_str[x++] = input[i]; flag = 1; break;
                case '0': temp_str[x++] = input[i]; flag = 1; break;
                case '1': temp_str[x++] = input[i]; flag = 1; break;
                case '2': temp_str[x++] = input[i]; flag = 1; break;
                case '3': temp_str[x++] = input[i]; flag = 1; break;
                case '4': temp_str[x++] = input[i]; flag = 1; break;
                case '5': temp_str[x++] = input[i]; flag = 1; break;
                case '6': temp_str[x++] = input[i]; flag = 1; break;
                case '7': temp_str[x++] = input[i]; flag = 1; break;
                case '8': temp_str[x++] = input[i]; flag = 1; break;
                case '9': temp_str[x++] = input[i]; flag = 1; break;
                default:
                    read_num(&input_calc, temp_str, &flag, &x);
                    temp_str = calloc(50, sizeof(char));
                    break;
            }
        }
        free(temp_str);
    }
    if (!check_input(input, size_input)) {
        if (input_calc != NULL) {*input_calc = coup_list(input_calc);}
        if (input_calc != NULL) {*input_calc = sort_station(input_calc);}
        if (input_calc != NULL) {*input_calc = coup_list(input_calc);}
        result_output = calculation(input_calc);
    }
    return result_output;
}

list_calc sort_station(list_calc* head) {
    list_calc *result = NULL;
    list_calc *temp = NULL;
    while (head) {
        int menu = head->priority;
        switch (menu) {
        case 0: push_back(&result, head->in_num, 0, 0); break;
        default:
            if (temp != NULL) {
                if ((head->priority > temp->priority) || (head->type == LEFT)) {
                    push_back(&temp, 0, head->priority, head->type);
                } else {
                    if (head->type == RIGHT) {
                        while (temp && (temp->type != LEFT)) {
                            push_back(&result, 0, temp->priority, temp->type);
                            temp = temp->next;
                        }
                    } else {
                        push_back(&result, 0, temp->priority, temp->type);
                        pop_back(&temp);
                    }
                    push_back(&temp, 0, head->priority, head->type);
                    if (result->type < COS) {
                        if (temp->type == RIGHT) {pop_back(&temp);}
                        if (temp->type == LEFT) {pop_back(&temp);}
                    }
                }
            } else {
                push_back(&temp, 0, head->priority, head->type);
            }
            break;
        }
        head = head->next;
    }
    while (temp) {
        if (temp->type != LEFT &&  temp->type != RIGHT)
            push_back(&result, 0, temp->priority, temp->type);
        temp = temp->next;
    }
    while (head) {
        pop_back(&head);
        head = head->next;
    }
    return *result;
}

double calculation(list_calc* head) {
    list_calc *temp = NULL;
    double result = 0;
    int count = 2;
    double a = 0;
    double b = 0;
    while (head) {
        if (head->priority == 0) {
            push_back(&temp, head->in_num, 0, 0);
        } else if ((head->priority > 0) && (head->type < COS && head->type > 0)) {
            while (temp) {
                if (count == 2) {
                    b = temp->in_num;
                } else if (count == 1) {
                    a = temp->in_num;
                } else  if (count == 0) {
                    break;
                }
                count--;
                temp = temp->next;
            }
            if (count == 0) {
                push_back(&temp, arichmetics(a, b, head->type), 0, 0);
            }
            count = 2;
        } else if ((head->priority > 0) && (head->type > MOD && head->type < LEFT)) {
            while (temp) {
                if (count == 2) {
                    b = temp->in_num;
                } else  if (count == 1) {
                    break;
                }
                count--;
                temp = temp->next;
            }
            if (count == 1) {
                push_back(&temp, triganimetric(b, head->type), 0, 0);
            }
            count = 2;
        }
        head = head->next;
    }
    if (temp != NULL) {result = temp->in_num;}
    return result;
}

double arichmetics(double a, double b, int sumbol) {
    double result = 0;
    if (sumbol == PLUS) {result = a + b;}
    if (sumbol == MINUS) {result = a - b;}
    if (sumbol == DIV) {result = a / b;}
    if (sumbol == MULT) {result = a * b;}
    if (sumbol == POW) {result = pow(a, b);}
    if (sumbol == MOD) {result = fmod(a, b);}
    return result;
}

double triganimetric(double a, int sumbol) {
    double result = 0;
    if (sumbol == COS) {result = cos(a);}
    if (sumbol == SIN) {result = sin(a);}
    if (sumbol == TAN) {result = tan(a);}
    if (sumbol == ACOS) {result = acos(a);}
    if (sumbol == ASIN) {result = asin(a);}
    if (sumbol == ATAN) {result = atan(a);}
    if (sumbol == SQRT) {result = sqrt(a);}
    if (sumbol == LN) {result = log(a);}
    if (sumbol == LOG) {result = log10(a);}
    return result;
}

void read_num(list_calc** input_calc, char* temp_str, int* flag, int* x) {
    if (*flag && temp_str) {
        push_back(input_calc, atof(temp_str), 0, 0);
        *x = 0;
        *flag = 0;
        free(temp_str);
    }
}

list_calc coup_list(list_calc* head) {
    list_calc *temp = NULL;
    while (head) {
        push_back(&temp, head->in_num, head->priority, head->type);
        head = head->next;
    }
    while (head) {
        pop_back(&head);
        head = head->next;
    }
    return *temp;
}

void push_back(list_calc **head, double in_num, int priority, int type) {
    list_calc *temp = calloc(1 , sizeof(list_calc));
    temp->in_num = in_num;
    temp->priority = priority;
    temp->type = type;
    temp->next = *head;
    *head = temp;
}

list_calc pop_back(list_calc **head) {
    list_calc* ptr = NULL;
    list_calc temp = {0};
    ptr = (*head);
    temp.in_num = ptr->in_num;
    temp.priority = ptr->priority;
    temp.type = ptr->type;
    (*head) = (*head)->next;
    free(ptr);
    return temp;
}

int check_input(const char* input, int size) {
    int check = 0;
    for (int i = 0; i < size; i++) {
        if (input[i] == '(') {check = (input[i+1] == ')' ? 1 : check);}
        if (input[i] == ')') {check = (input[i+1] == '(' ? 1 : check);}
    }
    return check;
}
