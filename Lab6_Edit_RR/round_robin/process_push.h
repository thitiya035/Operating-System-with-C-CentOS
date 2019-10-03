// By Weerayut Buaphet
// https://github.com/weerayutbu

int PushP(struct Process Info[NProcess], int &at, char Algo[10]);
int Push_SJF( int newP, int at);
int Push_PRIO(int newP, int at);
int Push_FIFO(int newP, int at);

//push process 
int PushP(struct Process Info[NProcess], int &at, char Algo[10]){		// pushP(Info, *At, "SJF")		//SJF, FIFO, PRIO		
	int NewProcess = 0;													// to count new process
	for(int j = 1 ; j<= NProcess; j++ ){
		
		// push when process arrived
		if(Info[j].AT == at and Info[j].REMAIN > 0 and Info[j].PID > 0){ // printf("at( %d )Insert: %d\n", at, Info[j].PID);
			int flag 	= 1;				// Initial flag by 1
			int newP 	= Info[j].PID;		// Get new process ID
			int newP_BT = Info[j].BT;		// Get Burst time new process
			
			printf("\nat:%-2d: (P%d)ARRI  %15s",at, Info[newP].PID," ");
			
			if(Algo == "SJF"){				// Check algorithm
				Push_SJF(newP, at);			// Push process in queue by algorithm
			}else if( Algo == "FIFO"){
				Push_FIFO(newP, at);
			}else if( Algo == "PRIO"){
				Push_PRIO(newP, at);
			}
			
			NewProcess++;					// Increase when have a new process
		}
	}
	
	return NewProcess;						// Return if have some process 
}

int Push_SJF(int newP, int at){
	int newP_BT  = Info[newP].REMAIN;
	int Nq       = DataInQueue();
	int flag 	 = 1;
	
	if(DataInQueue() == 0 and newP > 0 ){
		insertCQ(newP);
		printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-7s%-50s|", at, Info[newP].PID, "PUSH", "SJF", "ST", "NEW*",	"" );
	
	} else {
		for( int i = 0 ; i < Nq ; i++ ){
	
			int PIDq        = deleteCQ();
			int PIDq_Remain = Info[PIDq].REMAIN;
		
			if(newP_BT < PIDq_Remain and (flag == 1) ){								//insertion when new process burst time less than P in Q
				insertCQ(newP);
				insertCQ(PIDq);
				flag = 0;
				printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-7s%-50s|", at, Info[newP].PID, "PUSH", "SJF", "", "N<Q",	"new1" );
//2				printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-7s%-50s|", at, Info[PIDq].PID, "PUSH", "SJF", "", "N<Q",	"Q" );
	
			} else if(newP_BT >= PIDq_Remain and (flag == 1) and (i == Nq-1) ){		//insertion when new process burst time more than last process in Q
				insertCQ(PIDq);
				insertCQ(newP);
				flag = 0;
				
//2				printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-7s%-50s|", at, Info[PIDq].PID, "PUSH", "SJF", "", "END",	"Q" );
				printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-7s%-50s|", at, Info[newP].PID, "PUSH", "SJF", "", "END",	"new2" );
				
			} else {																//insertion when new process inserted 
				insertCQ(PIDq);
//2				printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-7s%-50s|", at, Info[PIDq].PID, "PUSH", "SJF", "", "   ","Q" );
			
			}
		}
	}
//1	ShowAllQueue();
}

int Push_PRIO(int newP, int at){
	
	int newP_PRI = Info[newP].PRI;
	int Nq       =  DataInQueue();
	int flag 	 = 1;
	
	if(DataInQueue() == 0 and newP > 0 ){
		insertCQ(newP);
		printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-5s%52s|", at, Info[newP].PID, "PUSH", "PRIO", "ST", "NEW*",	"" );
	}else{
	
		for( int i = 0 ; i < Nq ; i++ ){
			int PIDq = deleteCQ();
			int PIDq_PRI = Info[PIDq].PRI;
	
			if(newP_PRI < PIDq_PRI and (flag == 1) ){							//insertion when new process Priority less than P in Q
				insertCQ(newP);
				insertCQ(PIDq);
				flag = 0;
				
				printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-5s%-52s|", at, Info[newP].PID, "PUSH", "PRIO", "", "N<Q",	"new" );
				printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-5s%-52s|", at, Info[PIDq].PID, "PUSH", "PRIO", "", "N<Q",	"Q" );

	
			} else if(newP_PRI >= PIDq_PRI and (flag == 1) and (i == Nq-1) ){	//insertion when new process priority more than last process in Q
				insertCQ(PIDq);
				insertCQ(newP);
				flag = 0;
					
				printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-5s%-52s|", at, Info[PIDq].PID, "PUSH", "PRIO", "", "END",	"Q" );
				printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-5s%-52s|", at, Info[newP].PID, "PUSH", "PRIO", "", "END",	"new" );
			
			} else{																	//insertion when new process inserted 
				insertCQ(PIDq);
				printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-5s%-52s|", at, Info[PIDq].PID, "PUSH", "PRIO", "", "",	"Q" );
				
			}
		}	
	}
//	ShowAllQueue();
}

int Push_FIFO(int newP, int at){
	insertCQ(newP);
	printf("\nat:%-2d: (P%d)%-7s%-5s%-4s:%-5s%-52s|", at, Info[newP].PID, "PUSH", "FIFO", "ST", "NEW", "" );
	ShowAllQueue();
}
