#include<stdio.h>
#include<stdlib.h>
#include <iostream> 
#include <string.h>
#define MaxString  20

int String2Int( char s[MaxString]){
	return atoi(s);
}

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

int InputInt(){
	char str[MaxString];
	printf("Input Int Number : ");
	scanf("%s", str);
	
	if(IsNumber(str) == 1 ){
//		printf("yes\n");
		return String2Int(str);
		
	}else{
//		printf("not\n");
		InputInt();
	}
}

int main(){
	printf("Final Data: %d",InputInt());
}
