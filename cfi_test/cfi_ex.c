#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

typedef void(*func_ptr_t)(void);


int globval;

// Function Definitions
void fun1();
void fun2();
void hackFun();


int main(int argc, char *args[])
{
   volatile func_ptr_t fptr;
   uint64_t hash = 5381;
   uint64_t val;
   char buf[16];

   printf("fptr addr %p, buf addr %p\n", &fptr, buf);

   if(argc > 2)
   {
     fptr = fun1;
     puts("Choosing fun1\n");
   }
   else
   {
     fptr = fun2;
     puts("Choosing fun2\n");
   }

   printf("Reading input... %lu\n", sizeof(buf));
   read(0, buf, 100);

   fptr();
   return 0;
}

void fun1()
{
  printf("I'm inside fun1\n");
}


void fun2()
{
  printf("I'm inside fun2\n");
}

void hackFun()
{
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   puts("You got hacked!\n");
   fflush(stdout);
   exit(0);
}
