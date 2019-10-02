// save Round Robin

void SaveRR(int Temp_PID, int &at ,int INC, int &Qt){
	// Calculation waiting time and Save Waiting
	printf("\nat:%-2d: (P%d)%-16s:%7s"	, at, Temp_PID, "SAVE", " ");
	
	Info[Temp_PID].WAITING += Info[Temp_PID].IN - Info[Temp_PID].OUT;
	printf("IN: %-5dOUT: %-5dWAI: %-5d", Info[Temp_PID].IN, Info[Temp_PID].OUT, Info[Temp_PID].WAITING);

	// Save OUT
	Info[Temp_PID].OUT = at + INC;
	printf(">> OUT: %-3d%10s|"	, Info[Temp_PID].OUT, "" );	

	// set next state
	Info[Temp_PID].PS = 'I'; 		// Save -> Load
	Qt = 0;
	
}


// save short job first - preeamtive
void SavePP(int Temp_PID, int &at ,int INC){
	// Calculation waiting time and Save Waiting
	printf("\nat:%-2d: (P%d)%-16s:%7s"	, at, Temp_PID, "SAVE", " ");
	Info[Temp_PID].WAITING += Info[Temp_PID].IN - Info[Temp_PID].OUT;
	printf("IN: %-5dOUT: %-5dWAI: %-5d", Info[Temp_PID].IN, Info[Temp_PID].OUT, Info[Temp_PID].WAITING);
	
	// Save OUT
	Info[Temp_PID].OUT = at + INC;
	printf(">> OUT: %-3d%10s|"	, Info[Temp_PID].OUT, "" );
	
	// set next state
	Info[Temp_PID].PS = 'I'; 		// save 
	
	// push to queue
	if(Info[Temp_PID].REMAIN > 0){
		Push_SJF(Temp_PID, at);
		printf("\nat:%-2d: (P%d)%-16s:%57s|", at, Temp_PID, "INSE", "");
		ShowAllQueue();
	}
}

// save short job first - non preeamtive
void SaveNP(int Temp_PID, int &at ,int INC){
	// Calculation waiting time and Save Waiting
	
	printf("\nat:%-2d: (P%d)%-16s:%7s"	, at, Temp_PID, "SAVE", " ");	
	Info[Temp_PID].WAITING += Info[Temp_PID].IN - Info[Temp_PID].OUT;
	printf("IN: %-5dOUT: %-5dWAI: %-5d", Info[Temp_PID].IN, Info[Temp_PID].OUT, Info[Temp_PID].WAITING);
	
	// Save OUT
	Info[Temp_PID].OUT = at + INC;
	printf(">> OUT: %-3d%10s|"	, Info[Temp_PID].OUT, "" );
	
	// set next state
	Info[Temp_PID].PS = 'I'; 		// Save -> Load
}

// save priority 

void SavePRIO(int Temp_PID, int &at ,int INC){
	// Calculation waiting time and Save Waiting
	
	printf("\nat:%-2d: (P%d)%-16s:%7s"	, at, Temp_PID, "SAVE", " ");	
	Info[Temp_PID].WAITING += Info[Temp_PID].IN - Info[Temp_PID].OUT;
	printf("IN: %-5dOUT: %-5dWAI: %-5d", Info[Temp_PID].IN, Info[Temp_PID].OUT, Info[Temp_PID].WAITING);
	
	// Save OUT
	Info[Temp_PID].OUT = at + INC;
	printf(">> OUT: %-3d%10s|"	, Info[Temp_PID].OUT, "" );
	
	// set next state
	Info[Temp_PID].PS = 'I'; 		// Save -> Load
	
	// push to queue
	if(Info[Temp_PID].REMAIN > 0){
		Push_PRIO(Temp_PID, at);
		printf("\nat:%-2d: (P%d)%-16s:%57s|", at, Temp_PID, "INSE", "");
		ShowAllQueue();
	}
}

