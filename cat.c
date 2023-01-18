#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int fptr;
    int read_b;
    char array[100];

    // for(int i=0; i<argc; i++)
    // {
    //     printf("%s\n",argv[i]);
    // }

    if(argc<1)
    {
        printf("Not enough arguments in here!!\n");
    }
    
    if(!(strcmp(argv[1],"cat")))
    {
        for(int j=2; j<argc; j++)
        {
            fptr = open(argv[j], O_RDONLY);

            if (fptr == -1)
            {
                printf("No such file could be found in the directory!!\n");
                fptr=0;
            }
            else
            {
                while ((read_b= read(fptr, array, 100))!=0)
                    write(1, &array, read_b);
            }
            close(fptr);
            printf("\n");
        }
    }
    else
    {
        FILE *file;
        int count = 0, num = 0;
        
        if(argc<2 )
        {
            printf("Not enough arguments in here!!\n");
        }
        
        for(int j=2; j<argc; j++)
        {
            file = fopen(argv[j],"r");
            if(file==NULL)
            {
                printf("The file could not be opened!!\n");
            }
            
            fseek(file,0,SEEK_END);
            count = ftell(file);
            
            while(num<count)
            {
                num++;
                fseek(file,-num,SEEK_END);
                printf("%c",fgetc(file));
            }
            printf("\n");
            fclose(file);
        }
    }
    return 0;
}