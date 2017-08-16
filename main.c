#include "hamming.h"

#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

double diff(double start, double end) {
  double temp;
  if ((end - start) < 0) {
  	return 1000000000 + end - start;
  } else {
		return end - start;
  }
  return temp;
}

int _hammingDistance(char* a, char* b) {
	return distance(a, b, strlen(a), strlen(b));
}

int main() {
	printf("\nRunning unit tests\n");

	// expectations

	// matches
	if (_hammingDistance("", "") != 0) {
		return 1;
	}
	if (_hammingDistance("a", "a") != 0) {
		return 1;
	}
	if (_hammingDistance("abc", "abc") != 0) {
		return 1;
	}

	// swaps only

	if (_hammingDistance("a", "b") != 1) {
		return 1;
	}
	if (_hammingDistance("ab", "ac") != 1) {
		return 1;
	}
	if (_hammingDistance("ac", "bc") != 1) {
		return 1;
	}
	if (_hammingDistance("abc", "axc") != 1) {
		return 1;
	}
	if (_hammingDistance("xabxcdxxefxgx", "1ab2cd34ef5g6") != 6) {
		return 1;
	}

	printf("passed");

	// micro benchmark

	int i;
	unsigned int times = 20000000;

	printf("\n\nRunning benchmark %lu times \n", (unsigned long) times);

	double total_time = 0;
	double clock_cost = 0;

	struct timespec t1;
	struct timespec t2;

	for (i = 0; i < times; ++i) {
		clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		clock_cost += diff(t1.tv_nsec, t2.tv_nsec);

		clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
		_hammingDistance("xabxcdxxefxgx", "1ab2cd34ef5g6");
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		total_time += diff(t1.tv_nsec, t2.tv_nsec);
	}

	printf("median: %f ns/op\n\n", ((total_time-clock_cost)/times));

	return 0;
}