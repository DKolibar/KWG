/***
    KWG - KAREL WORLD GENERATOR - By Daniel Kolibár | dkolibar@gmail.com
 ***/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_CHAR ' '
#define SPECIAL_CHAR '?'
#define ARRAY_SIZE_I 30
#define ARRAY_SIZE_J 60

int checkChar(char Ich);
void getDimensions();
int start(int Iargc, char *Iargv[]);
void info();
void resetArray();
void getFilesReady(char *Iargv[]);
void cleanMap();
void skip();
void writeFirstLineOfKW(int Ipb);
void writeRestOfKW();

FILE *fr= NULL, *fw= NULL;
char map[ARRAY_SIZE_I][ARRAY_SIZE_J];
unsigned short Width=0, Height=0;
bool debug = false;

int main(int argc, char *argv[])
{
    int i=0,j=0;

    int pb = start(argc, argv); //start procedure + store amount of beepers at start from user
    resetArray();
    getFilesReady(argv);
    cleanMap(); //remove unecessary parts chars from map and store map into MAP array
    getDimensions();
    writeFirstLineOfKW(pb);
    writeRestOfKW();

    //print out whole MAP array
    if(debug)
    {
        for(i=0; i<ARRAY_SIZE_I; i++)
        {
            for(j=0;j<ARRAY_SIZE_J;j++)
                printf("%c", map[i][j]);
            printf("\n");
        }
    }

    //wait for user to close program
    if(debug)
    {
        printf("Press any key to exit!\n");
        getchar();
    }

    printf("Done.");

    return 0;
}

void writeFirstLineOfKW(int Ipb) //write first line, position of KAREL, KW dimensions and beeper amount from user input
{
    int i,j;
    int Y=Height, X=1;
    bool semaphore = false;

    char directions[] = {'E','N','W','S'};


    for(i=0; i<ARRAY_SIZE_I; i++)
    {
        for(j=0;j<ARRAY_SIZE_J;j++)
        {
            if(checkChar(map[i][j]) > -1)
            {
                if(checkChar(map[i][j]) > 0 && checkChar(map[i][j]) != 9)
                    fprintf(fw, "%d %d %d %d %c %d\n\n", Width, Height, X, Y, directions[checkChar(map[i][j])-1], Ipb);

                X++;
                semaphore = true;
            }
        }

        X=1;
        if(semaphore)
        {
            Y--;
            semaphore = false;
        }
    }
}

void writeRestOfKW()
{
    int i,j;
    int Y=Height, X=1;
    bool semaphore = false;

    //for loops scan whole MAP array, if there is some valid char, two directions are checked for wall presence
    for(i=0; i<ARRAY_SIZE_I; i++)
    {
        for(j=0;j<ARRAY_SIZE_J;j++)
        {
            if(checkChar(map[i][j]) > -1)
            {
                //check for beeper, checkChar() returns 9 because it found NUMBER
                if(checkChar(map[i][j]) == 9) //first number 1X
                {
                    if(checkChar(map[i][j + 1]) == 9) //second number X1
                        fprintf(fw, "B %d %d %c%c\n", X, Y, map[i][j], map[i][j+1]);
                    else
                        fprintf(fw, "B %d %d %c\n", X, Y, map[i][j]);
                    //TODO: make program work with placed beepers amount over 99
                }

                //check for WALL on EAST
                if(map[i][j+2]=='|')
                    fprintf(fw, "W %d %d E\n", X, Y);

                //check for WALL on SOUTH
                if(map[i+1][j]=='-')
                    fprintf(fw, "W %d %d S\n", X, Y);

                X++;
                semaphore = true; //change Y value only if loop is in row with valid chars, so spaces between rows are ignored
            }
        }

        X=1;
        if(semaphore)
        {
            Y--;
            semaphore = false;
        }
    }
}

void getDimensions()
{
    int i,j;

    //count WIDTH of map, every DOT or other valid char is represented as one column (width) of world
    for(j=0;j<ARRAY_SIZE_J;j++)
    {
        if(checkChar(map[0][j]) > -1)
            Width++;
    }

    //count HEIGHT of world, every DOT or other valid char is represented as one row (Height) of world
    for(i=0; i<ARRAY_SIZE_I; i++)
    {
        for(j=0;j<ARRAY_SIZE_J;j++)
        {
            if(checkChar(map[i][j]) > -1)
            {
                for(i=0;i<ARRAY_SIZE_I;i++)
                {
                    if(checkChar(map[i][j]) > -1)
                        Height++;

                    if(map[i][j]== SPECIAL_CHAR)
                    {
                        Height+=1;
                        return;
                    }
                }
            }
        }
    }

    if(debug)
        printf("width: %d Height: %d\n", Width, Height);
}

int checkChar(char Ich) //check if actual character (Ich) is valid
{
    char validChars[] = {'.','>','^','<','v'};
    int i;

    if((unsigned int) Ich >= 49 && (unsigned int) Ich <= 57)
        return 9; //if value is some number return 9 (why 9? because why not...)

    for(i=0;i<sizeof(validChars);i++)
    {
        if(Ich == validChars[i])
        {
            return i; //values 1-4 represents direction of Karel written to output file
        }
    }

    return -1; //returns when Ich is not valid character
}



void info()
{
    printf("\nUsage: KWG path_to_map_text_file beepers_amount_at_start [-D]");
    printf("\nExample: KWG folderA/map1.txt 60\n\n");
    printf("Options:\n");
    printf("   -D      Show debug info\n\n");
    printf("By: Daniel Kolibar | dkolibar@gmail.com\n");
    exit(EXIT_FAILURE);
}

int start(int Iargc, char *Iargv[])
{
    int n;

    //if program is run without any parameters:
    if(Iargc < 3 || Iargc > 4)
        info();

    //sets debug to true if -D flag is used, if there is invalid flag write info:
    if(Iargc == 4 && strcmp(Iargv[3],"-D")==0)
        debug = true;
    else if(Iargc == 4)
        info();

    //check second parameter (beepers amount)
    int i=0;
    while(*(Iargv[2]+i)!='\0') //check whole string until end
    {
        //if any of char in string is not number is is INVALID input
        if(*(Iargv[2]+i) < 48 || *(Iargv[2]+i) > 57)
        {
            info();
            break;
        }

        i++;
    }
    n = atoi(Iargv[2]);   // NOLINT(cert-err34-c)

    //prints basic info:
    if(debug)
    {
        printf("arg. N: %d\n", Iargc-1); //argument count
        printf("path: %s\n", Iargv[1]); //path of input file
        printf("beepers amount: %d\n", n); //beepers amount
    }

    return n;
}

void resetArray() //fill map array with EMPTY_CHAR
{
    int i=0,j=0;

    for(i=0; i<ARRAY_SIZE_I; i++)
    {
        for(j=0;j<ARRAY_SIZE_J;j++)
            map[i][j] = EMPTY_CHAR;
    }
}

void getFilesReady(char *Iargv[])
{
    char *s = Iargv[1], f[255];
    int slash=0;
    int i, i2;

    //fill f (final file name) with EMPTY_CHAR
    for(i=0; i<strlen(f);i++)
        f[i]=EMPTY_CHAR;

    //search for \/ and get last position of it
    for(i=0; i<strlen(s);i++)
    {
        if(*(s+i) == '\\' || *(s+i) == '/')
        {
            for(i2=i+1; i2<strlen(s); i2++)
            {
                if(*(s+i2) == '\\' || *(s+i) == '/')
                {
                    i=i2;
                    break;
                }
            }
            slash = i;
        }
    }

    //get name based of slash calculated position
    i=0;
    for(i2=slash; i2<strlen(s);i2++)
    {
        if(*(s+i2) != '\\')
        {
            f[i] = *(s + i2);
            i++;
        }
    }

    f[i]='\0'; strcat(f, ".kw"); //write .kw to end of file

    if(debug)
        printf("result file name: %s\n", f);

    fr = fopen(Iargv[1], "r"); //pointer to input file

    if(fr==NULL)
    {
        printf("Error opening input file :(");
        exit(EXIT_FAILURE);
    }

    fw = fopen(f, "w"); //pointer to output file with f name
    if(fw==NULL)
    {
        printf("Can't write output file :(");
        exit(EXIT_FAILURE);
    }
}

void skip() //skip for every four chars in every line of map
{
    fgetc(fr); fgetc(fr); fgetc(fr); fgetc(fr);
}

void cleanMap()
{
    int i=0,j=0,j2;
    int character; //actual char from input file

    //skip first line of map
    while(true)
    {
        if(fgetc(fr) == '\n')
            break;
    }

    skip();

    while(1)
    {
        character = fgetc(fr);

        if(character == '\n') //on \n place SPECIAL CHAR to end of row in array and go to next line of file
        {
            for(j2=j-1;j2<ARRAY_SIZE_J;j2++)
                map[i][j2]=SPECIAL_CHAR;

            i++; j=0;
            skip();
        }
        else if(feof(fr)) //on EOF remove last two lines from array
        {
            //if there is empty line at the end, remove it!
            if(map[i-2][0]=='-')
            {
                for(j2=0;j2<ARRAY_SIZE_J;j2++)
                    map[i-2][j2]=EMPTY_CHAR;
            }

            for(j2=0;j2<ARRAY_SIZE_J;j2++)
            {
                map[i][j2] = EMPTY_CHAR;
                map[i-1][j2]=EMPTY_CHAR;

            }
            break;
        }
        else
        {
            map[i][j] = (char) character;
            j++;
        }
    }
}