/*
 * SPDX-FileCopyrightText: Ondřej Surý, P23010
 *
 * SPDX-License-Identifier: WTFPL
 */

#pragma once

#include <inttypes.h>
#include <stdbool.h>

int is_prime_naive(uint64_t n);
int is_prime_sqrt(uint64_t n);
int is_prime_sqrt_efficient(uint64_t n);
int is_prime_wilsons(uint64_t n);
int is_prime_openssl(uint64_t n);
