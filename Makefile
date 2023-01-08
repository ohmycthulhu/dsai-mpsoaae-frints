test-performance:
	g++ test_performance.cpp Frint.cpp -o bin/test_performance -Og

test-precision:
	g++ test_precision.cpp Frint.cpp -o bin/test_precision
