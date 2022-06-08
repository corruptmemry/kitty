#include "httpd.h"
#include "utils.h"

int main(int c, char **v) {
  char *port = c == 1 ? "8000" : v[1];
  init_db();
  
  serve_forever(port);
  return 0;
}