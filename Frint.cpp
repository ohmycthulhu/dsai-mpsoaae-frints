//
// Created by elvin on 1/8/23.
//
#include <math.h>
#include <sstream>
#include "Frint.h"

double TEN_POWERS[] = {1e-127, 1e-126, 1e-125, 1e-124, 1e-123, 1e-122, 1e-121, 1e-120, 1e-119, 1e-118, 1e-117, 1e-116, 1e-115, 1e-114, 1e-113, 1e-112, 1e-111, 1e-110, 1e-109, 1e-108, 1e-107, 1e-106, 1e-105, 1e-104, 1e-103, 1e-102, 1e-101, 1e-100, 1e-99, 1e-98, 1e-97, 1e-96, 1e-95, 1e-94, 1e-93, 1e-92, 1e-91, 1e-90, 1e-89, 1e-88, 1e-87, 1e-86, 1e-85, 1e-84, 1e-83, 1e-82, 1e-81, 1e-80, 1e-79, 1e-78, 1e-77, 1e-76, 1e-75, 1e-74, 1e-73, 1e-72, 1e-71, 1e-70, 1e-69, 1e-68, 1e-67, 1e-66, 1e-65, 1e-64, 1e-63, 1e-62, 1e-61, 1e-60, 1e-59, 1e-58, 1e-57, 1e-56, 1e-55, 1e-54, 1e-53, 1e-52, 1e-51, 1e-50, 1e-49, 1e-48, 1e-47, 1e-46, 1e-45, 1e-44, 1e-43, 1e-42, 1e-41, 1e-40, 1e-39, 1e-38, 1e-37, 1e-36, 1e-35, 1e-34, 1e-33, 1e-32, 1e-31, 1e-30, 1e-29, 1e-28, 1e-27, 1e-26, 1e-25, 1e-24, 1e-23, 1e-22, 1e-21, 1e-20, 1e-19, 1e-18, 1e-17, 1e-16, 1e-15, 1e-14, 1e-13, 1e-12, 1e-11, 1e-10, 1e-9, 1e-8, 1e-7, 1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 1e-1, 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9, 1e10, 1e11, 1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19, 1e20, 1e21, 1e22, 1e23, 1e24, 1e25, 1e26, 1e27, 1e28, 1e29, 1e30, 1e31, 1e32, 1e33, 1e34, 1e35, 1e36, 1e37, 1e38, 1e39, 1e40, 1e41, 1e42, 1e43, 1e44, 1e45, 1e46, 1e47, 1e48, 1e49, 1e50, 1e51, 1e52, 1e53, 1e54, 1e55, 1e56, 1e57, 1e58, 1e59, 1e60, 1e61, 1e62, 1e63, 1e64, 1e65, 1e66, 1e67, 1e68, 1e69, 1e70, 1e71, 1e72, 1e73, 1e74, 1e75, 1e76, 1e77, 1e78, 1e79, 1e80, 1e81, 1e82, 1e83, 1e84, 1e85, 1e86, 1e87, 1e88, 1e89, 1e90, 1e91, 1e92, 1e93, 1e94, 1e95, 1e96, 1e97, 1e98, 1e99, 1e100, 1e101, 1e102, 1e103, 1e104, 1e105, 1e106, 1e107, 1e108, 1e109, 1e110, 1e111, 1e112, 1e113, 1e114, 1e115, 1e116, 1e117, 1e118, 1e119, 1e120, 1e121, 1e122, 1e123, 1e124, 1e125, 1e126, 1e127};
short TEN_POWER_OFFSET = 127;

/**
 * Helper functions
 * */

inline short numberOfDigits(long int number) {
    if (number == 0) {
        return 0;
    }

    float l = log10(abs(number));

    return (u_short)l + 1;
}

inline short numberOfDigits(float number) {
    if (number == 0) {
        return 0;
    }

    float l = log10(abs(number));

    if (l >= 0) {
        return (u_short)l + 1;
    }

    u_short b = (u_short)l;
    float ignored = l - b;

    if (ignored == 0) {
        return b + 1;
    }

    return b;
}

inline short numberOfDigits(double number) {
    if (number == 0) {
        return 0;
    }

    double l = log10(abs(number));

    if (l >= 0) {
        return (u_short)l + 1;
    }

    u_short b = (u_short)l;
    double ignored = l - b;

    if (ignored == 0) {
        return b + 1;
    }

    return b;
}

inline double powerTen(short deg) {
    return TEN_POWERS[deg + TEN_POWER_OFFSET];
}

long MAX_NUMBER = 10000000; /* 10^7 */
long MAX_DIGITS = 9; /* 10^7 */

/**
 * Constructors
 * */

Frint::Frint() : mSignificand(0), mExponent(0), mNbDigits(0) {}

Frint::Frint(const Frint & other) : mSignificand(other.mSignificand), mExponent(other.mExponent) {
    this->mNbDigits = numberOfDigits(this->mSignificand);
}

Frint::Frint(const long int significand, const long int exponent) : mSignificand(significand), mExponent(exponent) {
    this->mNbDigits = numberOfDigits(this->mSignificand);
}

Frint::Frint(const long number) {
    this->mSignificand = number;
    this->mExponent = numberOfDigits(number);
    this->mNbDigits = this->mExponent;
}

Frint::Frint(const float number) {
    this->mExponent = numberOfDigits(number);
    double base = number / powerTen(this->mExponent);
    this->mSignificand = (long)(base * MAX_NUMBER);
    this->mNbDigits = numberOfDigits(this->mSignificand);
}

Frint::Frint(const double number) {
    this->mExponent = numberOfDigits(number);
    double base = number / powerTen(this->mExponent);
    this->mSignificand = (long)(base * MAX_NUMBER);
    this->mNbDigits = numberOfDigits(this->mSignificand);
}

/**
 * Relation between other types
 * */

float Frint::toFloat() const {
    return ((float)this->mSignificand) * powerTen(this->mExponent) / powerTen(this->mNbDigits);
}

double Frint::toDouble() const {
    return ((double)this->mSignificand) * powerTen(this->mExponent) / powerTen(this->mNbDigits);
}

long Frint::toLong() const {
    if (this->mExponent <= 0) {
        return 0L;
    }

    if (this->mExponent == this->mNbDigits) {
        return this->mSignificand; // 0.716 * 10^3 = 716
    }

    if (this->mExponent < this->mNbDigits) {
        return this->shiftRight(this->mSignificand, this->mNbDigits - this->mExponent); // 0.752 * 10^2 ~= 75
    } else {
        return this->shiftLeft(this->mSignificand, this->mExponent - this->mNbDigits); // 0.752 * 10^4 = 7520
    }
}

std::string Frint::toString() const {
    std::ostringstream ss;
    ss << "0." << this->mSignificand << " * 10^" << this->mExponent;
    return ss.str();
}

/**
 * Comparison operations
 * */

bool Frint::operator==(const Frint& other) const {
    return this->mExponent == other.mExponent && this->mSignificand == other.mSignificand;
}

bool Frint::operator!=(const Frint& other) const {
    return !this->operator==(other);
}

bool Frint::operator>(const Frint& other) const {
    return !this->operator<=(other);
}

bool Frint::operator>=(const Frint& other) const {
    return !this->operator<(other);
}

bool Frint::operator<(const Frint& other) const {
    if (this->mExponent != other.mExponent) {
        return this->mExponent < other.mExponent;
    }

    long f, s;

    this->normalizeNumbers(*this, other, &f, &s);

    if (f != s) {
        return f < s;
    }

    return this->mNbDigits < other.mNbDigits;
}

bool Frint::operator<=(const Frint& other) const {
    return this->operator==(other) || this->operator<(other);
}

/**
 * Arithmetic operators
 * */

Frint Frint::operator+(const Frint& other) const {
    if (this->operator<(other)) {
        return other.operator+(*this);
    }

    /* TODO: Implement */
    return Frint(*this);
}

Frint Frint::operator-(const Frint& other) const {
    return this->operator+(other.operator-());
}

Frint Frint::operator*(const Frint& other) const {
    /* TODO: Implement */
    return Frint(*this);
}

Frint Frint::operator/(const Frint& other) const {
    return this->operator*(other.operator~());
}

Frint Frint::operator-() const {
    return Frint(-this->mSignificand, this->mExponent);
}

Frint Frint::operator~() const {
    /* TODO: Implement */
    return Frint(*this);
}

/**
 * Protected functions
 * */

/**
 * Shifting
 * */

long int Frint::shiftLeft(long int number, u_short nb) const {
    return number * powerTen(nb);
}

long int Frint::shiftRight(long int number, u_short nb) const {
    return number / powerTen(nb);
}

/**
 * Number normalization
 * */

void Frint::normalizeNumbers(const Frint &bigger, const Frint &smaller, long *fOutput, long *sOutput) const {
    if (bigger.mNbDigits < smaller.mNbDigits) {
        return normalizeNumbers(smaller, bigger, sOutput, fOutput);
    }

    long fTemp = bigger.mSignificand, sTemp = smaller.mSignificand;

    if (bigger.mNbDigits + smaller.mNbDigits < MAX_DIGITS) {
        *fOutput = fTemp;
        *sOutput = sTemp;
        return;
    }

    if (smaller.mNbDigits * 2 < MAX_DIGITS) {
        fTemp = this->shiftRight(fTemp, bigger.mNbDigits - smaller.mNbDigits);
    } else {
        fTemp = this->shiftRight(fTemp, bigger.mNbDigits - MAX_DIGITS / 2);
        sTemp = this->shiftRight(sTemp, smaller.mNbDigits - MAX_DIGITS / 2);
    }

    *fOutput = fTemp;
    *sOutput = sTemp;
}

long Frint::normalizeSignificand(const Frint &first, const u_short nbDigitsF, const u_short nbDigitsS) const {
    if (nbDigitsF > nbDigitsS) {
        return this->shiftLeft(first.mSignificand, nbDigitsF - nbDigitsS);
    } else if (nbDigitsS > nbDigitsF) {
        return this->shiftRight(first.mSignificand, nbDigitsS - nbDigitsF);
    }

    return first.mSignificand;
}
