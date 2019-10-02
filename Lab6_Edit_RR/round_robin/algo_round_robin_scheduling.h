
void ExecuteP_RR(int Temp_PID, int &at, int &Fl, int &Qt){

	Info[Temp_PID].REMAIN--;							// - time to use for execute
	Qt -= 1;
	printf("\nat:%-2d: (P%d)%-16s:%7sBT: %-5dREM: %-5dPRI: %-5d%21s|", at, Temp_PID, "EXEC", " ", Info[Temp_PID].BT, Info[Temp_PID].REMAIN, Info[Temp_PID].PRI,	"" );
	
	// set next state
	if( Info[Temp_PID].REMAIN == 0){
		Info[Temp_PID].PS = 'S'; 						//save
		Qt = 0;
	}

	if(Info[Temp_PID].REMAIN > 0 and Qt == 0){
		insertCQ(Temp_PID);
		Info[Temp_PID].PS = 'S'; 
	}
}


void Round_R(struct Process Info[NProcess]){
	#define Quantum_time 4
	//swapQ(Info);
	int Temp_PID = 0;									// PID Process is exeuting
	int Temp_QT = 0;									// Quantum time Process is exeuting
	int Turn = 0;
	int Temp_qt = 0;
	int max = 0;										// max time the process will execute
	int m;					
					
	for(m = 1; m <= NProcess; m++){
		max += Info[m].BT;								// all time to executing
	}
	
	int Arrival = 0;
	int *At = &Arrival;
	int *Tu = &Turn;
	int *Qt = &Temp_qt;
	
	for(*At = 0; *At <= max ; *At += 1 ){
		
//1		printf("\n\nat:%-3d:%d ", *At,*Qt);
		int Temp_POUT 	= 0;
		Temp_POUT 		= Info[Temp_PID].OUT;							// for set to .IN next process
		PushP(Info, *At, "FIFO");										// insert when have new process in Q

		//load
		if(DataInQueue()>=1 and *Qt == 0){								// Q >= 1 have process in Q 
			if( (Info[Temp_PID].PS == 'I' || Temp_PID == 0 ) && *Tu == 0 ){
				Temp_PID = LoadProcess(*At);
				*Tu = 1;
				*Qt = Quantum_time;
//1				printf(" P%d -> ", Temp_PID);


				// save log sequence
				if(Temp_PID != Sequence[p_alg][p_pro-1]){
					Sequence[p_alg][p_pro] = Temp_PID;
					p_pro++;
				}

			}
		}

		//execute
		if( *Tu == 1 and (*Qt>0 and Info[Temp_PID].REMAIN>0 ) ){
			ExecuteP_RR(Temp_PID, *At, *Tu, *Qt);
		}
		
		//save
		if( Temp_PID > 0 &&( Info[Temp_PID].PS == 'S' || *Qt == 0 || Info[Temp_PID].REMAIN == 0  )){
			SaveRR(Temp_PID, *At, 1, *Qt);
			*Tu = 0;
			Temp_PID = 0;

		}
		
		if(Check_Process_Terminate() != 0 and max == 0){
			max+=1;
		}
		
	}
	
	//ShowAllQueue();
}

