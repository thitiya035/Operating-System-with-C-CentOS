
void show_logical_table(){
	
printf("%10s\n page\n","Logical Address");
	int i,j;
	for(i=0;i<m;i++){
		for(j = 0 ; j < n; j++){
//				printf("Decimal: %d, Hex: %X    ",LogicalAddr[i][j],LogicalAddr[i][j]);
			if(j == 0 ){
				printf("%5d : ",LogicalAddr[i][j]);
			}else{
				printf("%5X H",LogicalAddr[i][j]);
				printf("\n");
			}
		}
	}
	printf("\n");
}

void show_Process_page_table(){
	int I,J;
	printf("\nProcess page table\n page\n");
	for(I=0; I<M; I++){
		for(J=0; J<N; J++){
//			printf("Decimal: %d, Hex: %X    ",PhysicalAddr[I][J], PhysicalAddr[I][J]);
			if(J == 0 ){
				printf("%5d : ",Process_table[I][J]);
			}else{
//					printf("%5X H",PhysicalAddr[I][J]);
				HexToBin(Process_table[I][J], 4); 					// Convert HexaDecimal to Binary (4 bit)
				printf("B\n");
			}
		}
	}
	printf("\n");
}

void PagingLogi2Physic(){
	
	printf("\n\n -- Physical Address -- \n%5s%10s\n","Page","");
	
	int page 	= 0;
	int offset 	= 0;
	
	while(1){
		printf("\nInsert Page number : ");
		scanf("%x", &page);
		
		printf("Insert offset : ");
		scanf("%x", &offset);	

		int j;
		for(j=0; j<M; j++){								// for check page in table
			if((page == Process_table[j][0])){
				
//				printf("%5x %5x H _:_ ",Process_table[j][1], LogicalAddr[i][1]);
				
				HexToBin(Process_table[j][1], 4);		// convert Process_table hex to binary 
				printf(" ");
				HexToBin(offset, 2);					// convert LogicalAddr hex to binary

//				printf("= %x",Process_table[j][1]+LogicalAddr[i][1]);
//				printf(" = ");
//				HexToBin(Process_table[j][1]+LogicalAddr[0][1], 4);	// add process_table by logical turn to physical address
				printf("B\n");
			}		
		}
	}

}
