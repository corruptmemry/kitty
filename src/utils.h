#include <sys/stat.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#define CHUNK_SIZE 1024

extern sqlite3 *db;
extern char *buffer[256];
extern char* rand_string_alloc(size_t size);
extern char* get_long_url(char* shortUrl);
extern char *insert_new_url(char* longUrl);
extern int init_db();
extern char* parseQuery(char qs[]);
extern int file_exists(const char *file_name);
extern int read_file(const char *file_name);
extern int startsWith(const char *a, const char *b);