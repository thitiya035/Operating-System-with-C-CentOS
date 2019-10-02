
void Round_R(struct Process Info[NProcess]){
	int Quantum_time = 4;
	int max = 0;								// max time the process will execute
	int m;
	int Temp_PID = 0;							// to keep process in ex
	int Temp_QT = 0;							// to keep time's process in ex
	
	for(m = 1; m <= NProcess; m++){
		max += Info[m].BT;
	}
	
	//printf("Totol Burst Time %d\n",max);
	
	int at ;
	for(at = 0; at <= max ; at ){
		
		//printf("at:%-5d : P%-5d : ",at, Temp_PID);		
		for(int j = 1 ; j<= NProcess; j++ ){
			
			// push when process arrived
			if(Info[j].AT == at){								//printf("at( %d )Insert: %d\n", at, Info[j].PID);
				insertCQ(Info[j].PID);							// insert when new process is arriv
			}	
		}	
		
		// pop process when have some process in queue and the process that is executing have quantum time == 0 
		if(Temp_QT == 0 && DataInQueue()>=1 ){
			Temp_PID = deleteCQ();
			Info[Temp_PID].IN = at;								// set start time
			Temp_QT	 = Quantum_time;							// fix time for execute
		}
		
		// Executing when the process have time for execute And the job does not finish yet.
		if(Temp_QT > 0 && Info[Temp_PID].REMAIN >= 1 ){			// have Q time and job doesn't finish 
			 Info[Temp_PID].REMAIN--;
			 Temp_QT--;
			 
			 if( Info[Temp_PID].REMAIN == 0){					// the job done
			 	Temp_QT = 0;									//printf("** Terminate %2d **\n", Temp_PID);
			 }
			 
			 if(Temp_QT == 0 && Info[Temp_PID].REMAIN >= 1){	// if time out but not terminate push the process into queue 	//printf("at( %d )Insert: %d\n", i, Temp_PID);
			 	insertCQ(Temp_PID);								// insert when job doesn't finish
			 }
		}
		
		// increate at
		at++;
		
		if( (Temp_QT == 0 || Info[Temp_PID].REMAIN == 0) and Temp_PID > 0 ){		//Quantum_time == 0 or Process was terminated
			
			//Save last out at previous
			int Temp_OUT = 0;
			Temp_OUT = Info[Temp_PID].OUT;
			
			//exit from execute
			Info[Temp_PID].OUT = at;
//			printf("\nPID:|P%-3d|(in: %-3d) P%d (out: %-3d)", Temp_PID,Info[Temp_PID].IN, Temp_PID, Info[Temp_PID].OUT);
			printf("   P%-3d >", Temp_PID);
				
			// Calculation waiting time
			if(Info[Temp_PID].PS == 'I'){		//start
				Info[Temp_PID].WAITING = Info[Temp_PID].IN - Info[Temp_PID].AT;
//				printf("%10s","---start--");
				Info[Temp_PID].PS = 'N';
			}else{
//				printf("%10s"," ");
				Info[Temp_PID].WAITING += Info[Temp_PID].IN - Temp_OUT;
			}
//			printf(" : waiting : %-3d", Info[Temp_PID].WAITING );

			//check for terminate
			int check_break = 0;			
			for(int j = 1 ; j<= NProcess; j++ ){
				check_break += Info[j].REMAIN; 
			}
			if(check_break == 0 ){
				break;
			}	 
		}
		
		// check remain time
		if(Check_Termi_All() != 0 and max == 0){
			max+=1;
		}
	}
	
	//ShowAllQueue();
}

