#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // for(int i=0; i<argc; i++)
    // {
    //     printf("%s\n", argv[i]);
    // }

    if(!(strcmp(argv[2],"-YMD")))
    {
    time_t mytime;
    mytime=time(NULL);
    struct tm tim=*localtime(&mytime);
    printf("Year: %d, Month: %d, Day: %d\n",tim.tm_year+1900, tim.tm_mon+1, tim.tm_mday);
    }
    else
    {
        time_t mytime;
        time(&mytime);

        printf("%s",ctime(&mytime));
    }
    return 0;
}