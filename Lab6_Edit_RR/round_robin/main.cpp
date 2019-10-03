// By Weerayut Buaphet
// https://github.com/weerayutbu

#include<stdio.h>
#include<conio.h>
#include<string.h>

#include "process.h"
#include "queue.h"
#include "process_push.h"
#include "process_management.h"
#include "process_load.h"
#include "process_save.h"
#include "function.h"
#include "Interrup.h"

#include "algo_short_job_first_scheduling_P.h"
#include "algo_short_job_first_scheduling_NP.h"
#include "algo_round_robin_scheduling.h"
#include "algo_Priority_scheduling.h"

// function
// Queue management
int insertCQ(int x);											// insert Q Function to save PID in Q
int deleteCQ();													// delete Q Function to delete and get PID from Q 
void showQ(struct Process Info[NProcess]);						// To show data in Q
void swapQ(struct Process Info[NProcess]);						// not use
int PushP(struct Process Info[NProcess], int &at);				// To push process in Q // not use

//check process
int Check_Termi_All();											// Check all process are terminate for exit from loop
void ShowAllQueue()	;											// To show PID in Q Function
void printall( struct Process Info[NProcess]);					// To show Process data in Q 

//sjf non preemtive 
void SJF_NPreemp(struct Process Info[NProcess]);				// To schedule process for execute by SJF_Non_Preemptive Algori
void ExecuteP_NP(int Temp_PID, int &at, int &Fl);				// To excute Process SJF_Non_Preemptive Algori

//sjf preemtive 
void SJF_Preemp(struct Process Info[NProcess]);					// To schedule process for execute by SJF_Preemptive Algori
void ExecuteP_P(int Temp_PID, int &at, int &Fl);				// To excute Process SJF_Preemptive Algori

//rr 
void Round_R(struct Process Info[NProcess]);					// To schedule process for execute by Round Robin Algori
void ExecuteP_RR(int Temp_PID, int &at, int &Fl, int &Qt);		// To excute Process Round Robin Algori

//pri
void Priority(struct Process Info[NProcess]);					// To schedule process for execute by Priority Algori
void ExecuteP_PRIO(int Temp_PID, int &at, int &Fl);				// To excute Process Priority Algori

// fucntion file 
void show_algor( int pro_alg);									// To show waiting time log
void choose_head_menu();										// To show Algorithm and choose the algorithm 
float average_t(struct Process Info[NProcess]);					// To calculate average waiting time
void printall(struct Process Info[NProcess]);					// To show all Process data in Q
void showQ(struct Process Info[NProcess]);						// To show data in Q
void swapQ(struct Process Info[NProcess]);						// not use

// process_push file
int PushP(struct Process Info[NProcess], int &at, char Algo[10]);	// To push process in queue by Algorithm and check interrup
int Push_SJF( int newP, int at);									// To push process in queue sort by SJF
int Push_PRIO(int newP, int at);									// To push process in queue sort by PRIO
int Push_FIFO(int newP, int at);									// To push process in queue sort by FIFO

// process_load file
int LoadProcess(int &at);										// To load process from queue

// process_save file
void SaveRR(int Temp_PID, int &at ,int INC, int &Qt);			// To save process by FIFO
void SavePP(int Temp_PID, int &at ,int INC);					// To save process by Priority
void SaveNP(int Temp_PID, int &at ,int INC);					// To save process by SJF
void SavePRIO(int Temp_PID, int &at ,int INC);					// To save process by SJF

// queue file
void ShowAllQueue();											// To show all data in queue
int DataInQueue();												// To show how many data in queue
int deleteCQ();													// To delete data and get PID from Q
int insertCQ( int y);											// To insert data at the last one in queue

// process_management file
int Check_Process_Terminate();									// Check all process are terminate for exit from loop

//Interrup file
int CheckInterrupSJF(int PID, int &at);							// To check interrupt from SJF algorithm
int CheckInterrupPRIO(int PID, int &at);						// To check interrupt from Priority algorithm

int main(){
	while (1){
		setTable(Info);
		choose_head_menu();
		p_pro = 1;												// Use to choose to save log algorithm 
		switch (getch()) {										
				case '1': printf("\n## 1. Non Preemtive SJF Scheduling. ##\n"); 
						  p_alg = 1;							// set data for 
						  SJF_N_Preemp(Info);				    			
						  break;
						
				case '2': printf("\n## 2. Preemtive SJF Scheduling. ##\n");	  
						  p_alg = 2;
						  SJF_Preemp(Info);					   
						  break;
						
				case '3': printf("\n## 3. Round Robin Sheduling. ##\n");   
						  p_alg = 3;     
						  Round_R(Info);					   
						  break;
						
				case '4': printf("\n## 4. Priority Scheduling. ##\n");  
						  p_alg = 4;        
						  Priority(Info);						
						  break;
		}
		
		printall(Info);
		ShowAllQueue();
		
		printf("\n\n");
		show_algor(p_alg);
		getch();
	
	}
}


