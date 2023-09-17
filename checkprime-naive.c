/*
 * Copyright (C) Ondřej Surý
 * SPDX-FileCopyrightText: Ondřej Surý
 *
 * SPDX-License-Identifier: WTFPL
 */

#include <inttypes.h>
#include <stdlib.h>

#include "checkprime.h"

int is_prime_naive(uint64_t n)
{
	int ret = 1;

	for (size_t i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}
