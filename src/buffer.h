#ifndef BUFFER_H
#define BUFFER_H

#include <cstddef>
#include <vector>


class Buffer {
public:
  Buffer(std::size_t size);
  void push(float v);
  void reset();

  std::vector<float> values() const;

private:
  std::size_t size;
  std::size_t next;
  bool rotated;

  std::vector<float> data;
};

#endif

