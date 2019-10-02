/*
 * File:   main.c
 * Author: zentut.com
 * Description: Read text file line by line and output it to
 *              the screen.
 */
 
#include <stdio.h>
#define MAXCHAR 1000

int ReadFile(){
	FILE *fp;
    char str[MAXCHAR];
    char* filename = "./../Lab10_Storage_Management/files/Log.txt";
 
    fp = fopen(filename, "r");
    
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    
    int line = 0;
    while (fgets(str, MAXCHAR, fp) != NULL){
    	++line;
    	printf("%d : ", line);
        printf("%s", str); 
	}
    fclose(fp);
}
 

int main() {
	ReadFile();
    return 0;
}
