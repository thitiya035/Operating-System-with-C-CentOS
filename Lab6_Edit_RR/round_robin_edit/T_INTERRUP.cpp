#include<stdio.h>
#include<conio.h>
#include "process.h"
#include "queue.h"
#include "process_push.h"
#include "process_management.h"
#include "process_load.h"
#include "function.h"
#include "Interrup.h"

#include "short_job_first_scheduling_P.h"
#include "short_job_first_scheduling_NP.h"
#include "round_robin_scheduling.h"


void __Interrup(int &At){
	int Temp_PID = 1;
	At 		 	 = 5;

	int Interrup = CheckInterrup(Temp_PID, At);
	if(Interrup > 0){
		printf("\n(*)");
	}
}

void __ARRIVED_PROCESS(int &At){
	int m, max = 0;					
	At = 0;

	for(m = 1; m <= NProcess; m++){
		max += Info[m].BT;										// ALL BURST TIME
	}
	
	for(At = 0; At <= max ; At += 1 ){
	
		//ARRIVAL
		PushP(Info, At, "SJF");
//1		PushP(Info, At, "FIFO");
//1		PushP(Info, At, "PRIO");
	}
}														

int main(){
	int a = 1;
	int *At = &a;
	setTable(Info);	
	
	__ARRIVED_PROCESS( *At );
	//printf("\n");
	//ShowAllQueue();
	
	__Interrup(*At);
	
	
}
