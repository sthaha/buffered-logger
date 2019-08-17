#include <iostream>
#include "logger.h"
#include "random.h"



int main(int , const char *[])
{

  auto r = Random(0.0, 10.0);
  for (int i = 0; i < 10; i++) {
    std::cout << "rand: " << r.next() << std::endl;
  }

  return 0;
}

void logger()
{
  auto l = Logger(20);
  l.setThreshold(8.0003);


  std::cout << "Log using .log" << std::endl;
  l.log(4.15);
  l.log(8.0005);

  std::cout << "Logging using << " << std::endl;
  l << 4.15 << 8.005;
  std::cout << "--------- xXx ----------" << std::endl;
}

