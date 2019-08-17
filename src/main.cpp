#include <iostream>
#include "logger.h"
#include "random.h"
#include "buffer.h"



int main(int , const char *[])
{

  auto r = Random(0.0, 10.0);
  auto buffer = Buffer(5);

  for (int i = 0; i < 10; i++) {
    auto x = r.next();
    buffer.push(x);
  }

  for (auto i : buffer.values()) {
    std::cout << " ... " << i << std::endl;
  }

  return 0;
}

void testBufferUsingVector()
{
  auto r = Random(0.0, 10.0);
  std::vector<float> data(10);
  int index = 0;

  for (int i = 0 ; i < 4 ; ++i) {
      auto x = r.next();
      std::cout << "  " << i << ": " << x << std::endl;
      data[index++ % 10] = i * 1000 + x;
      index %= 10;
  }

  for (auto it = data.begin()+index ; it < data.end(); ++it)
  {
      std::cout <<  *it << std::endl;
  }

  auto end = data.begin()+index;

  for (auto it = data.begin() ; it != end; ++it)
  {
      std::cout <<  *it << std::endl;
  }

}


void testRandom()
{
  auto r = Random(0.0, 10.0);
  for (int i = 0; i < 10; i++) {
    std::cout << "rand: " << r.next() << std::endl;
  }

}

void testLogger()
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

