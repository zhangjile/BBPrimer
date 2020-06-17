// pilgrimage to C
#include <stdio.h>

int main(void) {
	printf("This is my first C program, 23/04/2020!\n");
	printf("1900 + 71 = %d\n", 1900+71);
	printf("1900\n  71 +\n------\n%d\n", 1900 + 71);
	
	
  char str [80];
  int i;

  printf ("Enter your family name: ");
  scanf ("%79s",str);      //no more than 79 characters
  printf ("Enter your age: ");
  scanf ("%d",&i);
  printf ("Mr. %s , %d years old.\n",str,i);
  printf ("Enter a hexadecimal number: ");
  
  scanf ("%x",&i);
  printf ("\nYou have entered %#x (%d).\n",i,i);     //0x30 (48)
  
  
	int x, y;
	float z;
	scanf("%d",&x);
	scanf("%d%f",&y, &z);
	printf("x = %d, y = %d, z = %f", x,y,z);
  
 
	return 0;
}
