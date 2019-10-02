int LoadProcess(int &at){
	int Temp_PID = deleteCQ();
	Info[Temp_PID].IN = at;
	printf("\nat:%-2d: (P%d)%-16s:%6sOUT: %-5dREM: %-5dWAI: %-5d<< IN : %-3d%10s|", at, Temp_PID, "LOAD", " ", Info[Temp_PID].OUT, Info[Temp_PID].REMAIN, Info[Temp_PID].WAITING, Info[Temp_PID].IN, "" );
	
	// save log sequence
	Sequence[p_alg][p_pro] = Temp_PID;
	p_pro++;
	
	return Temp_PID;
	
}
