// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	syscall(__NR_ftruncate, (unsigned int) fd, (unsigned long) length, 0, 0, 0, 0);
	return 0;
}
