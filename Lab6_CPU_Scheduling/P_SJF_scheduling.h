// By Weerayut Buaphet
// https://github.com/weerayutbu

//------------- preemptive SJF scheduling. -------------------------------------

int execute_SJF_Pre(struct Process Info[NumOfPro], int ex_pid, int QT, int at){
	int FreeTime = 0;
	
	if( Info[ex_pid].PC > 1){
		Info[ex_pid].PC -= 1;
	}else if ( Info[ex_pid].PC <= 1 ){							// Check for terminate, when PC = BT - Work_time == 0
		Info[ex_pid].PS = 0;	
		Info[ex_pid].PC = 0;									
	}

	if(Info[ex_pid].WT == 0 && Info[ex_pid].OutP == 0){			// Check start process
		Info[ex_pid].WT = at - Info[ex_pid].AT;
	}else{
		Info[ex_pid].WT += at - Info[ex_pid].OutP;
	}

	Info[ex_pid].OutP = at + QT;								// Set wait time

	//printf("IN:%-10dOUT:%-10dWT:%-10d", at, Info[ex_pid].OutP, Info[ex_pid].WT);
	
	if( TempPExecut != ex_pid && ex_pid >= 1){					// Check change process
		//printf("\tCh_Pro :: PID( %-2d-> %-2d)",TempPExecut, ex_pid, at, Info[ex_pid].AT);							//When change process to execution				
		printf("P%d->",ex_pid);
		TempPExecut = ex_pid;
	}
	
	return FreeTime;	
}


int check_minPC(struct Process Info[NumOfPro],int ProAT[NumOfPro] ,int count){
	int i	 	= 1;
	int Tpro 	= 0;
	int PC_PID 	= 0;
	
	if(count <= 0 ){
		return 0;
	} 
	
	Tpro = Info[ProAT[i]].PC;
	PC_PID = ProAT[i];
	i++;

	for( i; i <= count ; i++){
		if( Tpro > Info[ProAT[i]].PC){
			Tpro = Info[ProAT[i]].PC;
			PC_PID = ProAT[i];
		}
	}
	return PC_PID;
}

void SJF_Pre( struct Process Info[NumOfPro] ){
	printf("## 2.Preemptive SJF scheduling ##\n");
	printf("---------------------------------------------------------------\n");
	printf("Sequence process is :");

	int at = 0;
	int SJF_pre_PAT[NumOfPro];
		
	int TempAt = 0;
	int TempBt = 0;
	
	while(1){		
		//printf("\n at -> %-15d",at);
		int count 	= check_AT(Info,SJF_pre_PAT,at);				// Process are arrive	
		if(count != 0){
			int Ex_PID 	= check_minPC(Info,SJF_pre_PAT, count);		// Process is going work by minBT
			execute_SJF_Pre(Info, Ex_PID, 1, at);
		}
		at+=1;
		
		if(at >= 50 || check_pre_stop(Info) ){
			break;	
		}
	}
}

