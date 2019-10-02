#include<stdio.h>
#include<conio.h>

void add( int &a){
	a += 1;
	printf("%d", a);
	
}

int main(){
	int Arrival = 0;
	int *at = &Arrival;
	*at = 10;
	printf("%d\n", Arrival);
	add(*at);
	printf("\n%d", Arrival);
}
