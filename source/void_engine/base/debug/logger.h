#pragma once

#include <iostream>
#include <string>

namespace void_engine {
namespace debug {
    class Logger {
    public:
        static void info(const char* message, const char* file_name, int code_line, const char* function_name);
        static void warning(const char* message, const char* file_name, int code_line, const char* function_name);
        static void error(const char* message, const char* file_name, int code_line, const char* function_name);
        static void config(const char* message, const char* file_name, int code_line, const char* function_name);

        static void info(const std::string& message, const char* file_name, int code_line, const char* function_name);
        static void warning(const std::string& message, const char* file_name, int code_line, const char* function_name);
        static void error(const std::string& message, const char* file_name, int code_line, const char* function_name);
        static void config(const std::string& message, const char* file_name, int code_line, const char* function_name);
    };
}

#ifdef _DEBUG
#define LOGINFO(message) debug::Logger::info(message, __FILE__, __LINE__, __FUNCTION__)
#define LOGWARN(message) debug::Logger::warning(message, __FILE__, __LINE__, __FUNCTION__)
#define LOGERROR(message) debug::Logger::error(message, __FILE__, __LINE__, __FUNCTION__)
#define LOGCONFIG(message) debug::Logger::config(message, __FILE__, __LINE__, __FUNCTION__)
#else
#define LOGINFO(message)
#define LOGWARN(message)
#define LOGERROR(message)
#define LOGCONFIG(message)
#endif // !_DEBUG
}
