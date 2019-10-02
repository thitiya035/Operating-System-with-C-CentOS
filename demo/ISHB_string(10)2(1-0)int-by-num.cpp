#include<stdio.h>
#include<conio.h>
#include<stdio.h>

int main(){
	char data[10] = "01234";
	
	printf("data[0] : %d\n", data[0]);
	printf("data[8] : %d\n", data[8]);
	printf("\n\n");

	for( int i = 0 ; i < 10 ; i++ ){

		int temp = 0;
		
		if( data[i] >= 48 ){
			temp = data[i]-48;	
		}else{
			temp = 0;
		}
	
		printf("%10d\n",  temp);
	}
}
