// Int hex to string hex

#include <stdio.h> 
#include <stdio.h>
#include <string.h>

void Int2String_hex(){ 
	
	int  hex_int		= 0x0529;
	char hex_char[10] 	= "";
	
	// convert hex to string
	sprintf(hex_char, "%X", hex_int);					
	
	printf("\nHex:%-10X", hex_int);								// int
	printf("\nHex:%-10s", hex_char);							// string	

	// copy string to add bit
	char start_bit[10]  = "";
	strcat(start_bit, "String "); 								// add 0000 for start bit
	
	// add 2 think together
	strcat(start_bit, hex_char); 
	
	printf("\n(Int_Hex -> String_Hex) : %-10s", start_bit);		// Result	
} 

// driver code 
int main() 
{ 

	// Get the Hexadecimal string 
	Int2String_hex();

} 

