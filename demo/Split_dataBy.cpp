// A C/C++ program for splitting a string 
// using strtok() 
#include <stdio.h> 
#include <string.h> 

char* Token(char str[100], char TBy[3], int count){  
	int CountTk = 1;
	// Returns first token 
	char *token = strtok(str, TBy); 
	
	while (token != NULL){ 	
		if( CountTk == count){ 
			printf("%s\n", token);
			return token;	
		} 
		
		token = strtok(NULL, TBy);
		CountTk++;
	} 
	return "NotFound"; 
} 


int main(){
	char str[200] ="Geeks-for-Weerayut";
	char TokenBy[3] = "-";
	Token(str, TokenBy, 2);
}
