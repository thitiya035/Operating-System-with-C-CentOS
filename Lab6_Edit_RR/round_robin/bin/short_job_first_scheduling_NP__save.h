int LoadP(int &at);
void ExecuteP_NP(int Temp_PID, int &at, int &Fl);
void SaveP(int Temp_PID, int &at ,int INC);


void ExecuteP_NP(int Temp_PID, int &at, int &Fl){
//1	printf("\nat:%-3d: exec(P%d)   ", at, Temp_PID);
//1	Info[Temp_PID].REMAIN--;							// - time to use for execute
//1	printf("%10s%-2d", "REMAIN: ",Info[Temp_PID].REMAIN);
//1	ShowAllQueue();
	
	// set next state
	if( Info[Temp_PID].REMAIN == 0){
		Info[Temp_PID].PS = 'S'; 						//Terminate -> Save
	}
}

void SaveNP(int Temp_PID, int &at ,int INC){
	// Calculation waiting time and Save Waiting
//1	printf("\nat:%-3d: save(P%d)   ", at, Temp_PID);
	
	Info[Temp_PID].WAITING += Info[Temp_PID].IN - Info[Temp_PID].OUT;

//1	printf("%10s%-5d", "WAITING: ", Info[Temp_PID].WAITING);

//2	printf("%5s%-5d", " IN: ",Info[Temp_PID].IN);	
//2	printf("%5s%-5d", "OUT: ",Info[Temp_PID].OUT);	

	// Save OUT
	Info[Temp_PID].OUT = at + INC;
//1	printf("%5s%-5d", "OUT: ",Info[Temp_PID].OUT);
	
	// set next state
	Info[Temp_PID].PS = 'I'; 		// Save -> Load
}

//swapQ(Info);
void SJF_NPreemp(struct Process Info[NProcess]){
	int Temp_PID = 0;								// PID Process is exeuting
	int Temp_QT = 0;								// Quantum time Process is exeuting
	
	int Turn = 0;
	
	int max = 0;									// max time the process will execute
	int m;										
	for(m = 1; m <= NProcess; m++){
		max += Info[m].BT;							// all time to executing
	}
	
	int Arrival = 0;
	int *At = &Arrival;
	int *Tu = &Turn;
	
	for(*At = 0; *At <= max ; *At += 1 ){				// Simulation Operating System is processing 
//1		printf("\n");
		int Temp_POUT 	= 0;
		Temp_POUT 		= Info[Temp_PID].OUT;		// for set to .IN next process

		PushP(Info, *At);							// insert when have new process in Q
		
		// load
		if(DataInQueue()>=1){						// Q >= 1 have process in Q 
			swapQ(Info);
			if(*Tu == 0 && (Info[Temp_PID].PS == 'I') || (Temp_PID == 0 && *Tu == 0) ){
				Temp_PID = LoadP(*At);
				*Tu = 1;
				printf(" P%d -> ", Temp_PID);
			}
		}
		
			
		if( *Tu == 1 ){
			
			//execute
			ExecuteP_NP(Temp_PID, *At, *Tu);
		
			//save
			if(Info[Temp_PID].PS == 'S'){
				SaveNP(Temp_PID, *At, 1);		// increate time use
				*Tu = 0;
				Temp_PID = 0;
			}
		}
		
		// check remain time
		if(Check_Termi_All() != 0 && max == 0){
			max+=1;
		}
	}
	//ShowAllQueue();
}

