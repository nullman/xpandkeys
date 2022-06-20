#include <stdio.h>

extern char * get_string() {
    return "Hello World!";
}

#if ! TEST
int main(int argc, char *argv[]) {
    printf("%s\n", get_string());
}
#endif
