#ifndef RANDOM_H
#define RANDOM_H

#include <random>

class Random {
public:
  Random(float min, float max)
    :min(min)
    ,max(max)
    ,spread(RAND_MAX/(max - min)){
    std::srand(time(nullptr)); // Seed std::rand
  }

  float next() const
  {
    return min + static_cast<float>(std::rand())/spread;
  }

private:
  float min;
  float max;
  float spread;
};

#endif
