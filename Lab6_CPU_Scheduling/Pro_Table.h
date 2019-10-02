#define NumOfPro 5						// Set Number of process 

struct Process {
	int PID;							// Process ID
	int BT;             				// Burst Time
	int AT;             				// Arrival Time
	int PRI;             				// Prioity
	int PS;								// Process Status
	int PC;								// Process Count
	int WT;								// Wait time
	int TUT;							// Turnaround time
	int OutP;							// Out State execute
};

struct Process setTable( struct Process Info[NumOfPro] ){
		//Process Name		  Burst Time	   	 Arrival Time		Prioity
		Info[1].PID = 1 ;	  Info[1].BT = 9;    Info[1].AT = 1 ;   Info[1].PRI = 3 ;
		Info[2].PID = 2 ;	  Info[2].BT = 3 ;   Info[2].AT = 1 ;   Info[2].PRI = 5 ;
		Info[3].PID = 3 ;	  Info[3].BT = 5 ;   Info[3].AT = 3 ;   Info[3].PRI = 1 ;
		Info[4].PID = 4 ;	  Info[4].BT = 4 ;   Info[4].AT = 4 ;   Info[4].PRI = 4 ;
		Info[5].PID = 5 ;	  Info[5].BT = 2 ;   Info[5].AT = 7 ;   Info[5].PRI = 2 ;
		
	int i ;
	for(i = 1 ; i <= NumOfPro ; i++ ){
		Info[i].PS  = 1 ;
		Info[i].PC  = Info[i].BT;
		Info[i].WT  = 0;
		Info[i].TUT = 0;
		Info[i].OutP = 0;
	}
}



/*
		//Process Name		  Burst Time	   	 Arrival Time		Prioity

*/
