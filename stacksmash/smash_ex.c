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
   char buf[16] = {0};

   printf("hackFun Addr %p\n", &hackFun);
   printf("Stack pointer %p\nBuf address %p\n", __builtin_frame_address(0), buf);

   printf("Reading input... %lu\n", sizeof(buf));
   read(0, buf, 100);
   printf("First 4 characters %c %c %c %c\n", buf[0], buf[1], buf[2], buf[3]);
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
