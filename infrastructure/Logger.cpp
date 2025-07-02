#include "Logger.h"

namespace tradebot {
	
Logger::Logger(const std::string& filename, bool toConsole)
    : file_(filename, std::ios::app), toConsole_(toConsole) {
    // Создать папку logs, если нет
    std::filesystem::create_directories("logs");
}

Logger::~Logger() { flush(); }

void Logger::flush() {
    std::string msg = stream_.str();
    file_ << msg;
    file_.flush();
    if (toConsole_) std::cout << msg;
    stream_.str("");
    stream_.clear();
}

// Глобальный синглтон
Logger& LOGGER() {
    static Logger logger("logs/bot.log", false); // false — только в файл, true — и в консоль
    return logger;
}

} // namespace tradebot