// variable
#define NProcess 5									// Set Number of process 
int Sequence[5][20];								// To save log waiting time process
// 1. sjf preemtive
// 2. sjf non-preemtive
// 3. round robin
// 4. priority
int p_alg = 1;										// To choose algorithm
int p_pro = 1;										// To keep current process that is executing


struct Process {
	int  PID;										// Process ID
	int  AT;             							// Arrival Time
	int  BT;             							// Burst Time
	int  PRI;										// To Keep priority each process

	int  REMAIN;									// check for terminate
	int  IN;										// To save time that the process start to use critical section  
	int  OUT;										// To save time that the process exit from critical section
	int  WAITING;									// To save wating time each process
	char PS;										// To save state process
};

struct Process Info[NProcess+1];
struct Process setTable( struct Process Info[NProcess] ){	// To set process table PID, Burst time, Arival time and priority process  
	int i;
		Info[1].PID = 1 ;	  Info[1].BT = 9;    Info[1].AT = 1 ;   Info[1].PRI = 3 ;
		Info[2].PID = 2 ;	  Info[2].BT = 3 ;   Info[2].AT = 1 ;   Info[2].PRI = 5 ;
		Info[3].PID = 3 ;	  Info[3].BT = 5 ;   Info[3].AT = 3 ;   Info[3].PRI = 1 ;
		Info[4].PID = 4 ;	  Info[4].BT = 4 ;   Info[4].AT = 4 ;   Info[4].PRI = 4 ;
		Info[5].PID = 5 ;	  Info[5].BT = 2 ;   Info[5].AT = 7 ;   Info[5].PRI = 2 ;

	for(i = 1 ; i <= NProcess ; i++ ){
		Info[i].REMAIN 		  = Info[i].BT;			// To set Remain time equal to waiting time
		Info[i].WAITING		  = 0;					// To set start waiting time at 0
		Info[i].OUT		 	  = Info[i].AT;			// To set Out time equal to Arrival time for easy to calculate waiting time
		Info[i].IN	 	   	  = 0;					// To set start in by 1
		Info[i].PS			  = 'A';				// To set start state by A
	}

	for( int i = 1 ; i <= 5 ; i++ ){
		for(int j = 1; j<= 10; j++){
			Sequence[i][j] = 0;						// To set start log waiting time equal 0
		}
	}
}



