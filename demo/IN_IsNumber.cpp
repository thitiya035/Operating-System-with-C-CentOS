#include<stdio.h>
#include<stdlib.h>
#include <iostream> 
#include <string.h>
#define MaxString  20

int IsNumber(char* s){
    for (int i = 0; i < strlen(s); i++){
         if (isdigit(s[i]) == false){
         	printf("Not a number.\n");
         	return false;
		 }
	}
	printf("Yes, It is a number.\n");
    return true; 
}

int main(){
	char SNumber[10] = "1234"; 
	char S[10] 		 = "lsfjd";
	int Number       = 1234;
	
	//chcek
	IsNumber(SNumber);
	IsNumber(S);
	
	// int -> string -> (checke num)
	char snum[10];
	itoa(Number, snum, 10);
	IsNumber(snum);
}
