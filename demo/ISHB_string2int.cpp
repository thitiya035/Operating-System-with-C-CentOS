#include<stdio.h>
#include<stdlib.h>
#define MaxString  20

int String2Int( char s[MaxString]){
	return atoi(s);
}

int main(){
	printf("int :%d \n", String2Int("1234"));
}
