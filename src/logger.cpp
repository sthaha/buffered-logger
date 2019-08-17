#include <iostream>
#include "logger.h"


Logger::Logger(int size)
  : m_size(size) {

}


void Logger::log(float v) {
  std::cerr << "logging " << v << std::endl;
}
