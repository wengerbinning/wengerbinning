#ifndef __DATE_H
#define __DATE_H

class Date {
    private:
        unsigned int year;
        unsigned int mouth;
        unsigned int day;
    public:
        Date(unsigned int year, unsigned int mouth, unsigned int day):
        year(year),mouth(mouth),day(day){};
        Date() : Date(1999, 05, 29){};
        bool setYear(unsigned int year);
        bool setMouth(unsigned int Mouth);
        bool setDay(unsigned int day);
        unsigned int getYear();
        unsigned int getMouth();
        unsigned int getDay();
};

#endif
