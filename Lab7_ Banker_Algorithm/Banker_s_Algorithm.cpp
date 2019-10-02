// Banker's Algorithm 

#include <stdio.h> 
//#include "SetupProcess1.h"
//#include "SetupProcess2.h"
#include "SetupProcess3.h"

int main() { 
	
	int f[n], ans[n], ind = 0; 								// f : to save flag process state 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 											// set flag
	} 
	
	int need[n][m];
	for (i = 0; i < n; i++) { 								// i is process
		for (j = 0; j < m; j++) 							// m is resource
			need[i][j] = max[i][j] - alloc[i][j]; 			// set need 
	} 
	
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 
			
			
				int flag = 0; 								// Check need enough
				for (j = 0; j < m; j++) { 
					if (need[i][j] > avail[j]){ 			// check the process need resource more than available
						flag = 1; 							// set flag when resource not enough
						break; 
					} 
				} 
				
														
				if (flag == 0) {
					printf("\nAvailable drives = (%2d,%2d,%2d)",avail[0],avail[1],avail[2]);
					printf("\nFirst state allocate (%2d,%2d,%2d) drives to P%-2d",avail[0],avail[1],avail[2],i+1);				//**
					
					ans[ind++] = i; 					// save process complete each state
					for (y = 0; y < m; y++){
						avail[y] += alloc[i][y];		// increase resources A B C 
					} 
					
					f[i] = 1; 						   
					
					printf("\nP%-2d completes and releases (%2d,%2d,%2d) Available drives",i+1, avail[0],avail[1],avail[2]); 	//**					
					printf("\nNext state ...\n\n"); 
					start = 1;
					
				}else{
					//printf("\nAvailable drives = (%2d,%2d,%2d)",avail[0],avail[1],avail[2]);
					//printf("\nProcess may get deadlock = UNSAFE STATE");							//**
				} 
				
			}
		} 
	} 

	// Check process state
	int check_st = 0;
	for (i = 0; i < n; i++){						// to check stat process completed
	//	printf("\nF: %d",f[i]); 
		check_st += f[i];		
	}

	if(check_st == n){								// all process completed
		printf("\nSequences state are "); 
		for (i = 0; i < n - 1; i++){
			printf("P%d,", ans[i]+1); 
		}
		printf("P%d", ans[n - 1]+1); 
		printf("\n**ALL process run to completion = SAFE STATE");	
		
	}else if( check_st > 0){						// some process completed
		printf("\nNot enough for process needs remaining (");
		for (i = 0; i < n; i++){
			if(f[i] != 1){
				if( i == n-1 ){
					printf("P%d)", i+1); 
				}else{
					printf("P%d,", i+1);
				}
				 
			}
		} 	
		printf("\nProcess may get deadlock = UNSAFE STATE");
		
	}else{											// not any process completed
		printf("\nAvailable drives = (%2d,%2d,%2d)",avail[0],avail[1],avail[2]);
		printf("\nIf grant last drive to any process may get deadlock = UNSAFE STATE");
		printf("\n**ALL process don't run to completion");
	}

	//print table
	printf("\n\n===================================================");
	printf("\n%-10s %-10s %-10s %-10s %-10s %10s", "Process", "Alloc", "Max", "Need", "Avail", "State");
	printf("\n%-10s %-10s %-10s %-10s %-10s %10s", "", "A  B  C", "A  B  C", "A  B  C", "A  B  C", "");
	
	for(int i = 0 ; i < n ; i++){
		printf("\nP%-10d%-3d%-3d%-3d  %-3d%-3d%-3d  %-3d%-3d%-3d  %-10s",i+1, alloc[i][0], alloc[i][1], alloc[i][2],     max[i][0], max[i][1], max[i][2],    need[i][0], need[i][1], need[i][2], " ");
		if(f[i] == 1){
			//printf("%10d", ans[i]);
		}else{
			printf("%10s", "NULL");
		}
	}
	
	return (0); 

	// This code is contributed by Deep Baldha (CandyZack) 
} 

