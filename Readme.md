# FRINT

FRINT (Floating value Represented with INTegers) are floating point number that are represented by two long integers: significand and exponential.
The objective of this work is to develop a custom type that would represent this type in C++. This project contains type declaration and basic arithmetic and logic operations to work with it,
including the conversion to common types.

Also, it contains tests for checking precision and performance.
The full specification and report can be found in `docs/`.

## Tests

There are 2 types of tests present: precision and performance tests.
The former runs operations to ensure that the number representation stays correct on operations,
the latter compares FRINT's performance with float using all available operations.

To run precision tests, use:
```bash
make test-precision && bin/test_precision
```


To run performance tests, use:
```bash
make test-performance && bin/test_performance
```
