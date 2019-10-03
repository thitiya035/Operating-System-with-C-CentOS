// By Weerayut Buaphet
// https://github.com/weerayutbu

#define N 11

int Q[N];
int x, Qnumber = 0, F=0, R=0;
char status = 'N';
char ch;

int insertCQ( int y){
	if( R==F-1 || R== N-1 && F==1){
		printf("Over Flow \n");
		status = 'O';
		return -1;
		
	}else{
		if( R==N-1){
			R=1;
			
		} else {
			R++;
			if(F==0){
				F=1;
			}
		}	
			Qnumber++;
//			printf("Queue number : %d\n", Qnumber);
			Q[R] = y;
			status = 'N';					
	}
}

int deleteCQ(){
	int y;
	if(F == 0){
		printf("\n!!! Under Flow !!!");
		status = 'U';
		return -1;
	}else{
		y = Q[F];
		
		//
		Q[F] = 0;
		//
		
		if(F==R){
			F=0;
			R=0;
		}else{
			if(F==N-1){
				F=1;
			}else{
				F++;
			}
		}
		status = 'N';
//		printf("Delete P%d",y);
		return(y);
	}
}

int DataInQueue(){
	int y = 0;
	if( F!=0 && R!=0){
		if(F<=R){
			y=R-F+1;
		}else{
			y=(N-1)-F+1+R;
		}
	}
	return y;
}

void ShowAllQueue(){
	int i;
//	printf("N :%d\n",N-1);
//	printf("Status = %c : \n", status);
//	printf("Data waiting in queue = %d\n", DataInQueue());
//	printf("F = %d	<-->  R = %d\n",F,R);
	for( i = 1; i<N; i++){
	//	printf("%5d : [ %5d ] \n", i, Q[i]);
		printf("%-3d", Q[i]);
	}
	//printf("\n-------------------\n");
	//printf("\n");
}

