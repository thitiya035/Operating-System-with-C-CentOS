// By Weerayut Buaphet
// https://github.com/weerayutbu

// variable
#define NProcess 5						// Set Number of process 
int Sequence[5][20];
// 1. sjf preemtive
// 2. sjf non-preemtive
// 3. round robin
// 4. priority
int p_alg = 1;
int p_pro = 1;


struct Process {
	int PID;							// Process ID
	int AT;             				// Arrival Time
	int BT;             				// Burst Time
	int  PRI;

	int  EXT;
	int  REMAIN;							// check for terminate
	int  IN;
	int  OUT;
	int  WAITING;
	char PS;
};

struct Process Info[NProcess+1];
struct Process setTable( struct Process Info[NProcess] ){
	int i;
	
		//Process Name		  Burst Time	   	 Arrival Time		Prioity
/*		Info[1].PID = 1 ;	  Info[1].BT = 53 ;   Info[1].AT = 0 ;   Info[1].PRI = 3 ;
		Info[2].PID = 2 ;	  Info[2].BT = 17 ;   Info[2].AT = 0 ;   Info[2].PRI = 5 ;
		Info[3].PID = 3 ;	  Info[3].BT = 68 ;   Info[3].AT = 0 ;   Info[3].PRI = 1 ;
		Info[4].PID = 4 ;	  Info[4].BT = 24 ;   Info[4].AT = 0 ;   Info[4].PRI = 1 ;	
*/
		Info[1].PID = 1 ;	  Info[1].BT = 9;    Info[1].AT = 1 ;   Info[1].PRI = 3 ;
		Info[2].PID = 2 ;	  Info[2].BT = 3 ;   Info[2].AT = 1 ;   Info[2].PRI = 5 ;
		Info[3].PID = 3 ;	  Info[3].BT = 5 ;   Info[3].AT = 3 ;   Info[3].PRI = 1 ;
		Info[4].PID = 4 ;	  Info[4].BT = 4 ;   Info[4].AT = 4 ;   Info[4].PRI = 4 ;
		Info[5].PID = 5 ;	  Info[5].BT = 2 ;   Info[5].AT = 7 ;   Info[5].PRI = 2 ;


/*		Info[1].PID = 1 ;	  Info[1].BT = 7;    Info[1].AT = 1 ;   Info[1].PRI = 3 ;
		Info[2].PID = 2 ;	  Info[2].BT = 3 ;   Info[2].AT = 2 ;   Info[2].PRI = 5 ;
		Info[3].PID = 3 ;	  Info[3].BT = 1 ;   Info[3].AT = 8 ;   Info[3].PRI = 1 ;
		Info[4].PID = 4 ;	  Info[4].BT = 4 ;   Info[4].AT = 14 ;   Info[4].PRI = 4 ;
		Info[5].PID = 5 ;	  Info[5].BT = 1 ;   Info[5].AT = 14 ;   Info[5].PRI = 2 ;
*/			
	for(i = 1 ; i <= NProcess ; i++ ){
		Info[i].REMAIN 		  = Info[i].BT;
		Info[i].WAITING		  = 0;
		Info[i].OUT		 	  = Info[i].AT;
		Info[i].IN	 	   	  = 0;
		Info[i].PS			  = 'A';
	}

	for( int i = 1 ; i <= 5 ; i++ ){
		for(int j = 1; j<= 10; j++){
			Sequence[i][j] = 0;
		}
	}
}



