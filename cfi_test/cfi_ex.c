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
   //read(0, buf, 100);

   (*fptr)();

   hackFun();

   return 0;
}


__attribute__((noinline))
void fun1()
{
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
  printf("I'm inside fun1\n");
}


__attribute__((noinline))
void fun2()
{
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
  printf("I'm inside fun2\n");
}


__attribute__((noinline))
void hackFun()
{
   int val, i;
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop");
   puts("You got hacked!\n");
   fflush(stdout);
   //val = rand();
   scanf("%d", &val);
   for(i=1; i < val; ++i)
   {
     val = (val  % (val*i)) % val*i;
   }
   printf("val %d\n", val);
   //exit(0);
}
