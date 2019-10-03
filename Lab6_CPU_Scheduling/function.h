// By Weerayut Buaphet
// https://github.com/weerayutbu

float average_t(struct Process Info[NumOfPro]){
	float sum = 0;
	 int i = 1;
	for(i ; i <= NumOfPro ; i++){
		sum += Info[i].WT;
	}
	
	return sum/NumOfPro;
}

void Wait_time_process(struct Process Info[NumOfPro]){
	printf("\n\nWait time of process ( millisecond )\n\n");

	int i;
	for( i = 1 ; i <= NumOfPro ; i++){
		printf("|P%-14d",i);
	}
	printf("\n\n");	
	
	for( i = 1 ; i <= NumOfPro ; i++){
		printf("|%-15d",Info[i].WT);
	}
	printf("\n\n");
	
	
	printf("Average time is : %.2f ms\n\n", average_t(Info));
	printf("Turnaround time\n\n", average_t(Info));
	
	for( i = 1 ; i <= NumOfPro ; i++){
		printf("P%-2d = %-.2f ms |",i ,Info[i].WT*(1.0)+Info[i].BT*(1.0));
	}
}


char choose_head_menu(){
	printf(" Please press number\n");
	printf("===================================\n");
	printf(" 1.Non preemptive SJF scheduling.\n");
	printf(" 2.Preemptive SJF scheduling.\n");
	printf(" 3.Round Robin scheduling.\n");
	printf(" 4.Priority scheduling.\n");
	printf(" 5.Show Table Process.\n");
	char ch = getch();
	system("cls");
	
	printf("# Mr.Weerayut Buaphet ID: 59543206019-1 Sec.01        #\n\n");
	printf("# OUTPUT LAB 5 CPU Scheduling                         #\n\n");
	return ch;
}



void printAInfo(struct Process Info[NumOfPro],int Arr[NumOfPro] ,int pointer, int C){
	int i = 1;
	if( C == 1){
		printf("\n  %-15s%-15s%-15s%-15s%-15s%-15s%-15s\n","Process", "BurstTime", "Arrivaal_Time", "Priority", "PC", "OUT", "Wait_Time"  );
		for(i; i <= pointer ; i++ ){
			printf("  %-15d%-15d%-15d%-15d%-15d%-15d%-15d\n",Info[Arr[i]].PID , Info[Arr[i]].BT , Info[Arr[i]].AT , Info[Arr[i]].PRI, Info[Arr[i]].PC, Info[Arr[i]].OutP, Info[Arr[i]].WT );
		}		
	}else if(C == 2){
		i = 1;
		for(i; i <= pointer ; i++ ){
			printf("  %d%->",Info[Arr[i]].PID);
		}	
	}else{
		printf("\n  %-15s%-15s%-15s%-15s%-15s\n","Process", "BurstTime", "Arrivaal_Time", "Priority","Wait_Time"  );
		for(i; i <= pointer ; i++ ){
			printf("  %-15d%-15d%-15d%-15d%-15d%-15d%-15d\n",Info[Arr[i]].PID , Info[Arr[i]].BT , Info[Arr[i]].AT , Info[Arr[i]].PRI, Info[Arr[i]].PC, Info[Arr[i]].OutP, Info[Arr[i]].WT );
		}	
		
		printf("\n\n");
		
		i = 1;
		for(i; i <= pointer ; i++ ){
			printf("  %d%->",Info[Arr[i]].PID);
		}	
	}
	printf("\n\n");
}


void printAllInfo(struct Process Info[NumOfPro]){
		printf("\n  %-15s%-15s%-15s%-15s%-15s\n","Process", "BurstTime", "Arrivaal_Time", "Priority","Wait_Time"  );
	int i;
	for( i = 1 ; i <= NumOfPro ; i++){
			printf("  %-15d%-15d%-15d%-15d%-15d\n",Info[i].PID , Info[i].BT , Info[i].AT , Info[i].PRI, Info[i].WT );
	}
	printf("\n");
}

