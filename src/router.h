#include "httpd.h"
#include <sys/stat.h>
#include <sqlite3.h>
#include "utils.h"
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

extern void route();