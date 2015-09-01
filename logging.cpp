#include "logging.h"

#include <stdio.h>
#include <stdlib.h>

static const char* log_severity_names[] = {
    "DEBUG", "INFO", "ERROR", "FATAL",
};

LogMessage::~LogMessage() {
  fprintf(stderr, "<%s>%s(%u): %s\n", log_severity_names[severity_],
          file_, line_, buffer_.str().c_str());
  if (severity_ == FATAL) {
    exit(1);
  }
}
