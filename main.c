#include <stdio.h>
#include <stdlib.h>
#include "disassemble8080.h"

int main(nt argc, char** argc){
    FILE *f = fopen (argv[1], "rb"); //opening a non-text file from command line parameters
    if(f == NULL){ //catch file error
        printf("Error: No file opened");
        exit(1);
    }
    fseek(f, 0L, SEEK_END); //set the file position to the end of the file with 0L offset
    int fsize = ftell(f); //the current file position relative to the beginning
    fseek(f, 0L, SEEK_SET); //set the file position to the beginning of the file with 0L offset

    unsigned char *buffer = malloc(fsize); //allocate memory for the specified file size
    fclose(f); //closes the file stream

    //Program counter functionality
    int pc = 0;
    while(pc < fsize){
        pc += disassemble8080(buffer, pc); //increment the program counter with the instruction size
    }
    return 0;
};

