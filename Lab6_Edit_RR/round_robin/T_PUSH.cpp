// By Weerayut Buaphet
// https://github.com/weerayutbu

#include<stdio.h>
#include<conio.h>

#include "process.h"

#include "queue.h"
#include "process_push.h"
#include "process_management.h"
#include "process_load.h"
#include "function.h"

#include "short_job_first_scheduling_P.h"
#include "short_job_first_scheduling_NP.h"
#include "round_robin_scheduling.h"


void __TEST_FIFO(int &At){
	At = 1;
	Push_FIFO( 1, At);						//NewProcess, AT
	Push_FIFO( 2, At);						
	Push_FIFO( 3, At);														// 1 -> 2 -> 3		
	
	ShowAllQueue();
}

void __TEST_SJF(int &At){
	At = 2;
	Push_SJF( 1, At);						//NewProcess, AT	// 9
	Push_SJF( 2, At);											// 3
	Push_SJF( 3, At);											// 5		// 2 -> 3 -> 1		
		 
}

void __TEST_PRIO(int &At){
	At = 3;
	Push_PRIO( 1, At);						//NewProcess, AT	// 3
	Push_PRIO( 2, At);											// 5
	Push_PRIO( 3, At);											// 1		// 3 -> 1 -> 2	
	
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
	//	PushP(Info, At, "FIFO");
	//	PushP(Info, At, "PRIO");
	}
}														

int main(){
	int a = 1;
	int *At = &a;
	setTable(Info);	

//PUSH
	//__TEST_FIFO( *At );
	//__TEST_SJF(  *At );
	//__TEST_PRIO( *At );
	
	//__ARRIVED_PROCESS( *At );
	
	
}
