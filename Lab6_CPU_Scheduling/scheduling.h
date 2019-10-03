// By Weerayut Buaphet
// https://github.com/weerayutbu

int TempPExecut = 0;


int check_pre_stop(struct Process Info[NumOfPro]){
	int sum = 0;
	int i;
	for(i = 1; i <=NumOfPro; i++ ){
		if(Info[i].PS > 0){					
			return 0;					//Do not break
		}
	}
	
//	printf("All PC is zero");
	return 1;
}


int check_NPAT(struct Process Info[NumOfPro], int ProAT[NumOfPro]){
	int i = 1;
	int count = 0;
	
	for( i; i<= NumOfPro; i++){
		if(Info[i].PS == 1){				//check process terminate
			count += 1;
			ProAT[count] = Info[i].PID;
		}
	}
	return count;
}

int check_AT(struct Process Info[NumOfPro], int ProAT[NumOfPro],int at){
	int i = 1;
	int count = 0;
	for( i; i<= NumOfPro; i++){
		if((Info[i].AT <= at) && (Info[i].PS == 1)){
			count += 1;
			ProAT[count] = Info[i].PID;
		}
	}
	return count;
}

int check_minBT(struct Process Info[NumOfPro],int ProAT[NumOfPro] ,int count){
	int i	 	= 1;
	int Tpro 	= 0;
	int BT_PID 	= 0;
	
	if(count <= 0 ){
		return 0;
	} 
	
	
	Tpro = Info[ProAT[i]].BT;
	BT_PID = ProAT[i];
	i++;


	for( i; i <= count ; i++){
		if( Tpro > Info[ProAT[i]].BT){
			Tpro = Info[ProAT[i]].BT;
			BT_PID = ProAT[i];
		}
			//printf("BT-PID:%d|%d  ",BT_PID,Tpro);
	}
	return BT_PID;
}


int execute(struct Process Info[NumOfPro], int ex_pid, char algor[10], int at){
	
	if( TempPExecut != ex_pid && ex_pid > 0 ){
		printf("P%d->",ex_pid);							//When change process to execution				
		TempPExecut = ex_pid;
	}
	
	if(algor == "non_pre_SJF" || algor == "non_pri"){
		
		if(Info[ex_pid].WT == 0){					// check wait
			Info[ex_pid].WT = at;		
		}

		//-------process is executing here -----------//
		Info[ex_pid].PS = 0;								//Terminate
		return Info[ex_pid].BT;
		
	}
}


