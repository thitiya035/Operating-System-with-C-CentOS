int LoadP(int &at);
void ExecuteP_NP(int Temp_PID, int &at, int &Fl);
void SaveP(int Temp_PID, int &at ,int INC);


void ExecuteP_PRIO(int Temp_PID, int &at, int &Fl){

	Info[Temp_PID].REMAIN--;							// - time to use for execute
	printf("\nat:%-2d: (P%d)%-16s:%7sBT: %-5dREM: %-5dPRI: %-5d%21s|", at, Temp_PID, "EXEC", " ", Info[Temp_PID].BT, Info[Temp_PID].REMAIN, Info[Temp_PID].PRI,"" );
	ShowAllQueue();
	
	// set next state
	if( Info[Temp_PID].REMAIN == 0){
		Info[Temp_PID].PS = 'S'; 						//Terminate -> Save
	}
}


void Priority(struct Process Info[NProcess]){
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
		int Interrup	= 0;
		int Temp_POUT 	= 0;
		Temp_POUT 		= Info[Temp_PID].OUT;			// for set to .IN next process
		int NewProcess  = PushP(Info, *At, "PRIO" );		// insert when have new process in Q

  /*
		// preemtive
		// check interrup
		if(NewProcess >= 1 and Temp_PID >= 1){
			Interrup = CheckInterrupPRIO(Temp_PID, *At);
			if(Interrup > 0){
				printf("\n(*)");
			}
			NewProcess = 0;
		}
		
		//save
		if( Temp_PID > 0 &&( Info[Temp_PID].PS == 'S' || Interrup > 0 )){
			SavePRIO(Temp_PID, *At, 0);
			*Tu = 0;
			Temp_PID = 0;
			Interrup = 0;
		}
			
  */		
		// load
		if(DataInQueue()>=1){						// Q >= 1 have process in Q 
			if(*Tu == 0 && (Info[Temp_PID].PS == 'I') || (Temp_PID == 0 && *Tu == 0) ){
				Temp_PID = LoadProcess(*At);
				*Tu = 1;
//1				printf(" P%d -> ", Temp_PID);

			// save log sequence
			if(Temp_PID != Sequence[p_alg][p_pro-1]){
				Sequence[p_alg][p_pro] = Temp_PID;
				p_pro++;
				}
			}

		}
		
		//execute
		if( *Tu == 1 ){
			ExecuteP_PRIO(Temp_PID, *At, *Tu);
		}

		//save
		if(Temp_PID > 0 && Info[Temp_PID].PS == 'S'){
			SavePRIO(Temp_PID, *At, 1);		// increate time use
			Temp_PID = 0;
			*Tu = 0;
		}

		
		// check remain time
		if(Check_Process_Terminate() != 0 && max == 0){
			max+=1;
		}
	}
	
	//ShowAllQueue();
}

