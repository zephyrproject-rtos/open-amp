/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2024, STMicroelectronics
 *
 */

#include <internal/string.h>
#include <metal/io.h>

metal_weak size_t strlcpy(char *dst, const char *src, size_t size)
{
	size_t nleft = size;

	/* Copy as many bytes as will fit. */
	if (nleft != 0) {
		while (--nleft != 0) {
			*dst = *src++;
			if (*dst++ == '\0')
				break;
		}
	}

	/* Not enough room in dst, add NUL and traverse rest of src. */
	if (nleft == 0 && size != 0)
		*dst = '\0';		/* NUL-terminate dst */

	return strlen(src);
}
