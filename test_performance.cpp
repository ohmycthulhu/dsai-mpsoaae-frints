//
// Created by elvin on 1/8/23.
//

#include <iostream>
#include <vector>
#include <chrono>
#include "Frint.h"

void tests();

void testInitializations();
void testComparisons();
void testArithmetics();
void testConversion();

double getMeanTime(const std::vector<std::chrono::duration<long int>>&);

int main() {
    tests();

    return 0;
}

double getMeanTime(const std::vector<long int>& times) {
    double mean = 0;

    for (long int t : times) {
        mean += t;
    }

    return times.size() > 0 ? mean / times.size() : 0;
}

void tests() {
    std::cout << "Measuring initialization speed..." << std::endl;

    testInitializations();

    std::cout << std::endl << "Measuring conversion speed..." << std::endl;

    testConversion();

    std::cout << std::endl << "Measuring comparison speed..." << std::endl;

    testComparisons();

    std::cout << std::endl << "Measuring arithmetics speed..." << std::endl;

    testArithmetics();

    std::cout << "Finished all tests" << std::endl;
}

void testInitializations() {
    Frint f;
    std::vector<long int> times;
    std::chrono::time_point<std::chrono::system_clock> start, end;

    // Long initialization
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            f = Frint((long)j);
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Long initialization: " << getMeanTime(times) << std::endl;
    times.clear();


    // Float initialization
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            f = Frint((float)j);
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Float initialization: " << getMeanTime(times) << std::endl;
    times.clear();

    // Double initialization
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            f = Frint((double)j);
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Double initialization: " << getMeanTime(times) << std::endl;
    times.clear();
}

void testComparisons() {
    Frint firstSimple(0.16), secondSimple(0.51);
    float floatFSimple = 0.16, floatSSimple = 0.51;
    Frint firstComplex(0.125616), secondComplex(1616.72351);
    float floatFComplex = 0.125616, floatSComplex = 1616.72351;
    bool result;
    std::vector<long int> times;
    std::chrono::time_point<std::chrono::system_clock> start, end;

    // Equal operation

    // Simple
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            result = floatFSimple == floatSSimple;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Equal operation - Simple (float): " << getMeanTime(times) << std::endl;
    times.clear();


    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            result = firstSimple == secondSimple;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Equal operation - Simple: " << getMeanTime(times) << std::endl;
    times.clear();

    // Complex

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            result = floatFComplex == floatSComplex;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Equal operation - Complex (float): " << getMeanTime(times) << std::endl;
    times.clear();

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            result = firstComplex == secondComplex;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Equal operation - Complex: " << getMeanTime(times) << std::endl;
    times.clear();

    // Lt operation

    // Simple
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            result = floatFSimple < floatSSimple;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Equal operation - Simple (float): " << getMeanTime(times) << std::endl;
    times.clear();

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            result = firstSimple < secondSimple;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Equal operation - Simple: " << getMeanTime(times) << std::endl;
    times.clear();

    // Complex

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            result = floatFSimple < floatSSimple;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Equal operation - Complex (float): " << getMeanTime(times) << std::endl;
    times.clear();

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            result = firstComplex < secondComplex;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Equal operation - Complex: " << getMeanTime(times) << std::endl;
    times.clear();
}

void testArithmetics() {
    float firstF = 61.2177, secondF = 1623.711;
    Frint firstFr(firstF), secondFr(secondF);
    std::vector<long int> times;
    std::chrono::time_point<std::chrono::system_clock> start, end;

    float resultF;
    Frint resultFr;

    // Negation
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultF = -firstF;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Negation operation - float: " << getMeanTime(times) << std::endl;
    times.clear();

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultFr = -firstFr;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Negation operation - FRINT: " << getMeanTime(times) << std::endl;
    times.clear();

    // Addition
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultF = firstF + secondF;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Addition operation - float: " << getMeanTime(times) << std::endl;
    times.clear();

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultFr = firstFr + secondFr;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Addition operation - FRINT: " << getMeanTime(times) << std::endl;
    times.clear();

    // Subtraction
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultF = firstF - secondF;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Subtraction operation - float: " << getMeanTime(times) << std::endl;
    times.clear();

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultFr = firstFr - secondFr;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Subtraction operation - FRINT: " << getMeanTime(times) << std::endl;
    times.clear();


    // Inverse
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultF = 1 / firstF;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Inverse operation - float: " << getMeanTime(times) << std::endl;
    times.clear();

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultFr = ~firstFr;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Inverse operation - FRINT: " << getMeanTime(times) << std::endl;
    times.clear();

    // Multiplication
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultF = firstF * secondF;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Multiplication operation - float: " << getMeanTime(times) << std::endl;
    times.clear();

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultFr = firstFr * secondFr;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Multiplication operation - FRINT: " << getMeanTime(times) << std::endl;
    times.clear();

    // Division
    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultF = firstF / secondF;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Division operation - float: " << getMeanTime(times) << std::endl;
    times.clear();

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultFr = firstFr - secondFr;
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "Division operation - FRINT: " << getMeanTime(times) << std::endl;
    times.clear();
}

void testConversion() {
    Frint frintNumber(612.6116);
    std::vector<long int> times;
    std::chrono::time_point<std::chrono::system_clock> start, end;

    // To float
    float result;

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            result = frintNumber.toFloat();
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "To float: " << getMeanTime(times) << std::endl;
    times.clear();

    // To long
    long resultLong;

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultLong = frintNumber.toLong();
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "To long: " << getMeanTime(times) << std::endl;
    times.clear();

    // To string
    std::string resultString;

    for (int i = 0; i < 20; i++) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++) {
            resultString = frintNumber.toString();
        }

        end = std::chrono::high_resolution_clock::now();
        times.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
    std::cout << "To string: " << getMeanTime(times) << std::endl;
    times.clear();
}
