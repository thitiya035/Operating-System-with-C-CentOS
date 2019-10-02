
//--Define--//
#define MaxStack 20	// Set Max Stack

int stack[MaxStack]				;	// Set Max Stack
int x							;	// Temperature Variable
int SP 				= 0			;	// Initial SP = 0
char status 		= 'N'		;	// Initial Status = NORMAL
char ch							;	// KBD Read variable

void push(int x){
	//PUSH Function
	
	if(SP == MaxStack){	// Check Stack FULL?
		printf("!!!OVER FLOW!!!...\n");
		status = 'O';	// Set status = OVER FLOW
	}//End if
		else{
			SP = SP + 1 ;	// Increase SP
			stack[SP] = x ;	// Put data into Stack
		}//End else

}//End push function

int pop(){
	int x;
	if (SP != 0){ 	// Check Stack NOT EMPTY?
		x = stack[SP];	// Get data from Stack
		SP--;			// Decrease SP
		return(x);		// Return data
	}//End if 
	else{
		return 0;
		printf("\n!!!UNDER FLOW!!!...\n");
		status = 'U' ;	// Set STATUS = "UNDER FLOW"
	}//End if
	
}//End pop function

void ShowAllStack(){
	int i ;	// Counter variable
	printf("Status : %c\n", status);	// Display STATUS
	printf("SP : %d\n", SP);			// Display SP
	for( i = 1 ; i <= MaxStack ; i++ ){
		printf("%d:%d \n", i, stack[i]);	// Display
	}//Endfor
	printf("\n------------------------------------------------------\n");
	
}//End ShowAllStack function





