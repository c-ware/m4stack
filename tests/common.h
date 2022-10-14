#ifndef COMMON_H
#define COMMON_H

#include <assert.h>
#include <string.h>

/* QBSD does not have these headers (and rather, has the
 * functions declared in it be implicitly called..) */
#if !defined(__QuasiBSD__)
#include <stdlib.h>
#endif

#define LIBERROR_STREAM stderr
#define LIBERROR_ENABLED

#include "../src/liberror.h"
#include "libassert.h"

#endif
