// check all the process was terminate
int Check_Process_Terminate(){

	//*** check for terminate
	int check_break = 0;			
	for(int j = 1 ; j<= NProcess; j++ ){
		check_break += Info[j].REMAIN; 
	}
	
	if(check_break == 0 ){
		return 0;					// terminate all process turn 0
	}
	return 1;
}


