/*
 * SPDX-FileCopyrightText: Ondřej Surý, P23010
 *
 * SPDX-License-Identifier: WTFPL
 */

#pragma once

#include <limits.h>

extern char *toupper_map;

#define UP(c)                                                                  \
	(((int)(c) < CHAR_MIN || (int)(c) > UCHAR_MAX) ? c : toupper_map[c])
