#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <filesystem>

namespace tradebot {

class Logger {
public:
    Logger(const std::string& filename, bool toConsole = false);
    ~Logger();

    template<typename T>
    Logger& operator<<(const T& value) {
        stream_ << value;
        return *this;
    }

    Logger& operator<<(std::ostream& (*manip)(std::ostream&)) {
        stream_ << manip;
        flush();
        return *this;
    }

    void flush();

private:
    std::ofstream file_;
    std::ostringstream stream_;
    bool toConsole_;
};

// Глобальный доступ к логгеру
Logger& LOGGER();

} // namespace tradebot