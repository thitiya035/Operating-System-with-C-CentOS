// P0, P1, P2, P3, P4 are the Process names here 

int i, j, k, start = 0; 
int n = 4; // Number of processes 
int m = 3; // Number of resources 
int alloc[5][3] = { { 1, 0, 1 },   	// P0 // Allocation Matrix 
					{ 4, 5, 2 },   	// P1 
					{ 5, 3, 5 },   	// P2 
					{ 0, 6, 3 },   	// P3 
					{ 0, 0, 2 } }; 	// P4 
	
int max[5][3] = { { 4, 0, 1 },   	// P0 // MAX Matrix 
				  { 6, 7, 3 },   	// P1 
				  { 8, 3, 5 },   	// P2 
				  { 7, 6, 5 },   	// P3 
				  { 4, 3, 3 } }; 	// P4 

int avail[3] = { 2, 2, 2 }; 	   // Available Resources 

