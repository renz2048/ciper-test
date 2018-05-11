#ifndef HEADER_APPS_H
#define HEADER_APPS_H

#include <assert.h>

typedef struct options_st {
  const char *name;
  int retval;
  /*
   * - no value
   * n number
   * p positive number
   * u unsigned
   * l long
   * s string
   * < input file
   * > output file
   * f any format
   * F der/pem format
   * E der/pem/engine format identifier
   */
  int valtype;
  const char *helpstr;
} OPTIONS;

char *opt_init(int ac, char **av, const OPTIONS * o);

#endif
