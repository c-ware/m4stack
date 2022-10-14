/*
 * @docgen_start
 * @type: project
 * @name: m4stack-example-tree
 * @brief: tree command implemented with m4stack
 *
 * @description
 * @This is an basic example of a tree command, which recursively lists
 * @directories and files. Since its using m4stack, which is a stack
 * @implementation, it is performed using depth-first search.
 * @description
 *
 * @examples
 * @#include <stdio.h>\N
 * @#include <stdlib.h>\N
 * @#include <dirent.h>\N
 * @#include <string.h>\N
 * @#include <sys/stat.h>\N
 * @
 * @#include "m4stack/liberror.h"
 * @
 * @// M4 related junk, like getting m4stack included and\N
 * @// defining data structure properties.\N
 * @\N
 * @\N
 * @\N
 * @
 * @M4STACK_DECLARE(PathStack, char *);
 * @
 * @char *copy_string(const char *string) {
 * @    char *new_string = CWUTILS_NULL;
 * @
 * @    LIBERROR_IS_NULL(string, "string");
 * @
 * @    new_string = malloc(sizeof(char) * strlen(string) + 1);
 * @
 * @    LIBERROR_MALLOC_FAILURE(new_string, "new_string");
 * @
 * @    strncpy(new_string, string, strlen(string) + 1);
 * @
 * @    return new_string;\N
 * @}
 * @
 * @int is_direc(const char *path) {
 * @    struct stat stat_buffer;
 * @    int response = 0;
 * @
 * @    if((response = stat(path, &stat_buffer)) == -1)
 * @        return 0;
 * @
 * @    if((stat_buffer.st_mode & S_IFMT) != S_IFDIR)
 * @        return 0;
 * @
 * @    return 1;\N
 * @}
 * @
 * @int main() {
 * @    int path_buffer_capacity = 128 + 1;
 * @    char *path_buffer = CWUTILS_NULL;
 * @    struct PathStack *directories = CWUTILS_NULL;
 * @
 * @    directories = M4STACK_INIT(directories, PATH);
 * @    path_buffer = malloc(sizeof(char) * 128 + 1);
 * @
 * @    M4STACK_VERIFY(directories);
 * @    LIBERROR_MALLOC_FAILURE(path_buffer, "path_buffer");
 * @    M4STACK_PUSH(directories, copy_string("."), PATH);
 * @
 * @    // Exhaust directories until there are no more
 * @    while(M4STACK_IS_EMPTY(directories) == 0) {
 * @        DIR *directory_ptr = CWUTILS_NULL;
 * @        char *next_directory = CWUTILS_NULL;
 * @        struct dirent *entry = CWUTILS_NULL;
 * @
 * @        // Pop the next directory, load it, and scan its contents.
 * @        // This will separate files, which will be printed to the stdout,
 * @        // and directories, which will be pushed to continue the cycle.
 * @        M4STACK_POP(directories, next_directory, PATH);
 * @        LIBERROR_IS_NULL(next_directory, "next_directory");
 * @  
 * @        // Load the file path into the reused memory buffer, then read it
 * @        // through dirent. This buffer will be reused when making the full
 * @        // paths to new directories to push. But, if the length of the
 * @        // directory name is too big, resize the buffer.
 * @        if(strlen(next_directory) > (path_buffer_capacity - 1)) {
 * @            path_buffer = realloc(path_buffer, sizeof(char) * (strlen(next_directory) + 1));
 * @            path_buffer_capacity = strlen(next_directory) + 1;
 * @
 * @
 * @            LIBERROR_MALLOC_FAILURE(path_buffer, "path_buffer");
 * @        }
 * @
 * @        strncpy(path_buffer, next_directory, strlen(next_directory) + 1);
 * @
 * @        // Scan the directory, pushing new directories, and displaying
 * @        // files.
 * @        directory_ptr = opendir(next_directory);
 * @
 * @        LIBERROR_IS_NULL(directory_ptr, "directory_ptr");
 * @
 * @        // For each directory entry, build the full path to it.
 * @        while((entry = readdir(directory_ptr)) != NULL) {
 * @            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
 * @                continue;
 * @
 * @            if((strlen(entry->d_name) + strlen(next_directory) + 1) > (path_buffer_capacity - 1)) {
 * @                path_buffer = realloc(path_buffer, sizeof(char) * (strlen(entry->d_name) + strlen(next_directory) + 1 + 1));
 * @                path_buffer_capacity = strlen(entry->d_name) + strlen(next_directory) + 1 + 1;
 * @
 * @                LIBERROR_MALLOC_FAILURE(path_buffer, "path_buffer");
 * @            }
 * @
 * @            sprintf(path_buffer, "%s/%s", next_directory, entry->d_name);
 * @
 * @            // Enstack directories
 * @            if(is_direc(path_buffer) == 1) {
 * @                M4STACK_PUSH(directories, copy_string(path_buffer), PATH);
 * @            }
 * @
 * @            printf("%s\n", path_buffer);
 * @        }
 * @
 * @        free(next_directory);
 * @        closedir(directory_ptr);
 * @    }
 * @
 * @    M4STACK_FREE(directories, PATH);
 * @    free(path_buffer);
 * @
 * @    return 0;
 * @}
 * @examples
 *
 * @reference: cware(cware)
 * @reference: m4stack(cware)
 *
 * @docgen_end
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include <sys/stat.h>

#include "m4stack/liberror.h"


/* M4 related junk, like getting m4stack included and
 * defining data structure properties. */


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































    struct PathStack {
        int length;
        int capacity;

        char * *contents;
    }
;

char *copy_string(const char *string) {
    char *new_string = CWUTILS_NULL;

    LIBERROR_IS_NULL(string, "string");

    new_string = malloc(sizeof(char) * strlen(string) + 1);

    LIBERROR_MALLOC_FAILURE(new_string, "new_string");

    strncpy(new_string, string, strlen(string) + 1);

    return new_string;
}

int is_direc(const char *path) {
    struct stat stat_buffer;
    int response = 0;

    if((response = stat(path, &stat_buffer)) == -1)
        return 0;

    if((stat_buffer.st_mode & S_IFMT) != S_IFDIR)
        return 0;

    return 1;
}

int main() {
    int path_buffer_capacity = 128 + 1;
    char *path_buffer = CWUTILS_NULL;
    struct PathStack *directories = CWUTILS_NULL;

    directories = 
	(struct PathStack *) malloc(sizeof(*(directories)));

    LIBERROR_MALLOC_FAILURE((directories), "(directories)");

	(directories)->length = 0;
	(directories)->capacity = 3;
	(directories)->contents = (char * *) malloc(sizeof(char *) * 3);

    LIBERROR_MALLOC_FAILURE((directories)->contents, "(directories)->contents");
    LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity");
    LIBERROR_IS_NEGATIVE((directories)->length, "(directories)->length")
;
    path_buffer = malloc(sizeof(char) * 128 + 1);

    
    LIBERROR_IS_NULL((directories), "(directories)");
    LIBERROR_IS_NULL((directories)->contents, "(directories)->contents");
    LIBERROR_IS_NEGATIVE((directories)->length, "(directories)->length");
    LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity")
;
    LIBERROR_MALLOC_FAILURE(path_buffer, "path_buffer");
    
    
do {
    
    LIBERROR_IS_NULL((directories), "(directories)");
    LIBERROR_IS_NULL((directories)->contents, "(directories)->contents");
    LIBERROR_IS_NEGATIVE((directories)->length, "(directories)->length");
    LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity")
;

	if(((directories)->length) == ((directories)->capacity)) {
		(directories)->contents = (char * *) realloc((directories)->contents, sizeof(char *) * ((directories)->capacity * 2));
		(directories)->capacity = ((directories)->capacity * 2);

        LIBERROR_MALLOC_FAILURE((directories)->contents, "(directories)->contents");
        LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((directories), "(directories)");
    LIBERROR_IS_NULL((directories)->contents, "(directories)->contents");
    LIBERROR_IS_NEGATIVE((directories)->length, "(directories)->length");
    LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity")
;

    (directories)->contents[(directories)->length] = (copy_string("."));
    (directories)->length = ((directories)->length + 1);
;

    /* Exhaust directories until there are no more */
    while((((directories)->length) == 0) == 0) {
        DIR *directory_ptr = CWUTILS_NULL;
        char *next_directory = CWUTILS_NULL;
        struct dirent *entry = CWUTILS_NULL;

        /* Pop the next directory, load it, and scan its contents.
         * This will separate files, which will be printed to the stdout,
         * and directories, which will be pushed to continue the cycle. */
        
    
    LIBERROR_IS_NULL((directories), "(directories)");
    LIBERROR_IS_NULL((directories)->contents, "(directories)->contents");
    LIBERROR_IS_NEGATIVE((directories)->length, "(directories)->length");
    LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity")
;

    /* Cannot pop from an empty array */
#if defined(LIBERROR_ENABLED)
    if((directories)->length == 0) {
       fprintf(LIBERROR_STREAM, "attempt to pop from an empty stack (%s:%i)\n", __FILE__, __LINE__);
        abort();
    }
#endif

    (directories)->length--;
    (next_directory) = (directories)->contents[(directories)->length];
;
        LIBERROR_IS_NULL(next_directory, "next_directory");
  
        /* Load the file path into the reused memory buffer, then read it
         * through dirent. This buffer will be reused when making the full
         * paths to new directories to push. But, if the length of the
         * directory name is too big, resize the buffer. */
        if(strlen(next_directory) > (path_buffer_capacity - 1)) {
            path_buffer = realloc(path_buffer, sizeof(char) * (strlen(next_directory) + 1));
            path_buffer_capacity = strlen(next_directory) + 1;


            LIBERROR_MALLOC_FAILURE(path_buffer, "path_buffer");
        }

        strncpy(path_buffer, next_directory, strlen(next_directory) + 1);

        /* Scan the directory, pushing new directories, and displaying
         * files. */
        directory_ptr = opendir(next_directory);

        LIBERROR_IS_NULL(directory_ptr, "directory_ptr");

        /* For each directory entry, build the full path to it. */
        while((entry = readdir(directory_ptr)) != NULL) {
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            if((strlen(entry->d_name) + strlen(next_directory) + 1) > (path_buffer_capacity - 1)) {
                path_buffer = realloc(path_buffer, sizeof(char) * (strlen(entry->d_name) + strlen(next_directory) + 1 + 1));
                path_buffer_capacity = strlen(entry->d_name) + strlen(next_directory) + 1 + 1;

                LIBERROR_MALLOC_FAILURE(path_buffer, "path_buffer");
            }

            sprintf(path_buffer, "%s/%s", next_directory, entry->d_name);

            /* Enstack directories */
            if(is_direc(path_buffer) == 1) {
                
    
do {
    
    LIBERROR_IS_NULL((directories), "(directories)");
    LIBERROR_IS_NULL((directories)->contents, "(directories)->contents");
    LIBERROR_IS_NEGATIVE((directories)->length, "(directories)->length");
    LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity")
;

	if(((directories)->length) == ((directories)->capacity)) {
		(directories)->contents = (char * *) realloc((directories)->contents, sizeof(char *) * ((directories)->capacity * 2));
		(directories)->capacity = ((directories)->capacity * 2);

        LIBERROR_MALLOC_FAILURE((directories)->contents, "(directories)->contents");
        LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity");
	}
} while(0)
;

    
    LIBERROR_IS_NULL((directories), "(directories)");
    LIBERROR_IS_NULL((directories)->contents, "(directories)->contents");
    LIBERROR_IS_NEGATIVE((directories)->length, "(directories)->length");
    LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity")
;

    (directories)->contents[(directories)->length] = (copy_string(path_buffer));
    (directories)->length = ((directories)->length + 1);
;
            }

            printf("%s\n", path_buffer);
        }

        free(next_directory);
        closedir(directory_ptr);
    }

    
    
    LIBERROR_IS_NULL((directories), "(directories)");
    LIBERROR_IS_NULL((directories)->contents, "(directories)->contents");
    LIBERROR_IS_NEGATIVE((directories)->length, "(directories)->length");
    LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity")
;

	do {
		int __M4_INDEX = 0;

		while(__M4_INDEX < (directories)->length) {
            LIBERROR_IS_OOB(__M4_INDEX, (directories)->length);

			free((directories)->contents[__M4_INDEX]);

			__M4_INDEX++;
		}

        
    LIBERROR_IS_NULL((directories), "(directories)");
    LIBERROR_IS_NULL((directories)->contents, "(directories)->contents");
    LIBERROR_IS_NEGATIVE((directories)->length, "(directories)->length");
    LIBERROR_IS_NEGATIVE((directories)->capacity, "(directories)->capacity")
;

		free((directories)->contents);
		free((directories));
	} while(0)
;
    free(path_buffer);

    return 0;
}
