#include "date.h"
/**
 * 
 * @param year is Date year member. It's a unsigned int between 0~9999.
 * @return return is a bool, if it's true, set year is successful.
 */
bool Date::setYear(unsigned int year) {
    this->year = year;
}

bool Date::setMouth(unsigned int mouth) {
    this->mouth = mouth;
}

bool Date::setDay(unsigned int day) {
    this->day = day;
}

unsigned int Date::getYear() {
    return this->year;
}

unsigned int Date::getMouth() {
    return this->mouth;
}

unsigned int Date::getDay() {
    return this->day;
}

