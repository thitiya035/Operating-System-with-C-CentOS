#include<stdio.h>
#include<conio.h>
#include "queue.h"

int main(){
	printf("CICULAR QUEUE PROGRAM..\n");
	printf("=========================");
	ch = ' ';
	while(ch != 'E'){
		printf("\n[1=Insert		:2=DELETE	E:Exit] : ");
		ch = getch();
		switch(ch){
			case '1' : printf("\nInsert Number : ");
					   scanf("%d", &x);
					   insertCQ(x);
					   ShowAllQueue();
					   break;
			case '2' : x = deleteCQ();
					   printf("\nData from Queue =%d\n",x);
					   ShowAllQueue();
					   break;
		}
	}
}
