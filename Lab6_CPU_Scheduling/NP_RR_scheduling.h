

int executeRR(struct Process Info[NumOfPro], int ex_pid, int QT, int at){
	
	int FreeTime = 0;
	if( TempPExecut != ex_pid ){
		printf(" P%d -> ",ex_pid);							//When change process to execution				
		TempPExecut = ex_pid;
	}
	//printf("**** PC:%d PS:%d QT:%d at:%d WT%d\n",Info[ex_pid].PC,Info[ex_pid].PS,QT, at, Info[ex_pid].WT);

	if( Info[ex_pid].PC >= QT){
		Info[ex_pid].PC -= QT;
		
	}else if(Info[ex_pid].PC > 0){
		FreeTime =  QT - Info[ex_pid].PC;
		Info[ex_pid].PC = 0;
		Info[ex_pid].PS = 0;
	}

	if( Info[ex_pid].PC <= 0 ){							// Check for terminate, when PC = BT - Work_time == 0
		Info[ex_pid].PS = 0;							// Terminate
	}

	int temp = 	Info[ex_pid].WT + at - Info[ex_pid].OutP;
	Info[ex_pid].WT = temp;

	//printf("IN:%d	OUT:%d  WT%d", at, Info[ex_pid].OutP, Info[ex_pid].WT);
	Info[ex_pid].OutP = at + QT - FreeTime;
	
	return FreeTime;	
}
 
void Round_R( struct Process Info[NumOfPro] ){

	printf("## 3.Round Robin scheduling ##\n");
	printf("---------------------------------------------------------------\n");
	printf("Sequence process is :");

	int at = 0;
	int RR_PAT[NumOfPro];
	int Qt =4;
	int TempAt = 0;
	int TempBt = 0;
	int FreeTime = 0;
			
	while(1){
		int count  = check_NPAT(Info,RR_PAT);				// Process are arrive

		int i  = 1;
		for(i; i<=count ;i++){
			FreeTime = executeRR(Info, RR_PAT[i], Qt, at);
			//printAInfo(Info, RR_PAT, count, 1);
			at+=Qt;
			at-=FreeTime;		
		}

		if(at >= 1000 || check_pre_stop(Info) ){
			break;	
		}
	}	

}

