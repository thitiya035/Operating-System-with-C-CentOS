// By Weerayut Buaphet
// https://github.com/weerayutbu

#include<stdio.h>
#include<conio.h>
#include <stdio.h>
#include <string.h>
#include "library/hex2binary.h"
#include "data.h"
#include "physical_addr_1.h"
#include "physical_addr_2.h"

int main()
{

	//lab8-1
	printf("\n\n-- Lab8.1 -- \n");
//	show_logical_table();			// show data in logical table
//	show_Process_page_table();		// show data in show_Process page table
//	PagingLogi2Physic();			// Calculate physical address


	
	//lab8-2
	printf("\n\n-- Lab8.2 -- ");
	show_segment_table();			// show segment table
	Check_Logical_addr();			// check logical and mapping into physical address

	return 0;
}
