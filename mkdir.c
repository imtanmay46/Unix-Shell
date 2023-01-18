#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // for(int i=0; i<argc; i++)
    // {
    //     printf("%s\n", argv[i]);
    // }

    int i=0;
    for (int j=2; j< argc; j++)
    {
        i=mkdir(argv[j],0755);

        if(i==0)
        {
            printf("Directory creation Successful!!\n");
        }
        else
        {
            printf("Directory couldn't be created!!\n");
            i=0;
        }
        // printf("%s\n",argv[j]);
    }

    return 0;
}