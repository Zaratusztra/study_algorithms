#include <stdlib.h>
#include <stdio.h>

double rnp_eval(const char * rnp_expr)
{
    return -1.0;
}


int main(int argc, char **argv){
    const char * expr = argv[0];
    fprintf(stdout, "%f", rnp_eval);
    return 0;
}
