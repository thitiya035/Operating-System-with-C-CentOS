// By Weerayut Buaphet
// https://github.com/weerayutbu

//------------- Non preemptive SJF scheduling. -------------------------------------
int execute_SJF_NPre(struct Process Info[NumOfPro], int ex_pid, int at){
	

	if(Info[ex_pid].WT == 0 && Info[ex_pid].OutP == 0 && at == 0){			// Check start process
		Info[ex_pid].WT = at - Info[ex_pid].AT;
	}else{
		Info[ex_pid].WT = at - Info[ex_pid].AT;
	}
	
	if( TempPExecut != ex_pid && ex_pid >= 1){					// Check change process
		//printf("\tCh_Pro :: PID( %-2d-> %-2d)",TempPExecut, ex_pid, at, Info[ex_pid].AT);							//When change process to execution				
		printf("P%d->",ex_pid);
		TempPExecut = ex_pid;
	}
	
	Info[ex_pid].PS = 0;								//Terminate
	Info[ex_pid].PC = 0;
	
	return Info[ex_pid].BT;
}



void SJF_Non( struct Process Info[NumOfPro]){
	printf("## 1.Non preemptive SJF scheduling ##\n");
	printf("---------------------------------------------------------------\n");
	printf("Sequence process is :");
	int at = 0;
	int i  = 1;
	int SJF_Non_PAT[NumOfPro];
	int Timeuse = 0;
	
	int TempAt = 0;
	int TempBt = 0;
	
	int j = 1;
	for(j ; j <= NumOfPro; j++){
		Info[j].AT = 0;
	}
	
	while(1){
		
		//printf("\nAT:%d :: ",at);
		//int Timeuse = execute(Info, Ex_PID, "non_pre_SJF", at);
		int count 	= check_AT(Info,SJF_Non_PAT,at);			// Process are arrive	
		if(count != 0){
			
			int Ex_PID 	= check_minBT(Info,SJF_Non_PAT, count);		// Process is going work by minBT
			Timeuse = execute_SJF_NPre(Info, Ex_PID, at);			// at = 0;
						
			if(Timeuse == 0){
				at+=0;					//1 when use at table 
			}else{
				at+=Timeuse;
			}
		}else{
			at++;
		}
		//printf("AT:%d :: ",at);
		
		if(at >= 50 || check_pre_stop(Info) ){
			break;	
		}
	}	

}

