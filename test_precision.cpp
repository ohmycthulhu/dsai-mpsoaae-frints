//
// Created by elvin on 1/8/23.
//

#include <iostream>
#include "Frint.h"

void tests();

template <typename T>
void testRepresentation(const T number);

void testResult(const std::string msg, const bool result);
void testResult(const std::string msg, const Frint result);

int main() {
    std::cout << "Starting precision tests" << std::endl;

    tests();

    std::cout << "Tests ended tests" << std::endl;
    return 0;
}


template <typename T>
void testRepresentation(const T number) {
    Frint represented(number);
    std::cout << "Number " << number << ": " << represented.toFloat() << std::endl;
}


void testResult(const std::string msg, const bool result) {
    std::cout << "Test " << msg << ": " << result << std::endl;
}

void testResult(const std::string msg, const Frint result, const double actual) {
    std::cout << "Test " << msg << ": " << result.toFloat() << " (" << actual << ")" << std::endl;
}

void tests() {
    std::cout << "Number representation" << std::endl;

    // Number 0
    testRepresentation(0L);

    // Number 1
    testRepresentation(1L);

    // Float 0.56
    testRepresentation(0.56f);

    // Float 0.006121
    testRepresentation(0.006121f);

    // Float 612.71232
    testRepresentation(612.71232f);

    // Long 7123600
    testRepresentation(71213600L);

    // Float 712610000
    testRepresentation(712610000L);

    // Float 0.999
    testRepresentation(0.999f);

    std::cout << std::endl << "Conversion" << std::endl;

    double initialNumber = 567.61217;
    Frint number(initialNumber);
    std::cout << "Converting " << initialNumber << " to string: " << number.toString() << std::endl;
    std::cout << "Converting " << initialNumber << " to long: " << number.toLong() << std::endl;
    std::cout << "Converting " << initialNumber << " to float: " << number.toFloat() << std::endl;
    std::cout << "Converting " << initialNumber << " to double: " << number.toDouble() << std::endl;

    std::cout << std::endl << "Comparison operations" << std::endl;

    std::cout << std::boolalpha;

    // 6.1 > 5.2
    testResult(
            "6.1 > 5.2",
            Frint(6.1f) > Frint(5.2f)
        );

    // 0.9 < 4.1
    testResult(
            "0.9 < 4.1",
            Frint(0.9) > Frint(4.1)
    );

    // 0.4 == 0.4
    testResult(
            "0.4 == 0.4",
            Frint(0.4) == Frint(0.4)
    );

    // 0.61212 == 0.0061212
    testResult(
            "0.61212 == 0.0061212",
            Frint(0.61212f) == Frint(0.0061212f)
    );

    // 0.5121 != 4.122
    testResult(
            "0.5121 != 4.122",
            Frint(0.5121f) != Frint(4.122f)
    );

    // 0.4 < 0.5
    testResult(
            "0.4 < 0.5",
            Frint(0.4f) < Frint(0.5f)
    );

    // 0.4 >= 0.5
    testResult(
            "0.4 >= 5.2",
            Frint(0.4f) >= Frint(5.2f)
    );


    std::cout << std::endl << "Arithmetic operations" << std::endl;

    // 5.12 + 8
    testResult(
            "5.12 + 8",
            Frint(5.12f) + Frint(8L),
            5.12 + 8
    );

    // 9 + 0
    testResult(
            "9 + 0",
            Frint(9L) + Frint(0L),
            9 + 0
    );

    // 0.512 + 0.682
    testResult(
            "0.512 + 0.682",
            Frint(0.512) + Frint(0.682),
            0.512 + 0.682
    );

    // 0.512^-1
    testResult(
            "0.512^-1",
            ~Frint(0.512),
            1 / 0.512
    );

    // 0.0216 + 0.941
    testResult(
            "0.0216 + 0.941",
            Frint(0.0216) + Frint(0.941),
            0.0216 + 0.941
    );

    // 16 * 95213
    testResult(
            "16 * 95213",
            Frint(16L) * Frint(95213L),
            16 * 95213
    );

    // 0.176 * 0.00125
    testResult(
            "0.176 * 0.00125",
            Frint(0.176) * Frint(0.00125),
            0.176 * 0.00125
    );

    // 71 * 96.444
    testResult(
            "71 * 96.444",
            Frint(71L) * Frint(96.444),
            71 * 96.444
    );

    // 18 * 2.4271
    testResult(
            "18 * 2.4271",
            Frint(18L) * Frint(2.4271),
            18 * 2.4271
    );

    // 18 / 0.4126
    testResult(
            "18 / 0.4126",
            Frint(18L) / Frint(0.4126),
            18 / 0.4126
    );

    // 41 - 0.999
    testResult(
            "41 - 0.999",
            Frint(41L) - Frint(0.999),
            41 - 0.999
    );
}
