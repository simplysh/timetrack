#ifndef TIME_H
#define	TIME_H

#include <string>

class Time {
  public:
    Time();
    Time(int seconds);
    Time(const std::string timestamp);
    
    static Time fromMinutes(int minutes);

    int getTime() const;
    int getSeconds() const;
    int getMinutes() const;
    int getHours() const;

    Time operator+(const Time& b);

    std::string toTimeString() const;
    std::string toString() const;
    std::string toSignedString() const;
    std::string toHumanString() const;
  private:
    int seconds_;

    int toSeconds(std::string time) const;
};

inline std::ostream& operator<< (std::ostream& os, const Time& time) {
  os << time.toString();
  return os;
}

#endif
