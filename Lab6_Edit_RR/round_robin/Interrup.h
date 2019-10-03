// By Weerayut Buaphet
// https://github.com/weerayutbu

int CheckInterrupSJF(int PID, int &at){
	printf("\nat:%-2d: (P%d)%-16s:"	, at, PID, "C-INTE");
	int Interrup = 0;
	int nowP_BT = Info[PID].REMAIN;
	int Nq =  DataInQueue();
	
	int PIDq = deleteCQ();
	int PIDq_Remain = Info[PIDq].REMAIN;

	if(nowP_BT > PIDq_Remain){							//insertion when new process Priority less than P in Q
		Interrup = 1;
		printf("\nat:%-2d: (P%d)%-16s:BY(%d)"	, at, PID, "INTE", PIDq);
	}
	
	Push_SJF(PIDq, at);
	
	return Interrup;
}

int CheckInterrupPRIO(int PID, int &at){
	printf("\nat:%-2d: (P%d)%-16s:"	, at, PID, "C-INTE");
	int Interrup = 0;
	int nowP_PRIO = Info[PID].PRI;
	int Nq =  DataInQueue();
	
	int PIDq = deleteCQ();
	int PIDq_PRIO = Info[PIDq].PRI;

	if(nowP_PRIO > PIDq_PRIO){							//insertion when new process Priority less than P in Q
		Interrup = 1;
		printf("\nat:%-2d: (P%d)%-16s:BY(%d)"	, at, PID, "INTE", PIDq);
	}
	
	Push_PRIO(PIDq, at);
	return Interrup;
}
