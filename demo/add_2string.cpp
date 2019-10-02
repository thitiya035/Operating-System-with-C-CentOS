#include <stdio.h>
#include <string.h>
 
int main()
{
  char a[1000], b[1000], c[2000];
  
  // get string 1
  printf("Enter the first string\n");
  gets(a);
 
  // get string 2
  printf("Enter the second string\n");
  gets(b);
  
  // get string 2
  printf("Enter the third string\n");
  gets(c);
 
  // concate 
  strcat(a, b);
  strcat(a, c);
 
  printf("String obtained on concatenation: %s\n", a);
 
  return 0;
}
