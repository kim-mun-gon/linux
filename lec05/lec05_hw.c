#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *in, *out;
    int rn, wn;
    char buf[BUFSIZ];

    if(argc != 3)
    {
        fprintf(stderr, "Usage: fcopy fie1 file2\n");
        return -1;
    }

    in = fopen(argv[1],"r");
    
    if(in == NULL)
    {
        perror(argv[1]);
        return -1;
    }

    out = fopen(argv[2], "w");
    
    if(out == NULL)
    {
        perror(argv[2]);
        return -1;
    }

    while((rn = fread(buf, sizeof(char), BUFSIZ, in)) > 0)
    {
        if((wn = fwrite(buf, sizeof(char), rn, out) != rn))
            perror("file write error!\n");
    }

    fclose(out);
    fclose(in);

    return 0;
}
