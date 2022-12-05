//
// Created by aperi on 03/12/2022.
//

#ifndef TP_01_LOGGER_H
#define TP_01_LOGGER_H
#define INFO_MESSAGE_TYPE 3737
#define ERROR_MESSAGE_TYPE 3437
#define WARNING_MESSAGE_TYPE 3748
#include <iostream>
#include <vector>
#include <map>

class Logger {
protected:
    std::map<int,std::vector<std::string>> messages;
    Logger();
    const static Logger *instance;

public:
    Logger(Logger &copy) = delete;
    void operator=(const Logger &) = delete;
    static const Logger  * getInstance();
    void addInfoLog(std::string msg) const;
    void newLogSection() const;
private:






};


#endif //TP_01_LOGGER_H
