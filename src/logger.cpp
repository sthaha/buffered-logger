#include <iostream>
#include <fstream>
#include <limits>
#include "logger.h"
#include "buffer.h"


Logger::Logger(int size)
  :m_size(size)
  ,m_threshold(0.0)
  ,m_anomalyDetected(false)
  ,m_before(0) {
  m_current = new Buffer(m_size);
}

Logger::~Logger(){
	if (m_anomalyDetected) {
		saveBuffer();
	}
}


Logger& Logger::setThreshold(float t){
  m_threshold = t;
  return *this;
}

Logger& Logger::setOutput(std::string path){
  m_path = path;
  return *this;
}


float Logger::threshold() const {
  return m_threshold;
}

void Logger::log(float v) {
  std::cerr <<  ">>>  log: " << v
      << "| t :" << m_threshold <<  "  to: " << m_current
      << "| anomaly: " << (m_anomalyDetected? "true" : "false") <<  "  to: " << m_current
      << std::endl;
  m_current->push(v);

  if (m_anomalyDetected) {
    if(!m_current->isFull()) {
      return;
    }

    saveBuffer();
    reset();
		return;
  }

	if( v > m_threshold ) {
			std::cerr <<  ">>> >>> >>>  " << v << " crossed " << m_threshold << std::endl;
			m_anomalyDetected = true;
			m_before = m_current;
			m_current = new Buffer(m_size);
		}
}

Logger& Logger::operator<<(float v) {
  log(v);
  return *this;
}

void Logger::reset() {
	m_anomalyDetected = false;
	m_before = 0;
	m_current->reset();
}

void Logger::saveBuffer() {
  std::cerr << "#####  " << " write both buffers " << std::endl;
	std::ofstream f;
  f.open(m_path, std::ios::out|std::ios::app);
	f << "--------------------------------------------" << std::endl;
	for(auto v : m_before->values()) {
		f << v << std::endl;
	}
f << "   - - - - - - - - - - - - - " << std::endl;
	for(auto v : m_current->values()) {
		f << v << std::endl;
	}
	f.close();
}
