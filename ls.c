#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // for(int i=0; i<argc; i++)
    // {
    //     printf("%s\n", argv[i]);
    // }

    if(!(strcmp(argv[2],"-F")))
    {
        DIR*f;
        struct dirent *d;
        f=opendir(".");
        if(!f)
        {
        printf("No such directory was found!!\n");
        exit(1);
        }
        else
        {
            while((d=readdir(f))!=NULL)
            {
                printf("%s/\n",d->d_name);
            }
            closedir(f);
        }
    }
    else
    {
        DIR*f;
        struct dirent *d;
        f=opendir(".");
        if(!f)
        {
        printf("No such directory was found!!\n");
        exit(1);
        }
        else
        {
            while((d=readdir(f))!=NULL)
            {
                printf("%s\n",d->d_name);
            }
            closedir(f);
        }
    }
    return 0;
}