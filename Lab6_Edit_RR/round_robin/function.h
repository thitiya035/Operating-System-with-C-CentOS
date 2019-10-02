void show_algor( int pro_alg);
void choose_head_menu();
float average_t(struct Process Info[NProcess]);
void printall(struct Process Info[NProcess]);
void showQ(struct Process Info[NProcess]);
void swapQ(struct Process Info[NProcess]);

void swapQ(struct Process Info[NProcess]){
	int Temp;									// keep min PID  
	//showQ(Info);
	int i = 1;
	for( i; i <= N ; i++){
		if( Info[Q[F]].REMAIN > Info[Q[i]].REMAIN && Q[i] != 0){				// (new min)  X.bt > bt in q
			Temp  =  Q[i];		//Min BT's PID 
			Q[i]  =  Q[F];
			Q[F]  =  Temp;
		}
			//printf("BT-PID:%d|%d  ",BT_PID,Tpro);
	}
	//showQ(Info);
	//printf("\n\n");
}

void showQ(struct Process Info[NProcess]){
	int temp_st_q = Q[F];
	printf("FIRST QUEUE : PID%d\n", temp_st_q);
	
	int i = 1;
	for( i ; i<N ; i++){
		printf("PID%-5d", Q[i]);
	}
	
	printf("\n");
	
	for( i = 1; i<N; i++){
		printf("   %-5d", Info[Q[i]].BT);
	}
}

//printall(Info);
void printall(struct Process Info[NProcess]){
	printf("\n\n   %-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n","PROC", "BT", "AT", "PRI", "EXEC", "REMAIN", "IN", "OUT", "WAIT", "PS"  );
	int i;
	for( i = 1 ; i <= NProcess ; i++){
			printf("   %-10d%-10d%-10d%-10d%-10d%-10d%-10d%-10d%-10d : %-15s\n",Info[i].PID , Info[i].BT , Info[i].AT , Info[i].PRI, Info[i].EXT, Info[i].REMAIN, Info[i].IN, Info[i].OUT, Info[i].WAITING), Info[i].PS;
	}
	printf("\n");
}

float average_t(struct Process Info[NProcess]){
	float sum = 0;
	 int i = 1;
	for(i ; i <= NProcess ; i++){
		sum += Info[i].WAITING;
	}
	
	return sum/NProcess;
}

void choose_head_menu(){
	printf(" Please press number\n");
	printf("===================================\n");
	printf(" 1.Non preemptive SJF scheduling.\n");
	printf(" 2.Preemptive SJF scheduling.\n");
	printf(" 3.Round Robin scheduling.\n");
	printf(" 4.Priority scheduling.\n");
	printf("------------------------------------------------\n\n");
}

void show_algor( int pro_alg){ 
	//printf("\n\n");
	//printall(Info);
	//ShowAllQueue();
	printf("\n------------------------------------------------------------------------------------------------------------\n");	
	printf("\n# MR.WEERAYUT BUAPHET  ID:59543206019-1 Sec.01");
	printf("\n# MS.THITIYA  MANOWANG ID:59543206035-7 Sec.01");
	printf("\n\n# OUTPUT LAB 6 CPU Scheduling");
	
	printf("\n\n");
	switch(p_alg){
		case 1: printf("## 1. Non Preemtive SJF Scheduling. ##"); break;
		case 2: printf("## 2. Preemtive SJF Scheduling. ##");	  break;
		case 3: printf("## 3. Round Robin Sheduling. ##");        break;
		case 4: printf("## 4. Priority Scheduling. ##");          break;					
	}
	
	//show log process
	printf("\n------------------------------------------------------------------------------------------------------------");
	printf("\nSequence process is :");

	for(int j = 1; j<= 20; j++){
		if(Sequence[pro_alg][j] > 0){
			printf("P%-2d-> ", Sequence[pro_alg][j]);
		}
	}

	//wait time
	printf("\n\nWait time of process ( millisecond )\n\n");

	int i;
	for( i = 1 ; i <= NProcess ; i++){
		printf("|P%-14d",i);
	}
	printf("\n\n");	
	
	for( i = 1 ; i <= NProcess ; i++){
		printf("|%-15d",Info[i].WAITING);
	}
	printf("\n\n");
	
	
	printf("Average time is : %.2f ms\n\n", average_t(Info));
	printf("Turnaround time\n\n", average_t(Info));
	
	for( i = 1 ; i <= NProcess ; i++){
		printf("P%-2d = %-.2f ms |",i ,Info[i].WAITING*(1.0)+Info[i].BT*(1.0));
	}
	
	printf("\n------------------------------------------------------------------------------------------------------------");
	for(int i = 0 ; i < 5; i++){
		printf("\n");
	}
}
