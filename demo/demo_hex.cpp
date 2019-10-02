#include <stdio.h>

int print_hex() {
	unsigned char a=0x64;
	int b=0xFAFA;
	
	printf("value of a: %X [%x]\n",a,a);
	printf("value of b: %X [%x]\n",b,b);
	return 0;
}

int Reading_hex() {
	unsigned char a;
	int b;
	
	printf("Enter value of a: ");
	scanf("%x",&a);
	printf("Enter value of b: ");
	scanf("%x",&b);
	
	printf("Value of a: Hex: %X, Decimal: %d\n",a,a);
	printf("Value of b: Hex: %X, Decimal: %d\n",b,b);
	return 0;
}


int Int_by_hex(){
	int arr[]={0x64, 0xAB0, 0xA0A0, 0xFAFA, 0x100};
	int i;
	
	printf("Array elements are\n");
	for(i=0;i<5;i++)
		printf("Decimal: %d, Hex: %X\n",arr[i],arr[i]);
	return 0;
}

int main(){
	Reading_hex();
	Int_by_hex();
	print_hex();
}

