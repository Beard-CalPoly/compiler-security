int foo(int a, int b)
{
  int ret;
  if(a > 10)
  {
     ret = a * b + a % b;
  }
  else
  {
    ret = a + b + (b*2 / 36);
  }
  return ret;
}
