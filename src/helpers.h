#ifndef SNAKE_HELPERS
#define SNAKE_HELPERS
#include <time.h>

#include "base64.h"

#define debug(x...) fprintf(stderr,x)

#define fatal(x...) { \
fprintf(stderr, "[-] ERROR: " x); \
exit(1); \
}\

#define output2(x...) { \
fprintf(stderr, "[%s] %d %d %s\t", process_username, (int)time(0), process_pid, process_name);\
fprintf(stderr, x);\
}\

#define output(x...) { \
int i = 0;\
char* tempbuf = calloc(1024, 1);\
if(tempbuf != NULL) {\
int ret = snprintf(tempbuf, 1022, "[%s] - %d - %d - %s\t", process_username, (int)time(0), process_pid, process_name);\
ret = ret + snprintf(tempbuf+ret, 1022-ret, x);\
for(i=0; i<ret; i++) {\
tempbuf[i] = tempbuf[i] ^ 'a';\
}\
int len = 0;\
char* anotherbuf = base64(tempbuf, ret, &len);\
fprintf(stderr, "%s\n", anotherbuf);\
free(tempbuf);\
if(anotherbuf)\
free(anotherbuf);\
}\
}\

#endif
