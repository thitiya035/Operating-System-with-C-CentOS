#include<stdio.h>
#include<conio.h>

#define N 10

int Q[N];
int x, F = 0, R = 0;
char status = 'N';
char ch;

void insertQ(int y){
	if(R == N-1){
		printf("!!! Over Flow\n");
		status = 'O';
	}else{
		R = R+1;
		if(F==0){
			F++;
		}

		Q[R] = y;
	}
}

int deleteQ(){
	int y;
	if( F != 0){
		y = Q[F];

		if(F == R){
			F=0;
			R=0;
		}else{
			F++;
		}
		return (y);
	}else{
			printf("\n !!! Under Flow !!! ");
			status = 'U';
	}
}

void ShowAllQueue(){
	int i ;
	printf("N :%d\n",N-1);
	printf("Status : %c\n", status);
	printf("F :%d R: %d\n", F, R);
	for(i=1, i<N; i++){
		printf("%d :%d -",i, Q[i]);
	}
	printf("\n---------------------\n");
}

int main(){
	printf("Queue Program\n");

	while (status == 'N')
	{			
		printf("1=INSERT	2=DELETE");
		ch = getch();
		switch (ch)	{
			case '1':
				printf("\n Insert Number :");
				scanf("%d",&x);
				insertQ(x);
				ShowAllQueue();
				break;

			case '2':
				x = deleteQ();
				printf("\nData from Queue = %d\n",x);
				ShowAllQueue();
				break;
		}
	}

	printf("\n");
	return 0;
	
}


