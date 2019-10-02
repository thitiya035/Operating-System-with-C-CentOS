#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Int2String1(){
	int num = 321;
	char snum[5];
	// convert 123 to string [buf]
	itoa(num, snum, 10);
	
	// print our string
	printf("%s\n", snum);
}

//the best way
char* Float2String( float num){ 
	char result[50]; 
	sprintf(result, "%f", num); 
	printf("The string for the num is %s\n", result); 
	return result;
} 

char* Int2String( int num){ 
	char result[50]; 
	sprintf(result, "%d", num); 
	printf("The string for the num is %s\n", result); 
	return result;
} 

int main(){
	char String[20];
	strcpy(String, Int2String(23.34));
	printf("snum: %s\n", String);
	getchar(); 
}
