#ifndef DURATION_H
#define DURATION_H

#include "port.h"

#include <sys/time.h>
#include <unistd.h>

class Duration_Base
{
public:
  Duration_Base();
  virtual ~Duration_Base() {};
  void reset(){ m_sum = 0.0; number_of_latencies = 0; }
  double start();
  double stop();
  double getMean() { return (m_sum / number_of_latencies); }

  virtual bool getTime(double *tv) = 0;

private:
  double m_start;
  double m_sum;
  int number_of_latencies;
};

class Duration : public Duration_Base
{
public:
  virtual bool getTime(double *time);
};

class CPU_Duration : public Duration_Base
{
public:
  virtual bool getTime(double *time);
};

#endif
