#ifndef INTERVAL_H
#define INTERVAL_H

class Interval {
  private:
    unsigned long m_interval;
    unsigned long m_previousMillis;

    void(*m_process)(); // 시간 간격이 됐을 때 호출할 함수에 대한 포힌터
   public:
    Interval(int interval, void (*process)());
    void check();
};

#endif
