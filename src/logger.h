#ifndef LOGGER_H
#define LOGGER_H

class Logger;

class Logger {
public:
  Logger(int size);
  void log(float value);

private:
  int m_size;
};

#endif
