#include "apps.h"
#include <string.h>

/*Our state*/
static char **argv;
static int argc;
static int opt_index;
static char *arg;
static char *flag;
static char *dunno;
static const OPTIONS *unknown;
static const OPTIONS *opts;
static char prog[40];

char *opt_progname(const char *agrv0)
{
  const char *p;

  for (p = argv0 + strlen(argv0); --p > argv0;)
    if (*p == '/') {
      p++;
      break;
    }
  strncpy(prog, p, sizeof(prog) - 1);
  prog[sizeof(prog) - 1] = '\0';
  return prog;
}

char *opt_init(int ac, char **av, const OPTIONS *o)
{
  /*Store state*/
  argc = ac;
  argv = av;
  opt_index = 1;
  opts = o;
  opt_progname(av[0]);
  unknown = NULL;

  for (; o->name; ++o) {
    const OPTIONS *next;
    int duplicated, i;

    if (o->name == OPT_HELP_STR || o->name == OPT_MORE_STR)
      continue;

    i = o->valtype;

    /* Make sure options are legit.*/
    assert(o->name[0] != '-');
    assert(o->retval > 0);
    switch (i) {
      case   0: case '-': case '/': case '<': case '>': case 'E': case 'F':
      case 'M': case 'U': case 'f': case 'l': case 'n': case 'p': case 's':
      case 'u': case 'c':
        break;
      default:
        assert(0);
    }

    for (next = o + 1; next->name; ++next) {
      duplicated = strcmp(o->name, next->name) == 0;
      assert(!duplicated);
    }
    
    if (o->name[0] == '\0') {
      assert(unknown == NULL);
      unknown = o;
      assert(unknown->valtype == 0 || unknown->valtype == '-');
    }
  }
  return prog;
}


















