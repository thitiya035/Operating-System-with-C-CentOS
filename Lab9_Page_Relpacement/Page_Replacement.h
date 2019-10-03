// By Weerayut Buaphet
// https://github.com/weerayutbu

//int process[NPro] = { 2, 1, 2, 3, 7, 6, 2, 3, 4, 2, 1, 5, 6, 3, 2, 3, 6, 2, 1};
//int process[NPro] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

//FIFO
void FIFO_page_replacement(){
	printf("\n   ** FIFO PAGE REPLACEMENT **\n");
	printf("\n   \"*\" is Font\n   \":\" is Rear\n---------------\n");
	setQ();
	int Count_page_faults = 0;									//for count page faults
	for( int i=0; i<NPro; i++){

		int New_process = process[i];
		printf("\n %-2d%-5s%6s%3d%-6s",New_process, "-->",":     ", New_process, " :");
		
		int check_process_in_q = 0;								//for check the same process in q
		int NumberDataInQ 	   = DataInQueue();					//get number of data in queue

		//Check same process in q
		for(int c=0; c<NumberDataInQ; c++){
			int temp = deleteCQ();								// return -2 when underflow
			if(temp == New_process){							// check the same process in q
				check_process_in_q = 1;							// set flag for do not insert the process
			}
			insertCQ(temp);
		}
		
		//check overflow
		int status = 0;
		if( check_process_in_q != 1){
			status = insertCQ( process[i]);		//insert new process  -> return -1 when over
		}
		
		// Replace page
		if(status == -1){						//swap when over(-1)
			//printf("\n %-2d%-5s%6s%3s%-6s",process[i], "-->",": OVER", " ", " :");
			printf("\n %-2s%-5s%6s%3s%-6s","", "",": OVER", " ", " :");
			
			//Delete first data in q
			printf("\n %-2s%-5s%6s%3d%-6s","", "",": DELE", deleteCQ(), " :");
			printf("\n %-2s%-5s%6s%3d%-6s","", "",":     ", process[i], " :");
			
			//Insert new page
			insertCQ(process[i]);				//insert new process
		}
		ShowAllQueue();
		
		if(check_process_in_q != 1){			// not have same process in q
			Count_page_faults++;
			printf("%10s%d)\n", " : PF: (", Count_page_faults);
		}
	}
	
	printf("\n--FIFO-----------------\n   ");
	ShowAllQueue();
	printf("\n-----------------------\n");
	int NumberDataInQ 	   = DataInQueue();					// get number of data in q
	for(int c=0; c<NumberDataInQ; c++){
		int temp = deleteCQ();								// return -2 when underflow
		printf("%7d --> OUT\n", temp);
	}
	printf("\n   Page faults = %d", Count_page_faults);
	printf("\n-----------------------\n");
}


//OPTIMAL
int find_step_optimal(int temp, int pointer){
	int Step_process    = -1;							//To save step
	
	printf("%8s%4d : -> ","", temp);
	for(int j=pointer+1; j<NPro; j++){						// each data afther this process

		//Count step when found the process will comming.
		if(process[j] == temp && Step_process == -1){	// if have the same process
			printf("(%d)  ", process[j]);				// Show when found the process
			Step_process = j;							// Set step
	//			printf("<%d>"  ,Step_process);
		}else{
			printf(" %-4d", process[j]);				// Show when not found the process
		}
	}

	printf("%6s%-3d%5s"  ,"Step: ", Step_process, "");
	
	if( Step_process == -1 ){
		return NPro+1;
	}else{
		return Step_process;
	}
	
	return 0;
}

void OPTIMAL_page_replacement(){
	printf("\n   ** OPTIMAL PAGE REPLACEMENT **\n");
	printf("\n   \"*\" is Font\n   \":\" is Rear\n---------------\n");
	setQ();
	int Count_page_faults = 0;									//for count page faults
	for( int i=0; i<NPro; i++){

		int New_process = process[i];
		printf("\n %-2d%-5s%6s%3d%-6s",New_process, "-->",":     ", New_process, " :");
		
		int check_process_in_q = 0;								//for check the same process in q
		int NumberDataInQ 	   = DataInQueue();					//get number of data in queue

		//Check same process in q
		for(int c=0; c<NumberDataInQ; c++){
			int temp = deleteCQ();								// return -2 when underflow
			if(temp == New_process){							// check the same process in q
				check_process_in_q = 1;							// set flag for do not insert the process
			}
			insertCQ(temp);
		}
		
		//check overflow
		int status = 0;
		if( check_process_in_q != 1){
			status = insertCQ( process[i]);		//insert new process  -> return -1 when over
		}
		
		// Replace page
		if(status == -1){						//swap when over(-1)
			ShowAllQueue();
			printf("\n %-2s%-5s%6s%3s%-6s","", "",": OVER", " ", " :");
			printf("\n\n");
			
			
//-->    //Find optimal page replacement
			printf("%8s: Find OPTIMAL : Process[%d] = %d \n","", i, process[i]);
			
			int max_step =  0;										// pointer process
			int optimal  = -1;										// process number
			
			//Check all process in q
			int NumberDataInQ 	 = DataInQueue();				//get number of data in queue			
			for(int c=0; c<NumberDataInQ; c++){						//each data in q
			
				int temp = deleteCQ();								// return -2 when underflow				
				int step_p = find_step_optimal(temp, i);
				
				//find max setp
				if(max_step <= step_p ){
					max_step = step_p;
					optimal  = temp;
				}
				
				printf("%6s%-3d%5s"  ,"Max : ", max_step, "");
				printf("%6s%-3d%5s"  ,"Opti: ", optimal , "");

				insertCQ(temp);
				printf("\n");
			}
			printf("\n%8s:%-9s: P = %d",""," OPTIMAL", optimal);



		//Swapping process
			printf("\n %-2s%-5s%6s : (%d --> %d)","","",": SWAP   ", process[i], optimal);
			
			//Check all process in q
			NumberDataInQ 	   	= DataInQueue();					//get number of data in queue			
			for(int c=0; c<NumberDataInQ; c++){						//each data in q
			
				int temp = deleteCQ();								// return -2 when underflow				
				
				//find optimal data in q
				if( temp == optimal ){

					//Delete process
					printf("\n %-2s%-5s%6s%3d%-6s","", "",": DELE", temp   , " :");
					printf("\n %-2s%-5s%6s%3d%-6s","", "",": INSE", process[i], " :");
					insertCQ(process[i]);
					
				}else{
					insertCQ(temp);
				}
			}
//-->

		}
		
		ShowAllQueue();
		
		if(check_process_in_q != 1){			// not have same process in q
			Count_page_faults++;
			printf("%10s%d)", " : PF: (", Count_page_faults);
			//printf("\n");
//			printf("\n----------------------------------------------\n\n");
		}
		
	}
	
	printf("\n--OPTIMAL-----------------\n   ");
	ShowAllQueue();
	printf("\n-----------------------\n");
	int NumberDataInQ 	   = DataInQueue();					// get number of data in q
	for(int c=0; c<NumberDataInQ; c++){
		int temp = deleteCQ();								// return -2 when underflow
		printf("%7d --> OUT\n", temp);
	}
	printf("\n   Page faults = %d", Count_page_faults);
	printf("\n-----------------------\n");
}


//LRU
int find_step_LRU(int temp, int pointer, int back_stap){
	int Step_process    = -1;							//To save step
	
	printf("%8s%4d : -> ","", temp);
	
	int stop_pointer;
	if(pointer < back_stap ){
		stop_pointer = 0;									// stop at 0 
	}else{
		stop_pointer = pointer - back_stap + 1;				// stop at back_stap-1 step
	}
	
	for(int j = pointer-1; j >= stop_pointer; j--){						// each data afther this process
	
		//Count step when found the process will comming.
		if(process[j] == temp && Step_process == -1){	// if have the same process
			printf("(%d)  ", process[j]);				// Show when found the process
			Step_process = j;							// Set step
	//			printf("<%d>"  ,Step_process);
		}else{
			printf(" %-4d", process[j]);				// Show when not found the process
		}
	}

	Step_process = pointer - Step_process;
	printf("%6s%-3d%5s"  ,"Step: ", Step_process, "");
	
	
	return Step_process;
}

void LRU_page_replacement(){
	printf("\n   ** LRU PAGE REPLACEMENT **\n");
	printf("\n   \"*\" is Font\n   \":\" is Rear\n---------------\n");
	setQ();
	int Count_page_faults = 0;									//for count page faults
	for( int i=0; i<NPro; i++){

		int New_process = process[i];
		printf("\n %-2d%-5s%6s%3d%-6s",New_process, "-->",":     ", New_process, " :");
		
		int check_process_in_q = 0;								//for check the same process in q
		int NumberDataInQ 	   = DataInQueue();					//get number of data in queue

		//Check same process in q
		for(int c=0; c<NumberDataInQ; c++){
			int temp = deleteCQ();								// return -2 when underflow
			if(temp == New_process){							// check the same process in q
				check_process_in_q = 1;							// set flag for do not insert the process
			}
			insertCQ(temp);
		}
		
		//check overflow
		int status = 0;
		if( check_process_in_q != 1){
			status = insertCQ( process[i]);		//insert new process  -> return -1 when over
		}
		
		// Replace page
		if(status == -1){						//swap when over(-1)
			ShowAllQueue();
			printf("\n %-2s%-5s%6s%3s%-6s","", "",": OVER", " ", " :");
			printf("\n");
			
			
//-->    //Find optimal page replacement
			printf("%8s: Find LRU : Process[%d] = %d \n","", i, process[i]);
			
			int max_step =  0;										// pointer process
			int RULP	 = -1;										// process number
			
			//Check all process in q
			int NumberDataInQ 	 = DataInQueue();					//get number of data in queue			
			for(int c=0; c<NumberDataInQ; c++){						//each data in q
			
				int temp = deleteCQ();								// return -2 when underflow				
				int step_p = find_step_LRU(temp, i, 5);
				
				//find max setp
				if(max_step <= step_p ){
					max_step = step_p;
					RULP  	 = temp;
				}
				
				printf("%6s%-3d%5s"  ,"Max : ", max_step, "");
				insertCQ(temp);
				printf("\n");
			}

			printf("\n%8s:%-9s: P = %d",""," LRU", RULP);


		//Swapping process
			printf("\n %-2s%-5s%6s : (%d --> %d)","","",": SWAP   ", process[i], RULP);
			
			//Check all process in q
			NumberDataInQ 	   	= DataInQueue();				//get number of data in queue			
			for(int c=0; c<NumberDataInQ; c++){						//each data in q
			
				int temp = deleteCQ();								// return -2 when underflow				
				
				//find optimal data in q
				if( temp == RULP ){

					//Delete process
					printf("\n %-2s%-5s%6s%3d%-6s","", "",": DELE", temp   , " :");
					printf("\n %-2s%-5s%6s%3d%-6s","", "",": INSE", process[i], " :");
					insertCQ(process[i]);
					
				}else{
					insertCQ(temp);
				}
			}
//-->

		}
		
		ShowAllQueue();
		
		if(check_process_in_q != 1){			// not have same process in q
			Count_page_faults++;
			printf("%10s%d)", " : PF: (", Count_page_faults);
			//printf("\n");
//			printf("\n----------------------------------------------\n\n");
		}
		
	}
	
	printf("\n-- RLU -----------------\n   ");
	ShowAllQueue();
	printf("\n-----------------------\n");
	int NumberDataInQ 	   = DataInQueue();					// get number of data in q
	for(int c=0; c<NumberDataInQ; c++){
		int temp = deleteCQ();								// return -2 when underflow
		printf("%7d --> OUT\n", temp);
	}
	printf("\n   Page faults = %d", Count_page_faults);
	printf("\n-----------------------\n");

}

