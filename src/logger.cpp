#include <iostream>
#include <limits>
#include "logger.h"


Logger::Logger(int size)
  :m_size(size)
  ,m_threshold(0.0) {

}

bool Logger::isOverThreshold(float v) const{
  return (v - m_threshold ) > std::numeric_limits<float>::epsilon();
}

void Logger::log(float v) {
  std::cerr << "logging " << v << std::endl;

  if (isOverThreshold(v)) {
    std::cerr << v << " crossed the threshold " << m_threshold << std::endl;
  }
}

void Logger::setThreshold(float t){
  m_threshold = t;
}

float Logger::threshold() const {
  return m_threshold;
}
