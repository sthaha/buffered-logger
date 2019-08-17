#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger;
class Buffer;

class Logger {
public:
  Logger(int size);
	~Logger();

  Logger& setThreshold(float t);
  float threshold() const;

  Logger& setOutput(std::string path);

  void log(float value);
  Logger& operator<<(float v);

  void reset();
  void saveBuffer();

private:
  int m_size;
  float m_threshold;
  bool m_anomalyDetected;

  Buffer *m_before;
  Buffer *m_current;

  std::string m_path;
};

#endif
