//
// Created by elvin on 1/8/23.
//

#ifndef DSAI_MPSOAAE_FRINTS_FRINT_H
#define DSAI_MPSOAAE_FRINTS_FRINT_H

#include<string>


class Frint {
public:
    Frint();
    Frint(const Frint&);
    Frint(const long int significand, const long int exponent);
    Frint(const long number);
    Frint(const float number);
    Frint(const double number);

    float toFloat() const;
    double toDouble() const;
    long toLong() const;
    std::string toString() const;

    bool operator==(const Frint&) const; /* X == Y */
    bool operator!=(const Frint&) const; /* X != Y */
    bool operator>(const Frint&) const; /* X > Y */
    bool operator>=(const Frint&) const; /* X >= Y */
    bool operator<(const Frint&) const; /* X < Y */
    bool operator<=(const Frint&) const; /* X <= Y */

    Frint operator+(const Frint&) const; /* X + Y */
    Frint operator-(const Frint&) const; /* X - Y */
    Frint operator*(const Frint&) const; /* X * Y */
    Frint operator/(const Frint&) const; /* X / Y */
    Frint operator-() const; /* -X */
    Frint operator~() const; /* X^-1 */
protected:
    long int shiftLeft(long int number, u_short nb) const;
    long int shiftRight(long int number, u_short nb) const;

    void normalizeNumbers(const Frint& bigger, const Frint& smaller, long int* fOutput, long int* sOutput) const;
    long int normalizeSignificand(const Frint& other, const u_short nbDigitsF, const u_short nbDigitsS) const;

    long int mSignificand;
    long int mExponent;
    unsigned short mNbDigits;
};

#endif //DSAI_MPSOAAE_FRINTS_FRINT_H
