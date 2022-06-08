#include "utils.h"

sqlite3 *db;

static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % 52;
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

char* rand_string_alloc(size_t size)
{
     char *s = malloc(size + 1);
     if (s) {
         rand_string(s, size);
     }
     return s;
}

int init_db(){
  char *err = 0;
  if(sqlite3_open("db/urls.db", &db) )
    fprintf(stderr, "SQLite error: %s\n", sqlite3_errmsg(db));
 // sqlite3_close(db);
}

char* parseQuery(char qs[]){
    char *query = strdup(qs),
        *tokens = query,
        *p = query;

    while ((p = strsep (&tokens, "&\n"))) {
        char *var = strtok (p, "="),
             *val = NULL;
        if (var && (val = strtok (NULL, "="))){
            return val;
        }
        else
            continue;
    }

    free (query);
    return 0;
}

int file_exists(const char *file_name) {
  struct stat buffer;
  int 
  exists = (stat(file_name, &buffer) == 0);

  return exists;
}

int read_file(const char *file_name) {
  char buf[CHUNK_SIZE];
  FILE *file;
  size_t nread;
  int err = 1;

  file = fopen(file_name, "r");

  if (file) {
    while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
      fwrite(buf, 1, nread, stdout);

    err = ferror(file);
    fclose(file);
  }
  return err;
}

int startsWith(const char *a, const char *b)
{
   if(strncmp(a, b, strlen(b)) == 0) return 1;
   return 0;
}