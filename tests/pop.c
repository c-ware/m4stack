/*
 * Test of the pop operation
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










void test_pop() {
    char *a = (char *) malloc(16);
    char *b = (char *) malloc(16);
    char *c = (char *) malloc(16);
    char *d = (char *) malloc(16);
    char *output = CWUTILS_NULL;
    struct StringStack *my_stack = 
	(struct StringStack *) malloc(sizeof(*(my_stack)));

    LIBERROR_MALLOC_FAILURE((my_stack), "(my_stack)");

	(my_stack)->length = 0;
	(my_stack)->capacity = 3;
	(my_stack)->contents = (char * *) malloc(sizeof(char *) * 3);

    LIBERROR_MALLOC_FAILURE((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length")
;

    strcpy(a, "foo");
    strcpy(b, "bar");
    strcpy(c, "baz");
    strcpy(d, "tuna");

    
    
do {
    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

	if(((my_stack)->length) == ((my_stack)->capacity)) {
		(my_stack)->contents = (char * *) realloc((my_stack)->contents, sizeof(char *) * ((my_stack)->capacity * 2));
		(my_stack)->capacity = ((my_stack)->capacity * 2);

        LIBERROR_MALLOC_FAILURE((my_stack)->contents, "(my_stack)->contents");
        LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

    (my_stack)->contents[(my_stack)->length] = (a);
    (my_stack)->length = ((my_stack)->length + 1);
;
    
    
do {
    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

	if(((my_stack)->length) == ((my_stack)->capacity)) {
		(my_stack)->contents = (char * *) realloc((my_stack)->contents, sizeof(char *) * ((my_stack)->capacity * 2));
		(my_stack)->capacity = ((my_stack)->capacity * 2);

        LIBERROR_MALLOC_FAILURE((my_stack)->contents, "(my_stack)->contents");
        LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

    (my_stack)->contents[(my_stack)->length] = (b);
    (my_stack)->length = ((my_stack)->length + 1);
;
    
    
do {
    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

	if(((my_stack)->length) == ((my_stack)->capacity)) {
		(my_stack)->contents = (char * *) realloc((my_stack)->contents, sizeof(char *) * ((my_stack)->capacity * 2));
		(my_stack)->capacity = ((my_stack)->capacity * 2);

        LIBERROR_MALLOC_FAILURE((my_stack)->contents, "(my_stack)->contents");
        LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

    (my_stack)->contents[(my_stack)->length] = (c);
    (my_stack)->length = ((my_stack)->length + 1);
;
    
    
do {
    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

	if(((my_stack)->length) == ((my_stack)->capacity)) {
		(my_stack)->contents = (char * *) realloc((my_stack)->contents, sizeof(char *) * ((my_stack)->capacity * 2));
		(my_stack)->capacity = ((my_stack)->capacity * 2);

        LIBERROR_MALLOC_FAILURE((my_stack)->contents, "(my_stack)->contents");
        LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

    (my_stack)->contents[(my_stack)->length] = (d);
    (my_stack)->length = ((my_stack)->length + 1);
;

    
    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

    /* Cannot pop from an empty array */
#if defined(LIBERROR_ENABLED)
    if((my_stack)->length == 0) {
       fprintf(LIBERROR_STREAM, "attempt to pop from an empty stack (%s:%i)\n", __FILE__, __LINE__);
        abort();
    }
#endif

    (my_stack)->length--;
    (output) = (my_stack)->contents[(my_stack)->length];
;
    ASSERT_NUMEQ(my_stack->length, 3);
    ASSERT_NUMEQ(my_stack->capacity, 3 * 2);
    ASSERT_STREQ(output, "tuna");
    ASSERT_STREQ(my_stack->contents[0], "foo");
    ASSERT_STREQ(my_stack->contents[1], "bar");
    ASSERT_STREQ(my_stack->contents[2], "baz");

    
    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

    /* Cannot pop from an empty array */
#if defined(LIBERROR_ENABLED)
    if((my_stack)->length == 0) {
       fprintf(LIBERROR_STREAM, "attempt to pop from an empty stack (%s:%i)\n", __FILE__, __LINE__);
        abort();
    }
#endif

    (my_stack)->length--;
    (output) = (my_stack)->contents[(my_stack)->length];
;
    ASSERT_NUMEQ(my_stack->length, 2);
    ASSERT_NUMEQ(my_stack->capacity, 3 * 2);
    ASSERT_STREQ(output, "baz");
    ASSERT_STREQ(my_stack->contents[0], "foo");
    ASSERT_STREQ(my_stack->contents[1], "bar");

    
    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

    /* Cannot pop from an empty array */
#if defined(LIBERROR_ENABLED)
    if((my_stack)->length == 0) {
       fprintf(LIBERROR_STREAM, "attempt to pop from an empty stack (%s:%i)\n", __FILE__, __LINE__);
        abort();
    }
#endif

    (my_stack)->length--;
    (output) = (my_stack)->contents[(my_stack)->length];
;
    ASSERT_NUMEQ(my_stack->length, 1);
    ASSERT_NUMEQ(my_stack->capacity, 3 * 2);
    ASSERT_STREQ(output, "bar");
    ASSERT_STREQ(my_stack->contents[0], "foo");

    
    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

    /* Cannot pop from an empty array */
#if defined(LIBERROR_ENABLED)
    if((my_stack)->length == 0) {
       fprintf(LIBERROR_STREAM, "attempt to pop from an empty stack (%s:%i)\n", __FILE__, __LINE__);
        abort();
    }
#endif

    (my_stack)->length--;
    (output) = (my_stack)->contents[(my_stack)->length];
;
    ASSERT_NUMEQ(my_stack->length, 0);
    ASSERT_NUMEQ(my_stack->capacity, 3 * 2);
    ASSERT_STREQ(output, "foo");

    
    
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (my_stack)->length) {
            LIBERROR_IS_OOB(__M4_INDEX, (my_stack)->length);

			free((my_stack)->contents[__M4_INDEX]);

			__M4_INDEX++;
		}

        
    LIBERROR_IS_NULL((my_stack), "(my_stack)");
    LIBERROR_IS_NULL((my_stack)->contents, "(my_stack)->contents");
    LIBERROR_IS_NEGATIVE((my_stack)->length, "(my_stack)->length");
    LIBERROR_IS_NEGATIVE((my_stack)->capacity, "(my_stack)->capacity")
;

		free((my_stack)->contents);
		free((my_stack));
	} while(0)
;
}

int main() {
    test_pop(); 

    return 0;
}
