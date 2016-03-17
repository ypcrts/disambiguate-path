#define DELIM "/"
#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv, char **envp)
{
  char *home, *home_tok, *home_sp;
  char *cwd, *tok, *cwd_sp;
  char *did, *did_p;
  int i, bytes;
  bool done_home = false;

  cwd = get_current_dir_name();
  did_p = did = calloc(1, sizeof (*cwd) );
  tok = strtok_r(cwd, DELIM, &cwd_sp);

  home = getenv("HOME");
  home_tok = strtok_r(home, DELIM, &home_sp);

  for (;; ) {
    tok = strtok_r(NULL, DELIM, &cwd_sp);
    if (tok == NULL) {
      break;
    }

    if (!done_home) {
      home_tok = strtok_r(NULL, DELIM, &home_sp);
      if (home_tok == NULL) {
        bytes = sprintf(did_p, "~");
        did_p = did_p + bytes;
        done_home = true;
      }
      else if (strcmp(tok, home_tok) == 0) {
        continue;
      }
      else {
        done_home = true;
      }
    }
    bytes = sprintf(did_p, "/");
    did_p = did_p + bytes;
    bytes = sprintf(did_p, tok);
    did_p = did_p + bytes;
  }
  printf(did);

  /* free(did);
   * free(home);
   * free(cwd); */
}
