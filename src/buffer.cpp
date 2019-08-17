#include "buffer.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>

Buffer::Buffer(std::size_t size)
   :m_capacity(size)
   ,m_next(0)
   ,m_full(false) {
}

void Buffer::reset()
{
  m_next = 0;
  m_full = false;
  m_data = std::vector<float>();
}

size_t Buffer::size() const
{
  return m_data.size();
}

bool Buffer::isFull() const
{
  return m_data.size() == m_capacity;
}



std::vector<float> Buffer::values() const {
  if (!m_full || m_next == 0) {
    std::cerr
      << " returing data as is  "
      << " | next: " << std::setw(3) << m_next
      << " | full: " << m_full << std::endl;
    return std::vector<float>(m_data);
  }
  //
  // copy from 0 to next
  std::cerr
    << " making a copy since "
    << " | next: " << std::setw(3) << m_next
    << " | full: " << m_full << std::endl;
  std::vector<float> values;
  std::copy(m_data.begin()+m_next, m_data.end(), back_inserter(values));
  std::copy(m_data.begin(), m_data.begin() + m_next, back_inserter(values));
  return values;
}

void Buffer::push(float v) {
  if (m_full) {
    m_data[m_next] = v;
  } else {
    m_data.push_back(v);
  }
  auto at = m_next;
  m_next = (m_next + 1) % m_capacity;
  m_full = m_full || m_next == 0;

  std::cerr << "  [" << std::setw(3) << std::right << at <<" ]: "
    << std::setw(10) << std::right << std::showbase << v
    << " | next: " << std::setw(3) << m_next
    << " | full: " << (m_full ? "true" : "false")
    << std::endl;
}

