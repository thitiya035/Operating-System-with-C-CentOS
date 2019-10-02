// lab 7-1
#define m  1							// number of pages  in logical memory
#define n  2							// page and address in logical memory
int LogicalAddr[m][n] = {
				{0x00,  0x00},
//				{0x01,  0x25},
//				{0x02,  0x43},
//				{0x03,  0x7A},
//				{0x05,  0x50},
//				{0x00,  0x00},
//				{0x00,  0x00},
//				{0x00,  0x00},
//				{0x00,  0x00},
//				{0x00,  0x00},
//				{0x00,  0x00}
			};

#define M  6	 					// number of pages  in physical memory
#define N  2						// page and address in physical memory
int Process_table[M][N]={
						{0x01,  0x0529},
						{0x02,  0x0523},
						{0x03,  0x0124},
						{0x04,  0x0D6B},
						{0x05,  0x076C},
						{0x06,  0x0F67},
//						{0x00,  0x0000},
//						{0x00,  0x0000},
//						{0x00,  0x0000},
//						{0x00,  0x0000}
					};


//lab7-2
#define Row   5	 					// number of pages  in physical memory
#define Col   3						// page and address in physical memory
int Segment_table[Row][Col]={
								{0,     219,    600},
								{1,     2300,   14},
								{2,     90,     100},
								{3,     1327,   580},
								{4,     1952,   96},
//								{0,     0,      0},
//								{0,     0,      0},
//								{0,     0,      0},
//								{0,     0,      0},
//								{0,     0,      0}
							};

#define Seg      5	 					// number of pages  in physical memory
#define Length   2						// page and address in physical memory
int Insert_data[Seg][Length]={
								{ 0,    430 },
								{ 1,    10  },
								{ 2,    500 },
								{ 3,    400 },
								{ 41,    112 },
//								{ 0,    0   },
//								{ 0,    0   },
//								{ 0,    0   },
//								{ 0,    0   },
//								{ 0,    0   }
							};

