// By Weerayut Buaphet
// https://github.com/weerayutbu

#include<stdio.h>
#include<conio.h>
#define NPro 19

int process[NPro] = { 2, 1, 2, 3, 7, 6, 2, 3, 4, 2, 1, 5, 6, 3, 2, 3, 6, 2, 1};
//int process[NPro] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

#include "queue.h"
#include "Page_Replacement.h"

// function queue file
void ShowAllQueue();											// To show all data in queue
int DataInQueue();												// To show how many data in queue
int deleteCQ();													// To delete data and get PID from Q
int insertCQ( int y);											// To insert data at the last one in queue

// function page replacement
void FIFO_page_replacement();
void OPTIMAL_page_replacement();
void LRU_page_replacement();


int main(){
//	FIFO_page_replacement();
	OPTIMAL_page_replacement();
//	LRU_page_replacement();

}
