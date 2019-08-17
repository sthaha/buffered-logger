#ifndef LOGGER_H
#define LOGGER_H

class Logger;

class Logger {
public:
  Logger(int size);

  void setThreshold(float t);
  float threshold() const;

  void log(float value);
  Logger& operator<<(float v);

  bool isOverThreshold(float v) const;

private:
  int m_size;
  int m_threshold;
};

#endif
