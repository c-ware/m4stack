/*
 * Testing of the initialization operation.
*/

#include "common.h"



#include <stdio.h>
#include <assert.h>
#include <string.h>


#if defined(__ULTRIX__) || defined(__QuasiBSD__)
#   if !defined(CWUTILS_GENERIC)
#       define CWUTILS_GENERIC char *
#   endif
#   if !defined(CWUTILS_NULL)
#       define CWUTILS_NULL    ((char *) 0)
#   endif
#else
#   if !defined(CWUTILS_GENERIC)
#      define CWUTILS_GENERIC void *
#   endif
#   if !defined(CWUTILS_NULL)
#      define CWUTILS_NULL    ((void *) 0)
#   endif
#endif




























    struct IntStack {
        int length;
        int capacity;

        int *contents;
    }
;

    struct StringStack {
        int length;
        int capacity;

        char * *contents;
    }
;










/* Test the state of the initialized stack */
void test_init_state() {
    struct StringStack *stack = (struct StringStack *) CWUTILS_NULL;

    stack = 
	(struct StringStack *) malloc(sizeof(*(stack)));

    LIBERROR_MALLOC_FAILURE((stack), "(stack)");

	(stack)->length = 0;
	(stack)->capacity = 3;
	(stack)->contents = (char * *) malloc(sizeof(char *) * 3);

    LIBERROR_MALLOC_FAILURE((stack)->contents, "(stack)->contents");
    LIBERROR_IS_NEGATIVE((stack)->capacity, "(stack)->capacity");
    LIBERROR_IS_NEGATIVE((stack)->length, "(stack)->length")
;

    ASSERT_PTRNEQ(stack, CWUTILS_NULL);
    ASSERT_PTRNEQ(stack->contents, CWUTILS_NULL);
    ASSERT_NUMEQ(stack->length, 0);
    ASSERT_NUMEQ(stack->capacity, 3);

    
    
    LIBERROR_IS_NULL((stack), "(stack)");
    LIBERROR_IS_NULL((stack)->contents, "(stack)->contents");
    LIBERROR_IS_NEGATIVE((stack)->length, "(stack)->length");
    LIBERROR_IS_NEGATIVE((stack)->capacity, "(stack)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (stack)->length) {
            LIBERROR_IS_OOB(__M4_INDEX, (stack)->length);

			free((stack)->contents[__M4_INDEX]);

			__M4_INDEX++;
		}

        
    LIBERROR_IS_NULL((stack), "(stack)");
    LIBERROR_IS_NULL((stack)->contents, "(stack)->contents");
    LIBERROR_IS_NEGATIVE((stack)->length, "(stack)->length");
    LIBERROR_IS_NEGATIVE((stack)->capacity, "(stack)->capacity")
;

		free((stack)->contents);
		free((stack));
	} while(0)
;
}

int main() {
    test_init_state();

    return 0;
}
