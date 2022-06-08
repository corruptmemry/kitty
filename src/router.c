#include "router.h"

#define PUBLIC_DIR "./public"
#define INDEX_HTML "/index.html"
#define NOT_FOUND_HTML "/404.html"
#define ROBOTS_FILE "/robots.txt"

void route() {
  ROUTE_START()

  GET("/") {
    char index_html[20];
    sprintf(index_html, "%s%s", PUBLIC_DIR, INDEX_HTML);

    HTTP_200;
    read_file(index_html);
  }

  GET("/robots.txt") {
    char file_name[20];
    sprintf(file_name, "%s%s", PUBLIC_DIR, ROBOTS_FILE);

    HTTP_200;
    read_file(file_name);
  }

  ROUTE_END();
}
