#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function Definitions
void foo();
void victim();
void hackFun();

int main(int argc, char *args[])
{
   victim();
   return 0;
}

void victim()
{
   int sanity = 0xdeadbeef;
   char buf[64] = {0};
   int sanity2 = 0xcafeb0ba;

   printf("What do you want? ... %lu\n", sizeof(buf));
   //fgets(buf, sizeof(buf), stdin);
   read(0, buf, 64);
   printf(buf);

   puts("What can you do now? ...\n");
   read(0, buf, 200);

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
