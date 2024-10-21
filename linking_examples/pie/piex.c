#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#define _ISOC99_SOURCE
#include <math.h>

// Function Definitions
void foo();
void victim();
void hackFun();

int main(int argc, char *args[])
{
   printf("Main   address: %p %lf\n", &main, log2((long int)&main));
   printf("foo    address: %p %lf\n", &foo, log2((long int)&foo));
   printf("printf address: %p %lf\n", &printf, log2((long int)&printf));

   return 0;
}

void foo()
{
  printf("Foo addr %p\n", &foo);
}
