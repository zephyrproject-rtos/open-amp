/*
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Copyright (c) 2024, STMicroelectronics
 *
 */

#include <internal/string.h>

/**
 * @internal
 *
 * @brief Copies a string to a destination buffer with size limitation and returns the length of
 *        the source string.
 *
 * This function copies up to `size - 1` characters from the source string `src`
 * to the destination buffer `dest`, ensuring that the destination buffer is
 * null-terminated. The function returns the length of the source string `src`.
 * If the length of `src` is greater than or equal to `size`, the destination
 * buffer will be truncated.
 *
 * @param dst Destination buffer where the string will be copied.
 * @param src Source string to be copied.
 * @param size Size of the destination buffer.
 * @return The length of the source string `src`.
 *
 * @note If the size of the destination buffer is 0, the function does not copy any characters and
 *       the destination buffer is not null-terminated.
 * @note The function ensures that the destination buffer is always null-terminated if `size` is
 *       greater than 0.
 * @note: this code is inspired from the strlcpy.c file from freeBSD .
 */

size_t
strlcpy(char *dst, const char *src, size_t size)
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
