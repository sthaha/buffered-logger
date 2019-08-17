#ifndef BUFFER_H
#define BUFFER_H

#include <cstddef>
#include <vector>


class Buffer {
public:
  Buffer(std::size_t size);
  void push(float v);
  void reset();
  size_t size() const;
  bool isFull() const;

  std::vector<float> values() const;

private:
  std::size_t m_capacity;
  std::size_t m_next;
  bool m_full;

  std::vector<float> m_data;
};

#endif

