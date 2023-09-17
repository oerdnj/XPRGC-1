/*
 * SPDX-FileCopyrightText: Ondřej Surý
 *
 * SPDX-License-Identifier: WTFPL
 */

#include <inttypes.h>
#include <math.h>
#include <stdlib.h>

#include "checkprime.h"

int is_prime_sqrt(uint64_t n)
{
	int ret = 1;

	uint64_t sqroot = sqrt(n);
	for (size_t i = 2; i <= sqroot; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

int is_prime_sqrt_efficient(uint64_t n)
{
	switch (n) {
	case 0:
	case 1:
		return 0;
	case 2:
	case 3:
		return 1;
	default:
		if (n % 2 == 0 || n % 3 == 0) {
			return 0;
		}
	}

	for (int i = 5; i * i <= n; i = i + 6) {
		if (n % i == 0 || n % (i + 2) == 0) {
			return 0;
		}
	}

	return 1;
}
