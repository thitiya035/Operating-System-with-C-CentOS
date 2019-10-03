// By Weerayut Buaphet
// https://github.com/weerayutbu

// P0, P1, P2, P3, P4 are the Process names here 

int i, j, k, start = 0; 
int n = 4; // Number of processes 
int m = 3; // Number of resources 
int alloc[5][3] = { { 8, 5, 3 },   	// P0 // Allocation Matrix 
					{ 1, 3, 5 },   	// P1 
					{ 1, 3, 0 },   	// P2 
					{ 1, 3, 0 },   	// P3 
					{ 0, 0, 0 } }; 	// P4 
	
int max[5][3] = { {10,  9, 5 },   	// P0 // MAX Matrix 
				  {12,  7, 7 },   	// P1 
				  { 3,  6, 9 },   	// P2 
				  { 8, 13, 5 },   	// P3 
				  { 0,  0, 0 } }; 	// P4 

int avail[3] = { 2, 4, 2 }; 	   // Available Resources 

