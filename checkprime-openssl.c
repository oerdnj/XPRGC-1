/*
 * SPDX-FileCopyrightText: Ondřej Surý, P23010
 *
 * SPDX-License-Identifier: WTFPL
 */

#include <assert.h>

#include "checkprime.h"

#include <openssl/bn.h>
#include <openssl/err.h>

static BN_CTX *ctx = NULL;
static BIGNUM *bn = NULL;

static void __attribute__((__constructor__)) _BN_CTX_ctor(void)
{
	ctx = BN_CTX_new();
	assert(ctx != NULL);

	bn = BN_new();
	assert(bn != NULL);
}

static void __attribute__((__destructor__)) _BN_CTX_dtor(void)
{
	BN_free(bn);
	BN_CTX_free(ctx);
}

int is_prime_openssl(uint64_t n)
{
	bn = BN_native2bn((uint8_t *)&n, sizeof(n), bn);

	return (BN_check_prime(bn, ctx, NULL));
}
