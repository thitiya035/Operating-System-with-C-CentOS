// C program to convert 
// Hexadecimal number to Binary 
// function to convert Hexadecimal to Binary Number 

void HexToBin(int someInt, int n){ 
	char hexdec[20];							// To save string of hexdec
	char String_Binary[100] = "";					// To save out put of Binary
	
	sprintf(hexdec, "%X", someInt);				// convert hex to string
//	printf("\nHex:%-10s  Binary: ",hexdec);
	
	long int i = 0; 
	
	while (hexdec[i]) { 
//		printf("\n"); 
		switch (hexdec[i]) { 
		case '0': 
			strcat(String_Binary,"0000 "); 
			break; 
		case '1': 
			strcat(String_Binary,"0001 "); 
			break; 
		case '2': 
			strcat(String_Binary,"0010 "); 
			break; 
		case '3': 
			strcat(String_Binary,"0011 "); 
			break; 
		case '4': 
			strcat(String_Binary,"0100 "); 
			break; 
		case '5': 
			strcat(String_Binary,"0101 "); 
			break; 
		case '6': 
			strcat(String_Binary,"0110 "); 
			break; 
		case '7': 
			strcat(String_Binary,"0111 "); 
			break; 
		case '8': 
			strcat(String_Binary,"1000 "); 
			break; 
		case '9': 
			strcat(String_Binary,"1001 "); 
			break; 
		case 'A': 
		case 'a': 
			strcat(String_Binary,"1010 "); 
			break; 
		case 'B': 
		case 'b': 
			strcat(String_Binary,"1011 "); 
			break; 
		case 'C': 
		case 'c': 
			strcat(String_Binary,"1100 "); 
			break; 
		case 'D': 
		case 'd': 
			strcat(String_Binary,"1101 "); 
			break; 
		case 'E': 
		case 'e': 
			strcat(String_Binary,"1110 "); 
			break; 
		case 'F': 
		case 'f': 
			strcat(String_Binary,"1111 "); 
			break; 
		default: 
			printf("\nInvalid hexadecimal digit %c", 
				hexdec[i]);
		} 
		printf("");
		i++; 
	} 
	
	char Binary[100] = "";				//To save binary string after add bit 
	if(i < n ){
		strcat(Binary, "0000 ");		//To add bit 0 to Binary
		i++;
	}
	
	strcat(Binary, String_Binary);		//to add bit 0 and binary bit togeter
	printf("%s", Binary);
} 

