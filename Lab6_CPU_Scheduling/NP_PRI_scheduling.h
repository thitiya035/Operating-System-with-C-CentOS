// By Weerayut Buaphet
// https://github.com/weerayutbu

//------------- Priority scheduling. -------------------------------------

int check_minPRI(struct Process Info[NumOfPro],int ProAT[NumOfPro] ,int count){
	//printf("> check_minBT:  count : %d\n", count);
	int i	 		= 1;
	int Tpro 		= 0;
	int PRI_PID 	= 0;
	
	if(count <= 0 ){
		return 0;
	}else{
		Tpro = Info[ProAT[i]].PRI;
		PRI_PID = ProAT[i];
		i++;
	}
	
	// check min
	for( i; i <= count ; i++){
		if( Tpro > Info[ProAT[i]].PRI){
			Tpro = Info[ProAT[i]].PRI;
			PRI_PID = ProAT[i];
		}
	}
	
	//printf(" - PID:%d   BT:%d  PRI:%d \n\n",PRI_PID, Tpro, Info[PRI_PID].PRI);
	return PRI_PID;
}

void Priority_Non( struct Process Info[NumOfPro] ){
	
	printf("## 4.Priority scheduling ##\n");
	printf("---------------------------------------------------------------\n");
	printf("Sequence process is :");

	int at = 0;
	int PRI_N_AT[NumOfPro];
		
	int TempAt = 0;
	int TempBt = 0;
	int i = 0;

	for( i ; i <= NumOfPro ; i++ ){
//		printf("AT:%d\n",at);
		int count 	= check_NPAT(Info,PRI_N_AT);			// Process are arrive	
		int Ex_PID 	= check_minPRI(Info,PRI_N_AT, count);		// Process is going work by minBT
		int Timeuse = execute(Info, Ex_PID, "non_pre_SJF", at);
		
		if(Timeuse == 0){
			at+=0;
		}else{
			at+=Timeuse;
		}
	}	
	
}
