#include <iostream>
#include "logger.h"
#include "random.h"
#include "buffer.h"


void testInsertMoreThanBuffer();
void testInsertMoreThanBuffer(size_t bufferSize, int samples);
void testLogAnomaly();

bool nearlyEqual(float a, float b);

int main(int , const char *[])
{

	testLogAnomaly();
	//testInsertMoreThanBuffer();
  return 0;
}


bool nearlyEqual(float a, float b)
{
   return fabs(a - b) <= std::numeric_limits<float>::epsilon();
}

void testInsertMoreThanBuffer()
{
	testInsertMoreThanBuffer(5, 5);
	testInsertMoreThanBuffer(5, 15);
	testInsertMoreThanBuffer(5, 13);
	testInsertMoreThanBuffer(5, 43);
	testInsertMoreThanBuffer(3, 2);
}


void testLogAnomaly()
{
  Logger log(20);
  log.setThreshold(2.0003)
		.setOutput("/tmp/record.log");


  auto r = Random(0.0, 10.0);
  for (int i = 0; i < 80; i++) {
    log << r.next();
  }
}

void testInsertMoreThanBuffer(size_t bufferSize, int samples)
{
  auto buffer = Buffer(bufferSize);
  std::vector<float> values;

	auto r = Random(0.0, 10.0);
  for (int i = 0; i < samples; i++) {
    auto x = r.next();
    values.push_back(x);
    buffer.push(x);
  }

	std::cerr << "\t- - - - - - - - - - - - - -" << std::endl;
  auto v = values.end() - buffer.size();
  for (auto i : buffer.values()) {
    std::cout << (nearlyEqual(i, *v) ? "ok" : "FAIL")
				<< ": " << i << " == " << *v << " : "
				<< std::endl;
    ++v;
  }

	std::cerr << "---------------------------------------" << std::endl;

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

  for (auto it = data.begin()+index ; it < data.end(); ++it) {
      std::cout <<  *it << std::endl;
  }

  auto end = data.begin()+index;

  for (auto it = data.begin() ; it != end; ++it) {
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

