// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */

	mode_t mode = 0;

	if(flags & (O_CREAT | O_TMPFILE)) {
		va_list args;

		va_start(args, flags);
		mode = va_arg(args, mode_t);
		va_end(args);
	}

	long ret = syscall(__NR_open, (long)filename, (long)flags, (long)mode, 0, 0, 0);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return (int)ret;
}
