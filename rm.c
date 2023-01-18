#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // for(int i=0; i<argc; i++)
    // {
    //     printf("%s\n", argv[i]);
    // }

    if(!(strcmp(argv[1],"rmdir")))
    {
        for(int k=2; k<argc; k++)
        {
            int j=0;
            char removedir[100]={0};
            sprintf(removedir,"rmdir %s",argv[k]);
            j=system(removedir);
            if(j==0)
            {
                printf("Directory Deletion Successful!!\n");
            }
            else
            {
                printf("Directory couldn't be deleted!!\n");
                j=0;
            }
        }
    }
    else if(!(strcmp(argv[1],"rm")))
    {
        for(int k=2; k<argc; k++)
        {
            int i=0;
            char removef[100]={0};
            sprintf(removef,"rm %s",argv[k]);
            i=system(removef);
            if(i==0)
            {
                printf("File Deletion Successful!!\n");
            }
            else
            {
                printf("File couldn't be deleted!!\n");
                i=0;
            }
        }
    }
    return 0;
}