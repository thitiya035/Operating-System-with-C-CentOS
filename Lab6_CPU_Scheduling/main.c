#include<stdio.h>
#include<conio.h>
#include<string.h>

#include "Pro_Table.h"				//stuctur process, setTable
#include "function.h"				//menu_selection, choose_head_menu, printInfo, printAllInfo
#include "scheduling.h"				//SJF_Non, SJF_Pre, Round_R, Priority_Non
#include "P_SJF_scheduling.h"
#include "NP_SJF_scheduling.h"
#include "NP_RR_scheduling.h"
#include "NP_PRI_scheduling.h"

int main(){
	struct Process Info[NumOfPro] ;
	setTable(Info);
	switch (choose_head_menu()) {
		case '1' :	SJF_Non( Info );
					break;
					
		case '2' :	SJF_Pre( Info );
					break;
					
		case '3' :	Round_R( Info );
					break;	
					
		case '4' :	Priority_Non( Info ) ;
					break;
		
		case '5' : 	printAllInfo( Info );
					break;
	}
	
	//printf("\n\n");
	//printAllInfo(Info);
	Wait_time_process(Info);
	exit(0);
}






