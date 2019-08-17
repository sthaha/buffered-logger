#include "buffer.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>

Buffer::Buffer(std::size_t size)
   :size(size)
   ,next(0)
   ,rotated(false) {
    data = std::vector<float>(size);
}

void Buffer::reset()
{
  next = 0;
  rotated = false;
}

std::vector<float> Buffer::values() const {
  if (!rotated || next == 0) {
    std::cerr
      << " returing data as is  "
      << " | next: " << std::setw(3) << next
      << " | rotated: " << rotated << std::endl;
    return std::vector<float>(data);
  }
  // copy from 0 to next
  std::cerr
    << " making a copy since "
    << " | next: " << std::setw(3) << next
    << " | rotated: " << rotated << std::endl;
  std::vector<float> values;
  std::copy(data.begin()+next, data.end(), back_inserter(values));
  std::copy(data.begin(), data.begin() + next, back_inserter(values));
  return values;
}

void Buffer::push(float v) {
  data[next++] = v;
  next %=size;
  rotated = rotated || next == 0;

  std::cerr << "  inserted: " << std::setw(10) << v
    << " | next: " << std::setw(3) << next
    << " | rotated: " << rotated << std::endl;
}


