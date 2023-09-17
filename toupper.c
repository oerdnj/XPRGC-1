/*
 * Copyright (C) Ondřej Surý
 * SPDX-FileCopyrightText: Ondřej Surý
 *
 * SPDX-License-Identifier: WTFPL
 */

#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "toupper.h"

static char toupper_map0[UCHAR_MAX + -CHAR_MIN];
char *toupper_map = toupper_map0 + -CHAR_MIN;

static void __attribute__((__constructor__)) toupper_init(void)
{
	for (int i = CHAR_MIN; i <= UCHAR_MAX; i++) {
		unsigned char c = i;
		toupper_map[i] = (c >= 'a' && c <= 'z') ? c &= ~0x20 : c;
	}
}

static void ups(char *str, size_t size)
{
	for (size_t i = 0; i < size; i++) {
		str[i] = UP(str[i]);
	}
}

int main(int argc, char **argv)
{
	int pos = 1;

	for (int pos = 1; pos < argc; pos++) {
		printf("%s => ", argv[pos]);
		ups(argv[pos], strlen(argv[pos]));
		printf("%s\n", argv[pos]);
	}

	return 0;
}
