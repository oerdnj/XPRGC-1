/*
 * SPDX-FileCopyrightText: Ondřej Surý, P23010
 *
 * SPDX-License-Identifier: WTFPL
 */

#define _GNU_SOURCE
#define _BSD_SOURCE

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "checkprime.h"

typedef int (*bench_fn)(uint64_t n);

#define REPEATS 1000

#define NS_PER_SEC 1000 * 1000 * 1000

uint64_t time_diff(struct timespec *t1, struct timespec *t2)
{
	uint64_t i1 = (uint64_t)t1->tv_sec * NS_PER_SEC + t1->tv_nsec;
	uint64_t i2 = (uint64_t)t2->tv_sec * NS_PER_SEC + t2->tv_nsec;

	assert(i1 >= i2);

	return (i1 - i2);
}

void bench(const int count, const uint64_t n, bench_fn fn, const char *name)
{
	struct timespec start;
	struct timespec finish;

	int r = clock_gettime(CLOCK_REALTIME, &start);
	assert(r == 0);

	int ret = (fn)(n);

	if (ret == -1) {
		printf("%" PRIu64 ": %s failure\n", n, name);
		return;
	}

	for (size_t i = 1; i < count; i++) {
		(fn)(n);
	}

	r = clock_gettime(CLOCK_REALTIME, &finish);
	assert(r == 0);

	printf("%" PRIu64 ": ", n);

	switch (ret) {
	case 0:
		printf("not a prime: ");
		break;
	case 1:
		printf("is a prime : ");
		break;
	default:
		assert(0);
	}

	printf("%20s speed: %0.2fus\n", name,
	       (double)time_diff(&finish, &start) / count);
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Usage: %s <repeats> <number> [<number> ...]\n",
		       argv[0]);
		exit(1);
	}

	long repeats = atol(argv[1]);

	if (repeats < 1) {
		printf("Repeats must be at least 1\n");
		exit(1);
	}

	for (int pos = 2; pos < argc; pos++) {
		uint64_t n = strtoull(argv[pos], NULL, 10);

		bench(repeats, n, is_prime_naive, "Naive approach");
		bench(repeats, n, is_prime_sqrt, "Square root");
		bench(repeats, n, is_prime_sqrt_efficient, "Efficient sqrt");
		bench(repeats, n, is_prime_openssl, "OpenSSL BN");
	}

	return 0;
}
