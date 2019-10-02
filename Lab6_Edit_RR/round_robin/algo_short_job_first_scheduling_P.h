void SavePP(int Temp_PID, int &at ,int INC);
void ExecuteP_P(int Temp_PID, int &at, int &Fl);
void SJF_Preemp(struct Process Info[NProcess]);

void ExecuteP_PP(int Temp_PID, int &at, int &Fl){

	Info[Temp_PID].REMAIN--;							// - time to use for execute
	printf("\nat:%-2d: (P%d)%-16s:%7sBT: %-5dREM: %-5dPRI: %-5d%21s|", at, Temp_PID, "EXEC", " ", Info[Temp_PID].BT, Info[Temp_PID].REMAIN, Info[Temp_PID].PRI,"" );
	
	// set next state
	if( Info[Temp_PID].REMAIN == 0){
		Info[Temp_PID].PS = 'S'; 						//save
	}
	
}
void SJF_Preemp(struct Process Info[NProcess]){
	int Interrup	= 0;
	int Temp_PID = 0;									// PID Process is exeuting
	int PID_PREV = 0;
	int Temp_QT = 0;									// Quantum time Process is exeuting
	int Turn = 0;
	int max = 0;										// max time the process will execute
	int m;
	
	for(m = 1; m <= NProcess; m++){
		max += Info[m].BT;								// all time to executing
	}
	
	int Arrival = 0;
	int *At = &Arrival;
	int *Tu = &Turn;
	
	for(*At = 0; *At <= max ; *At += 1 ){						// Simulation Operating System is processing 
		int Temp_POUT 	= 0;
		Temp_POUT 		= Info[Temp_PID].OUT;					// for set to .IN next process
		
		// push process
		int NewProcess  = PushP(Info, *At, "SJF");			// insert when have new process in Q

		//check interrup
		if(NewProcess >= 1 and Temp_PID >= 1){
			Interrup = CheckInterrupSJF(Temp_PID, *At);
			if(Interrup > 0){
				printf("\n(*)");
			}
			NewProcess = 0;
		}
				
		//save
		if( Temp_PID > 0 &&( Info[Temp_PID].PS == 'S' || Interrup > 0 )){
			SavePP(Temp_PID, *At, 0);
			*Tu = 0;
			Temp_PID = 0;
			Interrup = 0;
		}

		// load
		if(DataInQueue()>=1){						// Q >= 1 have process in Q 

			if( (Info[Temp_PID].PS == 'I' || Temp_PID == 0 ) && *Tu == 0 ){
				
				Temp_PID = LoadProcess(*At);
				*Tu = 1;
				
				//change process
				if(Temp_PID != Sequence[p_alg][p_pro-1]){
//1					printf("P%-3d-> ", Temp_PID);
					Sequence[p_alg][p_pro] = Temp_PID;
					p_pro++;
				}
				PID_PREV = Temp_PID;
			}
		}

		//execute
		if( *Tu == 1 ){
			ExecuteP_PP(Temp_PID, *At, *Tu);
		}
		
		//save
		if( Temp_PID > 0 &&( Info[Temp_PID].PS == 'S')){
			SavePP(Temp_PID, *At, 1);
			*Tu = 0;
			Temp_PID = 0;
		}
		
		if(Check_Process_Terminate() != 0 and max == 0){
			max+=1;
		}
		
	}
	//ShowAllQueue();
}


