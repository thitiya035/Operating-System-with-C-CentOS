void show_segment_table(){
	printf("\n\nShow Segment Process table\n");
	int i,j;
	for( i=0; i<Row; i++){
		for( j=0; j<Col; j++){
			printf("%10d", Segment_table[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void check_segment_space( int Segment,  int Logic_Addr){
	int find_seg = 0;
	for(int j = 0; j<Row; j++){									//loop all segment in table
		if(Segment == Segment_table[j][0]){						//check segment
			find_seg = 1;										//set 1 when found segment in the table
			printf("%-10d%-10d%-10d", Segment_table[j][0], Segment_table[j][1], Segment_table[j][2]);
			
			int End_Segment =  Segment_table[j][1] + Segment_table[j][2];		//cal end segment Lenght + base
			int Physical_Address = Segment_table[j][1]+ Logic_Addr;
			
			if(Physical_Address > End_Segment){								   //Physical >  End Segment
				printf("%-30s: -", "Incorrect Physical Address ");
			}else{
				printf("%-30s: %-10d", "Physical_Address ", Physical_Address);
			}
			
		}
	}
	
	if( find_seg == 0){
		printf("!!! Not found Segment in Segment Table\n");
	}
}

void Check_Logical_addr(){
	printf("%-20s%-10s%-20s%-10s%-30s\n\n","Logical Address","","Segment Table","","Physical Address");
	printf("%-10s%-10s","Segm", "Size");
	printf("%-10s","");
	printf("%-10s%-10s%-10s\n","Segm", "Base", "Lenght");
	
	for(int i=0; i<Seg; i++){		//loop all input data

		int page 	= 0;
		int offset 	= 0;

		printf("\nInsert segment number : ");
		scanf("%d", &page);
		
		printf("Insert offset : ");
		scanf("%d", &offset);

		printf("%-10d%-10d", page, offset);	//show input data
		printf("%-10s"," --->");
		check_segment_space(page, offset);   //show mapping segment
		printf("\n\n");
	}
}
