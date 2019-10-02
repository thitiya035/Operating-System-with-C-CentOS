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
//	printf("Yes, It is a number.\n");
    return true; 
}

int InputInt(){
	
	char str[MaxString];
	scanf("%s", str);
	
	if(IsNumber(str) == 1 ){
//		printf("yes\n");
		return String2Int(str);
		
	}else{
//		printf("not\n");
		InputInt();
	}
}

int InputIntByRange( int min, int max){
	printf("Input Number Between :%d - %d : ", min, max);
	
	int data = InputInt();
	
	if( max >= data and min <= data){
		return data;
	}else{
		printf("Incorrect Min:%d Max:%d Input: %d\n", min, max, data);
		InputIntByRange(min, max);
	}
}


int main(){
	int min = 1;
	int max = 2;
	printf("%d", InputIntByRange(min, max));

}
