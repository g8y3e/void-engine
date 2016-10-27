#pragma once

#include <string>
#include <exception>
#include <stdexcept>

namespace void_engine {
    class VoidRuntimeException : public std::runtime_error {
    public:
        VoidRuntimeException(const char* message)
            : std::runtime_error(message) {
        }

        VoidRuntimeException(const std::string& message)
            : std::runtime_error(message.c_str()) {
        }

        ~VoidRuntimeException() {
        }
    };
}