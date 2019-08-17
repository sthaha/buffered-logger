#include "logger.h"

int main(int , const char *[])
{
  auto l = Logger(20);
  l.log(4.15);
  return 0;
}
