// time.cpp

#include "time.h"
#include <iomanip>
#include <sstream>

Time::Time() : hour_(0), minute_(0), second_(0), is_time_valid_(true) {}

Time::Time(uint16_t hour, uint16_t minute, uint16_t second)
    : hour_(hour), minute_(minute), second_(second), is_time_valid_(true) {
    validate_time();
}

void Time::validate_time() {
    if (hour_ < 0 or hour_ > 23 or minute_ < 0 or minute_ > 59 or second_ < 0 or second_ > 59) {
        is_time_valid_ = false;
    } else {
        is_time_valid_ = true;
    }
}

void Time::set_time(uint16_t hour, uint16_t minute, uint16_t second) {
    hour_ = hour;
    minute_ = minute;
    second_ = second;
    validate_time();
}

uint32_t Time::to_seconds(void) const noexcept {
    return hour_ * 3600 + minute_ * 60 + second_;
}

std::string Time::from_seconds(uint32_t seconds) {
    uint16_t hour = seconds / 3600;
    uint16_t minute = (seconds % 3600) / 60;
    uint16_t second = seconds % 60;
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hour << ":"
        << std::setw(2) << std::setfill('0') << minute << ":"
        << std::setw(2) << std::setfill('0') << second;
    return oss.str();
}

std::string Time::to_string(void) const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hour_ << ":"
        << std::setw(2) << std::setfill('0') << minute_ << ":"
        << std::setw(2) << std::setfill('0') << second_;
    return oss.str();
}

bool Time::is_valid(void) const {
    return is_time_valid_;
}
