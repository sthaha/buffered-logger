#include "logger.h"

int main(int , const char *[])
{
  auto l = Logger(20);
  l.setThreshold(8.0003);

  l.log(4.15);
  l.log(8.0005);
  return 0;
}
