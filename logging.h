#ifndef LOGGING_H_
#define LOGGING_H_

#include <string.h>

#include <ostream>
#include <sstream>
#include <string>

enum LogSeverity {
  DEBUG,
  INFO,
  ERROR,
  FATAL,
};

#define LOG(Severity) LogMessage(__FILE__, __LINE__, Severity).stream()

#define PLOG(Severity) LOG(Severity) << "(errno = " << strerror(errno) << ") "

#define CHECK(Expr) \
  if (!(Expr)) LOG(FATAL) << "Check failed: " #Expr << " "

#define CHECK_EQ(Expected, Actual) \
  if ((Expected) != (Actual)) \
    LOG(FATAL) << "Check failed: " #Expected << " == " << #Actual \
               << " (" #Expected "=" << (Expected) << ", " #Actual "=" \
               << (Actual) << ") "

class LogMessage {
 public:
  LogMessage(const char* file, unsigned int line, LogSeverity severity)
      : file_(file), line_(line), severity_(severity) {
  }

  ~LogMessage();

  std::ostream& stream() {
    return buffer_;
  }

 private:
  std::ostringstream buffer_;
  const char* const file_;
  const unsigned int line_;
  const LogSeverity severity_;

  LogMessage(const LogMessage&) = delete;
  LogMessage& operator=(const LogMessage&) = delete;
};

#endif  // LOGGING_H_
