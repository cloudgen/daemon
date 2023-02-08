#include <stdio.h>
#include <string.h>
#include "singleton.h"
#include "daemon-info.h"
#include "log-message.h"
#include "main-loop.h"
#include "make-directory.h"
#include "remove-old-log.h"
#include "run-detached.h"

void handle_exit(int sig) {
  unlink(PID_FILE);
  log_message("Terminated");
  exit(0);
}

int main(int argc, char *argv[]) {

  check_singleton();
  if (make_directory(LOG_DIR) != 0) {
    fprintf(stderr, "Error creating directory\n");
    return 1;
  }

  if (argc > 1 && strcmp(argv[1], "-d") == 0) {
    printf("Daemon mode\n");
    run_detached();
  }
  create_pid_file();
  signal(SIGINT, handle_exit);
  signal(SIGTERM, handle_exit);
  log_message("Started");
  main_loop();  
  return 0;
}
