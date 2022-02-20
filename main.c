#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/* A IMPLEMENTER:
 * -eq -> equal
 * -ge -> greater or equal
 * -gt -> greater
 * -le -> lower or equal
 * -lt -> lower
 * -ne -> non equal
 */

int convert(const char * n, long * a){
    char *end;
    long m = strtol(n, &end, 10);
    if (*end != '\0') {
        *a = 0;
        return 0;
    }
    else {
        *a = m;
        return 1;
    }
}

int eq(long a, long b){
    return a == b;
}

int ge(long a, long b){
    return a >= b;
}

int gt(long a, long b){
    return a > b;
}

int le(long a, long b){
    return a <= b;
}

int lt(long a, long b){
    return a < b;
}

int ne(long a, long b){
    return a != b;
}

int run(int argc, char * argv[]){

    if (argc != 4) return 2; //error case bad arguments number

    long a;
    long b;
    if (!(convert(argv[1], &a) &&  convert(argv[3], &b))) {
        return 3; // error case bad integer input
    }

    char * flag = argv[2];

    if (strcmp(flag, "-eq") == 0) return !eq(a, b);
    else if (strcmp(flag, "-ge") == 0) return !ge(a, b);
    else if (strcmp(flag, "-gt") == 0) return !gt(a, b);
    else if (strcmp(flag, "-le") == 0) return !le(a, b);
    else if (strcmp(flag, "-lt") == 0) return !lt(a, b);
    else if (strcmp(flag, "-ne") == 0) return !ne(a, b);
    else return 4; // error case bad flag
}

void demo(int argc, char * argv[]){
    int result = run(argc, argv);
    char * string;
    if (result) string = "false";
    else string = "true";
    if (result == 0 || result == 1) printf("result: %d (%s)\n", result, string);
    else if (result == 2) printf("ERROR: you must type exactly 3 arguments!\nYour command should look like this: \ntest Integer1 -flag Integer2\n");
    else if (result == 3) printf("ERROR: the first and third arguments should be integers!\n");
    else if (result == 4) printf("ERROR: the flag should be among this flags:\n-eq (equal)\n-ge (greater than or equal)\n-gt (greater than)\n-le (lower than or equal)\n-lt (lower than)\n-ne (different)");
    else printf("ERROR: an undefined error occurred!");
}

int main(int argc, char * argv[]){
    demo(argc, argv);
    return run(argc, argv);
}