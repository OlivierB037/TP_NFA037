//
// Created by aperi on 03/12/2022.
//

#include <fstream>
#include "Logger.h"


Logger::Logger() : messages({std::make_pair(WARNING_MESSAGE_TYPE,std::vector<std::string>()),
                     std::make_pair(ERROR_MESSAGE_TYPE,std::vector<std::string>()),
                     std::make_pair(INFO_MESSAGE_TYPE,std::vector<std::string>())}){

}
const Logger* Logger::instance = nullptr;

void Logger::addInfoLog(std::string msg) const {
    std::ofstream fichier {"log.txt",std::ios::app};

    time_t now = time(0);
//    char *time = ctime(&now);
    tm *timeNow = localtime(&now);
    char formatedTime[30];
    sprintf(formatedTime,"%d/%d/%d/ %dH:%dmn:%ds",timeNow->tm_mday,timeNow->tm_mon,
            timeNow->tm_year + 1900,timeNow->tm_hour,timeNow->tm_min,timeNow->tm_sec);
    fichier << "INFO LOG "<<  formatedTime << " : \n\t" << msg << std::endl;
}
const Logger *Logger::getInstance() {
    if (instance == nullptr){
        instance = new Logger();
    }
}

void Logger::newLogSection() const {
    std::ofstream fichier {"log.txt",std::ios::app};
    fichier << std::endl << "------------------------------- NEW LOG ---------------------------------" << std::endl;
}

