#include <stdio.h>
 
int main() { 
	// create a FILE typed pointer
	FILE *file_pointer; 
	
	char Account_name[100] = "./../file/log.txt"; 
	
	// open the file "name_of_file.txt" for writing
	file_pointer = fopen( Account_name, "w"); 
 
	// Write to the file
	char Log[200] = "TRANS_ID:023,ID:,TIME:,STAT:,NAME:,SURN:,PASS:,ACT:,MONEY:,AMOU:,TYPE:,PHONE:,BY:,\n";
	fprintf(file_pointer, Log);
	
	// Close the file
	fclose(file_pointer); 
	return 0;
}
