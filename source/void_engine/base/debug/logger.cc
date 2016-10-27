#include "logger.h"

#include <void_engine/base/helper/define.h>

#ifdef WINDOWS_OS
#include <iostream>
#include "Windows.h"
#endif

namespace void_engine {
namespace debug {
#ifdef WINDOWS_OS
    void logger_print_message(const char* message, const char* file_name, int code_line, const char* function_name, int color) {
        HANDLE console_handler = GetStdHandle(STD_OUTPUT_HANDLE);

        std::string file_name_str = file_name;
        file_name_str = file_name_str.substr(file_name_str.find_last_of("\\") + 1);

        // grey white
        SetConsoleTextAttribute(console_handler, color);
        std::cout << file_name_str << "::" << function_name << "::" << code_line << ": " << message << std::endl;

        // set default color
        SetConsoleTextAttribute(console_handler, 7);
    }

    void Logger::info(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, 15);
    }

    void Logger::warning(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, 14);
    }

    void Logger::error(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, 12);
    }

    void Logger::config(const std::string& message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message.c_str(), file_name, code_line, function_name, 10);
    }

    void Logger::info(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, 15);
    }

    void Logger::warning(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, 14);
    }

    void Logger::error(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, 12);
    }

    void Logger::config(const char* message, const char* file_name, int code_line, const char* function_name) {
        logger_print_message(message, file_name, code_line, function_name, 10);
    }
#endif
}
}