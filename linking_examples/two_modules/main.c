extern int foo(int, int);

int main(int argc, char *argv[])
{
    int a;
    if(argc > 5)
    {
        a = foo(argc, argc*2);
    }
    else
    {
        a = foo(argc, argc/2);
    }

  return a;
}