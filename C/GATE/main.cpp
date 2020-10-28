#include <iostream>
int main()
{
  printf("%6d\n", 10);
  printf("%6d\n", 300);
  printf("%6.2f\n", 1545.3);
  char c = getchar();
  putchar(c);
  while ((c = getchar()) != EOF)
    putchar(c);
  return 0;
}