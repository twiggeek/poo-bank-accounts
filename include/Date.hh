#ifndef DATE_HH
#define DATE_HH

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

class Date {
private:
  unsigned int      _day;
  unsigned int      _month;
  unsigned int      _year;
  std::string       _dateAsString;
  std::vector<unsigned int>  _nbrDaysInMonths;

  bool isValid();
public:
  Date(const unsigned int day, const unsigned int month, const unsigned int year);
  Date(const std::string &dateAsString);
  Date(const Date &date);
  Date &operator=(const Date &date);

  ~Date();

  const unsigned int &getDay()         const;
  const unsigned int &getMonth()       const;
  const unsigned int &getYear()        const;
  const std::string  &getDateString()  const;

  bool compareDay(Date *date) const;
  bool compareMonth(Date *date) const;
};

std::ostream &operator<<(std::ostream &os, const Date *date);

#endif // DATE_HH
