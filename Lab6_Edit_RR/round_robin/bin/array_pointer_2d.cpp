#include<stdio.h>
#include<conio.h>

int wating[5][20];
// 1. sjf preemtive
// 2. sjf non-preemtive
// 3. round robin
// 4. priority

int main(){
	
	for(int i = 1 ; i <= 5 ; i++ ){
		for(int j = 1; j<= 10; j++){
			wating[i][j] = 0;
		}
	}
	
	*wating;
	*wating=10;
	
	
	for(int i = 1 ; i <= 5 ; i++ ){
		for(int j = 1; j<= 10; j++){
			printf("%2d \n", wating[i][j]);
			if(wating[i][j] > 0){
				printf("*******************");
			}
		}
	}
	
}
