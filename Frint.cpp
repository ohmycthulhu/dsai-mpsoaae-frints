//
// Created by elvin on 1/8/23.
//
#include "Frint.h"

/**
 * Constructors
 * */

Frint::Frint() {
    /* TODO: Implement */
}

Frint::Frint(const Frint &) {
    /* TODO: Implement */
}

Frint::Frint(const long int significand, const long int exponent) {
    /* TODO: Implement */
}

Frint::Frint(const long number) {
    /* TODO: Implement */
}

Frint::Frint(const float number) {
    /* TODO: Implement */
}

Frint::Frint(const double number) {
    /* TODO: Implement */
}

/**
 * Relation between other types
 * */

float Frint::toFloat() const {
    /* TODO: Implement */
    return 0.0f;
}

double Frint::toDouble() const {
    /* TODO: Implement */
    return 0.0;
}

long Frint::toLong() const {
    /* TODO: Implement */
    return 0L;
}

std::string Frint::toString() const {
    /* TODO: Implement */
    return "";
}

/**
 * Comparison operations
 * */

bool Frint::operator==(const Frint& other) const {
    /* TODO: Implement */
    return false;
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
    /* TODO: Implement */
    return false;
}

bool Frint::operator<=(const Frint& other) const {
    /* TODO: Implement */
    return false;
}

/**
 * Arithmetic operators
 * */

Frint Frint::operator+(const Frint& other) const {
    /* TODO: Implement */
    return *this;
}

Frint Frint::operator-(const Frint& other) const {
    /* TODO: Implement */
    return *this;
}

Frint Frint::operator*(const Frint& other) const {
    /* TODO: Implement */
    return *this;
}

Frint Frint::operator/(const Frint& other) const {
    /* TODO: Implement */
    return *this;
}

Frint Frint::operator-() const {
    /* TODO: Implement */
    return *this;
}

Frint Frint::operator~() const {
    /* TODO: Implement */
    return *this;
}

/**
 * Protected functions
 * */

/**
 * Shifting
 * */

long int Frint::shiftLeft(long int number, u_short nb) const {
    /* TODO: Implement */
    return number;
}

long int Frint::shiftRight(long int number, u_short nb) const {
    /* TODO: Implement */
    return number;
}

/**
 * Number normalization
 * */

void Frint::normalizeNumbers(const Frint &bigger, const Frint &smaller, long *fOutput, long *sOutput) const {
    /* TODO: Implement */

    *fOutput = bigger.mSignificand;
    *sOutput = smaller.mSignificand;
}

long Frint::normalizeSignificand(const Frint &first, const u_short nbDigitsF, const u_short nbDigitsS) const {
    if (nbDigitsF > nbDigitsS) {
        return this->shiftLeft(first.mSignificand, nbDigitsF - nbDigitsS);
    } else if (nbDigitsS > nbDigitsF) {
        return this->shiftRight(first.mSignificand, nbDigitsS - nbDigitsF);
    }

    return first.mSignificand;
}
