#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <pthread.h>
#include <ctype.h>


/*
Internal Commands handled: cd, pwd, echo

Variants of cd ==> cd, cd..
Variants of pwd ==> pwd, pwd-L
Variants of echo ==> echo, echo $USER

External Commands handled: ls, cat, date, rm, mkdir

Variants of ls ==> ls, ls-F
Variants of cat ==> cat, tac
Variants of date ==> date, date(Year, Month, Date) format
Variants of rm ==> rm, rmdir
Variants of mkdir ==> Single directory making, multiple directory making


Calling convention of Commands for the Shell:

*To be executed using Thread:->

cat &t
tac &t
pwd &t
pwd-L &t
echo &t
echo $USER &t
cd &t
cd .. &t
ls -&t
ls -F &t
date -YMD &t
date -&t
rm &t
rmdir &t
mkdir &t

*To be executed using Fork:->

ls. //There is a space after '.'
ls -F //There is a space after '-F'
cat.
date .
date -YMD .
rmdir .
rm .
mkdir .
cd..
cd
pwd
pwd-L
echo $USER
echo

*/


char catarr[400];
char lsarr[400];
char lsfarr[400];
char datearr[400];
char rmarr[400];
char rmdarr[400];
char mkarr[400];

void* cat()
{
    system(catarr);
    return NULL;
}

void* date()
{
    system(datearr);
    return NULL;
}

void* rm()
{
    system(rmarr);
    return NULL;
}

void* rmd()
{
    system(rmdarr);
    return NULL;
}

void* mkdir()
{
    system(mkarr);
    return NULL;
}

void* pwd()
{
    char ch[500];
    printf("%s",getcwd(ch,sizeof(ch)));
    printf("\n");
    return NULL;
}

void* pwd_l()
{
    char ch[500];
    printf("%s",getcwd(ch,sizeof(ch)));
    printf("\n");
    return NULL;
}

void* echo()
{
    char argv[100];
    fgets(argv,100,stdin);
    int argc=strlen(argv);

    char new_str[100];

    int counter = 0;
    for(int i=0; i < argc; i++)
    {
        if (isalnum(argv[i]) && argv[i]!=' ' && argv[i]!='~' && argv[i]!='!' && argv[i]!='@' && argv[i]!='#' && argv[i]!='$' && argv[i]!='%' && argv[i]!='^' && argv[i]!='&' && argv[i]!='*' && argv[i]!='(' && argv[i]!=')' && argv[i]!='-' && argv[i]!='_' && argv[i]!='+' && argv[i]!='=' && argv[i]!='`' && argv[i]!=',' && argv[i]!='.' && argv[i]!='/' && argv[i]!='<' && argv[i]!='>' && argv[i]!='?' && argv[i]!=';' && argv[i]!=':' && argv[i]!='[' && argv[i]!=']' && argv[i]!='{' && argv[i]!='}' && argv[i]!='|' )
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==' ')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='~')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='!')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='@')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='#')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='$')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='%')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='^')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='&')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='*')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='(')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==')')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='-')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='_')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='+')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='=')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='`')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==',')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='.')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='/')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='<')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='>')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='?')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==';')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==':')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='[')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==']')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='{')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='}')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='|')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
    }
    new_str[counter] = '\0';

    if(argc<1)
    {
        printf("Not enough arguments in here!!\n");
    }
    else
    {
        puts(new_str);
    }
    return NULL;
}

void* echo_user()
{
    char *buf=getlogin();
    printf("%s\n",buf);
    return NULL;
}

void* cd()
{
    char ch[150];
    printf("%s\n",getcwd(ch,150));
    return NULL;
}

void* cd_()
{
    char ch[150];
    chdir("..");
    printf("%s\n",getcwd(ch,150));
    return NULL;
}

void* ls()
{
    system(lsarr);
    return NULL;
}

void* lsf()
{
    system(lsfarr);
    return NULL;
}

int main()
{
    while(1)
    {
        printf("\n>>>");
        char input[51];
        fgets(input,51,stdin);

        if(input[0]=='c' && input[1]=='a' && input[2]=='t' && input[3]==' ' && input[4]=='&' && input[5]=='t')
        {
            char catloc[400]="/Users/varul18/Desktop/A1_2021569_OS/cat ";
            char inp[51];
            memcpy(inp,input,strlen(input)-3);
            memcpy(catarr, catloc, strlen(catloc));
            char arv[51];
            fgets(arv,51,stdin);
            strcat(inp,arv);
            strcat(catarr,inp);
            pthread_t thread;
            pthread_create(&thread,NULL, cat, NULL);
            pthread_join(thread, NULL);
            memset(catarr,0,sizeof(catarr));
            // exit(0);
        }

        else if(input[0]=='t' && input[1]=='a' && input[2]=='c' && input[3]==' ' && input[4]=='&' && input[5]=='t')
        {
            char catloc[400]="/Users/varul18/Desktop/A1_2021569_OS/cat ";
            char inp[51];
            memcpy(inp,input,strlen(input)-3);
            memcpy(catarr, catloc, strlen(catloc));
            char arv[51];
            fgets(arv,51,stdin);
            strcat(inp,arv);
            strcat(catarr,inp);
            pthread_t thread;
            pthread_create(&thread,NULL, cat, NULL);
            pthread_join(thread, NULL);
            memset(catarr,0,sizeof(catarr));
            // exit(0);
        }

        else if(input[0]=='p' && input[1]=='w' && input[2]=='d' && input[3]==' ' && input[4]=='&' && input[5]=='t')
        {
            pthread_t thread;
            pthread_create(&thread, NULL, pwd, NULL);
            pthread_join(thread, NULL);
            // exit(0);
        }
        else if(input[0]=='p' && input[1]=='w' && input[2]=='d' && input[3]=='-' && input[4]=='L' && input[5]==' ' && input[6]=='&' && input[7]=='t')
        {
            pthread_t thread;
            pthread_create(&thread, NULL, pwd_l, NULL);
            pthread_join(thread, NULL);
            // exit(0);
        }
        else if(input[0]=='e' && input[1]=='c' && input[2]=='h' && input[3]=='o' && input[4]==' ' && input[5]=='&' && input[6]=='t')
        {
            pthread_t thread;
            pthread_create(&thread, NULL, echo, NULL);
            pthread_join(thread, NULL);
            // exit(0);
        }
        else if(input[0]=='e' && input[1]=='c' && input[2]=='h' && input[3]=='o' && input[4]==' ' && input[5]=='$' && input[6]=='U' && input[7]=='S' && input[8]=='E' && input[9]=='R' && input[10]==' ' && input[11]=='&' && input[12]=='t')
        {
            pthread_t thread;
            pthread_create(&thread, NULL, echo_user, NULL);
            pthread_join(thread, NULL);
            // exit(0);
        }
        else if(input[0]=='c' && input[1]=='d' && input[2]==' ' && input[3]=='&' && input[4]=='t')
        {
            pthread_t thread;
            pthread_create(&thread, NULL, cd, NULL);
            pthread_join(thread, NULL);
            // exit(0);
        }
        else if(input[0]=='c' && input[1]=='d' && input[2]==' ' && input[3]=='.' && input[4]=='.' && input[5]==' ' && input[6]=='&' && input[7]=='t')
        {
            pthread_t thread;
            pthread_create(&thread, NULL, cd_, NULL);
            pthread_join(thread, NULL);
            // exit(0);
        }
        else if(input[0]=='l' && input[1]=='s' && input[2]==' ' && input[3]=='-' && input[4]=='&' && input[5]=='t')
        {
            char lsloc[400]="/Users/varul18/Desktop/A1_2021569_OS/LS ";
            memcpy(lsarr,lsloc,strlen(lsloc));
            char inp[51];
            memcpy(inp,input,strlen(input)-3);
            strcat(lsarr,inp);
            pthread_t thread;
            pthread_create(&thread, NULL, ls, NULL);
            pthread_join(thread, NULL);
            memset(lsarr,0,sizeof(lsarr));
            // exit(0);
        }
        else if(input[0]=='l' && input[1]=='s' && input[2]==' ' && input[3]=='-' && input[4]=='F' && input[5]==' ' && input[6]=='&' && input[7]=='t')
        {
            char lsloc[400]="/Users/varul18/Desktop/A1_2021569_OS/LS ";
            memcpy(lsfarr,lsloc,strlen(lsloc));
            char inp[51];
            memcpy(inp,input,strlen(input)-3);
            strcat(lsfarr,inp);
            pthread_t thread;
            pthread_create(&thread, NULL, lsf, NULL);
            pthread_join(thread, NULL);
            memset(lsfarr,0,sizeof(lsfarr));
            // exit(0);
        }
        else if(input[0]=='d' && input[1]=='a' && input[2]=='t' && input[3]=='e' && input[4]==' ' && input[5]=='-' && input[6]=='Y' && input[7]=='M' &&  input[8]=='D' && input[9]==' ' && input[10]=='&' && input[11]=='t')
        {
            char dateloc[400]="/Users/varul18/Desktop/A1_2021569_OS/date ";
            memcpy(datearr,dateloc,strlen(dateloc));
            char inp[51];
            memcpy(inp,input,strlen(input)-3);
            strcat(datearr,inp);
            pthread_t thread;
            pthread_create(&thread, NULL, date, NULL);
            pthread_join(thread, NULL);
            memset(datearr,0,sizeof(datearr));
            // exit(0);
        }
        else if(input[0]=='d' && input[1]=='a' && input[2]=='t' && input[3]=='e' && input[4]==' ' && input[5]=='-' && input[6]=='&' && input[7]=='t')
        {
            char dateloc[400]="/Users/varul18/Desktop/A1_2021569_OS/date ";
            memcpy(datearr,dateloc,strlen(dateloc));
            char inp[51];
            memcpy(inp,input,strlen(input)-3);
            strcat(datearr,inp);
            pthread_t thread;
            pthread_create(&thread, NULL, date, NULL);
            pthread_join(thread, NULL);
            memset(datearr,0,sizeof(datearr));
            // exit(0);
        }
        else if(input[0]=='r' && input[1]=='m' && input[2]==' ' && input[3]=='&' && input[4]=='t')
        {
            char rmloc[400]="/Users/varul18/Desktop/A1_2021569_OS/rmv ";
            memcpy(rmarr,rmloc,sizeof(rmloc));
            char inp[51];
            memcpy(inp,input,strlen(input)-3);
            char arv[51];
            fgets(arv,51,stdin);
            strcat(inp,arv);
            strcat(rmarr,inp);
            pthread_t thread;
            pthread_create(&thread, NULL, rm, NULL);
            pthread_join(thread, NULL);
            memset(rmarr,0,sizeof(rmarr));
            // exit(0);
        }
        else if(input[0]=='r' && input[1]=='m' && input[2]=='d' && input[3]=='i' && input[4]=='r' && input[5]==' ' && input[6]=='&' && input[7]=='t')
        {
            char rmdloc[400]="/Users/varul18/Desktop/A1_2021569_OS/rmv ";
            memcpy(rmdarr,rmdloc,sizeof(rmdloc));
            char inp[51];
            memcpy(inp,input,strlen(input)-3);
            char arv[51];
            fgets(arv,51,stdin);
            strcat(inp,arv);
            strcat(rmdarr,inp);
            pthread_t thread;
            pthread_create(&thread, NULL, rmd, NULL);
            pthread_join(thread, NULL);
            memset(rmdarr,0,sizeof(rmdarr));
            // exit(0);
        }
        else if(input[0]=='m' && input[1]=='k' && input[2]=='d' && input[3]=='i' && input[4]=='r'  && input[5]==' ' && input[6]=='&' && input[7]=='t')
        {
            char mkloc[400]="/Users/varul18/Desktop/A1_2021569_OS/mkdir ";
            memcpy(mkarr,mkloc,sizeof(mkloc));
            char inp[51];
            memcpy(inp,input,strlen(input)-3);
            char arv[51];
            fgets(arv,51,stdin);
            strcat(inp,arv);
            strcat(mkarr, inp);
            pthread_t thread;
            pthread_create(&thread, NULL, mkdir, NULL);
            pthread_join(thread, NULL);
            memset(mkarr,0,sizeof(mkarr));
            // exit(0);
        }

        else if(input[0]=='l' && input[1]=='s' && input[2]=='.')
        {
            pid_t pid=fork();
            if(pid==0)
            {
                char lsloc[400]="/Users/varul18/Desktop/A1_2021569_OS/LS ";
                memcpy(lsarr,lsloc,strlen(lsloc));
                strcat(lsarr,input);
                char *token = strtok(lsarr, " ");
                char *arr[51];
                int i=0;
                while( token != NULL ) {
                    arr[i]=token;
                    i++;
                    token = strtok(NULL, " ");
                }
                execl("/Users/varul18/Desktop/A1_2021569_OS/LS",arr[0],arr[1],arr[2], NULL);
            }
            else if(pid>0)
            {
                wait(NULL);
            }
        }

        else if(input[0]=='l' && input[1]=='s' && input[2]==' ' && input[3]=='-' && input[4]=='F' && input[6]!='&')
        {
            pid_t pid=fork();
            if(pid==0)
            {
                char lsloc[400]="/Users/varul18/Desktop/A1_2021569_OS/LS ";
                memcpy(lsfarr,lsloc,strlen(lsloc));
                strcat(lsfarr,input);
                char *token = strtok(lsfarr, " ");
                char *arr[51];
                int i=0;
                while( token != NULL ) {
                    arr[i]=token;
                    i++;
                    token = strtok(NULL, " ");
                }
                execl("/Users/varul18/Desktop/A1_2021569_OS/LS",arr[0],arr[1],arr[2], NULL);
            }
            else if(pid>0)
            {
                wait(NULL);
            }
        }

        else if(input[0]=='c' && input[1]=='a' && input[2]=='t' && input[3]==' ' && input[4]=='.')
        {
            pid_t pid=fork();
            if(pid==0)
            {
                char catloc[400]="/Users/varul18/Desktop/A1_2021569_OS/cat ";
                memcpy(catarr, catloc, strlen(catloc));
                char arv[51];
                fgets(arv,51,stdin);
                char inp[51];
                memcpy(inp,input,strlen(input)-2);
                strcat(inp,arv);
                strcat(catarr,inp);
                char *token = strtok(catarr, " ");
                char *arr[51];
                int i=0;
                while( token != NULL ) {
                    arr[i]=token;
                    i++;
                    token = strtok(NULL, " ");
                }
                execl("/Users/varul18/Desktop/A1_2021569_OS/cat",arr[0],arr[1],arr[2], NULL);
            }
            else if(pid>0)
            {
                wait(NULL);
            }
        }

        else if(input[0]=='d' && input[1]=='a' && input[2]=='t' && input[3]=='e' && input[4]==' ' && input[5]=='.')
        {
            pid_t pid=fork();
            if(pid==0)
            {
                char dateloc[400]="/Users/varul18/Desktop/A1_2021569_OS/date ";
                memcpy(datearr,dateloc,strlen(dateloc));
                strcat(datearr,input);
                char *token = strtok(datearr, " ");
                char *arr[51];
                int i=0;
                while( token != NULL ) {
                    arr[i]=token;
                    i++;
                    token = strtok(NULL, " ");
                }
                execl("/Users/varul18/Desktop/A1_2021569_OS/date",arr[0], arr[1], arr[2], NULL);
            }
            else if(pid>0)
            {
                wait(NULL);
            }
        }

        else if(input[0]=='d' && input[1]=='a' && input[2]=='t' && input[3]=='e' && input[4]==' ' && input[5]=='-' && input[6]=='Y' && input[7]=='M' && input[8]=='D' && input[9]==' ' && input[10]=='.')
        {
            pid_t pid=fork();
            if(pid==0)
            {
                char dateloc[400]="/Users/varul18/Desktop/A1_2021569_OS/date ";
                memcpy(datearr,dateloc,strlen(dateloc));
                strcat(datearr,input);
                char *token = strtok(datearr, " ");
                char *arr[51];
                int i=0;
                while( token != NULL ) {
                    arr[i]=token;
                    i++;
                    token = strtok(NULL, " ");
                }
                execl("/Users/varul18/Desktop/A1_2021569_OS/date",arr[0], arr[1], arr[2], NULL);
            }
            else if(pid>0)
            {
                wait(NULL);
            }
        }

        else if(input[0]=='r' && input[1]=='m' && input[2]=='d' && input[3]=='i' && input[4]=='r' && input[5]==' ' && input[6]=='.')
        {
            pid_t pid=fork();
            if(pid==0)
            {
                char rmdloc[400]="/Users/varul18/Desktop/A1_2021569_OS/rmv ";
                memcpy(rmdarr,rmdloc,sizeof(rmdloc));
                char arv[51];
                fgets(arv,51,stdin);
                char inp[51];
                memcpy(inp,input,strlen(input)-2);
                strcat(inp,arv);
                strcat(rmdarr,inp);
                char *token = strtok(rmdarr, " ");
                char *arr[51];
                int i=0;
                while( token != NULL ) {
                    arr[i]=token;
                    i++;
                    token = strtok(NULL, " ");
                }
                execl("/Users/varul18/Desktop/A1_2021569_OS/rmv",arr[0], arr[1], arr[2],arr[3], arr[4], arr[5],arr[6], arr[7], arr[8],arr[9], arr[10], NULL);
            }
            else if(pid>0)
            {
                wait(NULL);
            }
        }

        else if(input[0]=='r' && input[1]=='m' && input[2]==' ' && input[3]=='.' )
        {
            pid_t pid=fork();
            if(pid==0)
            {
                char rmloc[400]="/Users/varul18/Desktop/A1_2021569_OS/rmv ";
                memcpy(rmarr,rmloc,sizeof(rmloc));
                char arv[51];
                fgets(arv,51,stdin);
                char inp[51];
                memcpy(inp,input,strlen(input)-2);
                strcat(inp,arv);
                strcat(rmarr,inp);
                char *token = strtok(rmarr, " ");
                char *arr[51];
                int i=0;
                while( token != NULL ) {
                    arr[i]=token;
                    i++;
                    token = strtok(NULL, " ");
                }
                execl("/Users/varul18/Desktop/A1_2021569_OS/rmv",arr[0], arr[1], arr[2],arr[3], arr[4], arr[5],arr[6], arr[7], arr[8],arr[9], arr[10], NULL);
            }
            else if(pid>0)
            {
                wait(NULL);
            }
        }

        else if(input[0]=='m' && input[1]=='k' && input[2]=='d' && input[3]=='i' && input[4]=='r' && input[5]==' ' && input[6]=='.')
        {
            pid_t pid=fork();
            if(pid==0)
            {
                char mkloc[400]="/Users/varul18/Desktop/A1_2021569_OS/mkdir ";
                memcpy(mkarr,mkloc,sizeof(mkloc));
                char arv[51];
                fgets(arv,51,stdin);
                char inp[51];
                memcpy(inp,input,strlen(input)-2);
                strcat(inp,arv);
                strcat(mkarr, inp);
                char *token = strtok(mkarr, " ");
                char *arr[51];
                int i=0;
                while( token != NULL ) {
                    arr[i]=token;
                    i++;
                    token = strtok(NULL, " ");
                }
                execl("/Users/varul18/Desktop/A1_2021569_OS/mkdir",arr[0], arr[1], arr[2],arr[3], arr[4], arr[5],arr[6], arr[7], arr[8],arr[9], arr[10], NULL);
            }
            else if(pid>0)
            {
                wait(NULL);
            }
        }

        else if(input[0]=='c' && input[1]=='d' && input[2]=='.' && input[3]=='.')
        {
            char ch[150];
            chdir("..");
            printf("%s\n",getcwd(ch,150));
        }

        else if(input[0]=='c' && input[1]=='d' && input[2]!='.' && input[3]!='.')
        {
            char ch[150];
            printf("%s\n",getcwd(ch,150));
        }

        else if(input[0]=='p' && input[1]=='w' && input[2]=='d')
        {
            char ch[500];
            printf("%s",getcwd(ch,sizeof(ch)));
            printf("\n");
        }

        else if(input[0]=='p' && input[1]=='w' && input[2]=='d' && input[3]=='-' && input[4]=='L')
        {
            char ch[500];
            printf("%s",getcwd(ch,sizeof(ch)));
            printf("\n");
        }

        else if(input[0]=='e' && input[1]=='c' && input[2]=='h' && input[3]=='o' && input[4]==' ' && input[5]=='$' && input[6]=='U' && input[7]=='S' && input[8]=='E' && input[9]=='R')
        {
            char *buf=getlogin();
            printf("%s\n",buf);
        }

        else if(input[0]=='e' && input[1]=='c' && input[2]=='h' && input[3]=='o' && input[4]!=' ' && input[5]!='$')
        {
            char argv[100];
            fgets(argv,100,stdin);
            int argc=strlen(argv);

            char new_str[100];

            int counter = 0;
            for(int i=0; i < argc; i++)
            {
                 if (isalnum(argv[i]) && argv[i]!=' ' && argv[i]!='~' && argv[i]!='!' && argv[i]!='@' && argv[i]!='#' && argv[i]!='$' && argv[i]!='%' && argv[i]!='^' && argv[i]!='&' && argv[i]!='*' && argv[i]!='(' && argv[i]!=')' && argv[i]!='-' && argv[i]!='_' && argv[i]!='+' && argv[i]!='=' && argv[i]!='`' && argv[i]!=',' && argv[i]!='.' && argv[i]!='/' && argv[i]!='<' && argv[i]!='>' && argv[i]!='?' && argv[i]!=';' && argv[i]!=':' && argv[i]!='[' && argv[i]!=']' && argv[i]!='{' && argv[i]!='}' && argv[i]!='|' )
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==' ')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='~')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='!')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='@')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='#')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='$')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='%')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='^')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='&')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='*')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='(')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==')')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='-')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='_')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='+')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='=')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='`')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==',')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='.')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='/')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='<')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='>')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='?')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==';')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==':')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='[')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]==']')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='{')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='}')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
                else if(argv[i]=='|')
                {
                    new_str[counter] = argv[i];
                    counter++;
                }
            }
            new_str[counter] = '\0';

            if(argc<1)
            {
                printf("Not enough arguments in here!!\n");
            }
            else
            {
                puts(new_str);
            }
        }
    }
    return 0;
}