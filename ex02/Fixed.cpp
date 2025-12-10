#include "Fixed.h"
#include <iostream>
#include <cmath>
#include <iomanip>


Fixed::Fixed() : fixed_point_num_(0) {}

Fixed::Fixed(const Fixed &copy) {
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
    if (this != &fixed) {
        this->fixed_point_num_ = fixed.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
    return fixed_point_num_;
}

void Fixed::setRawBits(int const raw) {
    fixed_point_num_ = raw;
}

Fixed::Fixed(const int value) {
    this->fixed_point_num_ = value * (1 << Fixed::fractional_bits_);
}

Fixed::Fixed(const float value) {
    this->fixed_point_num_ = static_cast<int>(roundf(value * (1 << Fixed::fractional_bits_)));
}

float Fixed::toFloat() const {
    return static_cast<float>(this->fixed_point_num_) / (1 << Fixed::fractional_bits_);
}

int Fixed::toInt() const {
    return this->fixed_point_num_ >> Fixed::fractional_bits_;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    Fixed result;
    const long long sum = (long long)this->getRawBits() + fixed.getRawBits();
    result.setRawBits(static_cast<int>(sum));
    return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    Fixed result;
    const long long diff = (long long)this->getRawBits() - fixed.getRawBits();
    result.setRawBits(static_cast<int>(diff));
    return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    Fixed result;
    const long long product = (long long)this->getRawBits() * fixed.getRawBits();
    result.setRawBits(static_cast<int>(product >> Fixed::fractional_bits_));
    return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    Fixed result;
    const long long shifted = (long long)this->getRawBits() << Fixed::fractional_bits_;

    if (fixed.getRawBits() == 0) {
        std::cout << "DO NOT ENTER 0." << std::endl;
    }

    result.setRawBits(static_cast<int>(shifted / fixed.getRawBits()));
    return result;
}

bool operator<(const Fixed &fixed1, const Fixed &fixed2) {
    return fixed1.getRawBits() < fixed2.getRawBits();
}

bool operator>(const Fixed &fixed1, const Fixed &fixed2) {
    return fixed2 < fixed1;
}

bool operator<=(const Fixed &fixed1, const Fixed &fixed2) {
    return !(fixed2 < fixed1);
}

bool operator>=(const Fixed &fixed1, const Fixed &fixed2) {
    return !(fixed1 < fixed2);
}

bool operator==(const Fixed &fixed1, const Fixed &fixed2) {
    return fixed1.getRawBits() == fixed2.getRawBits();
}

bool operator!=(const Fixed &fixed1, const Fixed &fixed2) {
    return !(fixed1 == fixed2);
}

Fixed& Fixed::operator++() {
    ++this->fixed_point_num_;
    return *this;
}

Fixed Fixed::operator++(int) {
    const Fixed temp = *this;
    ++this->fixed_point_num_;
    return temp;
}

Fixed& Fixed::operator--() {
    --this->fixed_point_num_;
    return *this;
}

Fixed Fixed::operator--(int) {
    const Fixed temp = *this;
    --this->fixed_point_num_;
    return temp;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2) {
    if (fixed1 <= fixed2)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
    if (fixed1 <= fixed2)
        return fixed1;
    return fixed2;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
    if (fixed1 >= fixed2)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
    if (fixed1 >= fixed2)
        return fixed1;
    return fixed2;
}
