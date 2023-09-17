/*
 * Copyright (C) Ondřej Surý
 * SPDX-FileCopyrightText: Ondřej Surý
 *
 * SPDX-License-Identifier: WTFPL
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "valec.h"

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Usage: %s <r> <v>\n", argv[0]);
		return 1;
	}

	int r = atol(argv[1]);
	int v = atol(argv[2]);

	double V = OBJEM_VALCE(r, v);

	printf("Objem valce(r = %d, v = %d) => %.2f\n", r, v, V);

	return 0;
}
