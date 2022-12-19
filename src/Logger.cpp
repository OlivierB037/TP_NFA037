//
// Created by aperi on 03/12/2022.
//

#include <fstream>
#include "Logger.h"

#include <cstdarg>

Logger::Logger() : messages({std::make_pair(WARNING_MESSAGE_TYPE,std::vector<std::string>()),
                     std::make_pair(ERROR_MESSAGE_TYPE,std::vector<std::string>()),
                     std::make_pair(INFO_MESSAGE_TYPE,std::vector<std::string>())}){

}
const Logger* Logger::instance = nullptr;

void Logger::addInfoLog(const std::string& msg) const {
    std::ofstream fichier {"log.txt",std::ios::app};

    time_t now = time(0);
    char *time = ctime(&now);
//    tm *timeNow = localtime(&now);
//    char formatedTime[30];
//    sprintf(formatedTime,"%d/%d/%d/ %dH:%dmn:%ds",timeNow->tm_mday,timeNow->tm_mon,
//            timeNow->tm_year + 1900,timeNow->tm_hour,timeNow->tm_min,timeNow->tm_sec);
    fichier << "INFO LOG "<<  time << "\t" << msg << std::endl;
    fichier.close();
}


const Logger *Logger::getInstance() {
    if (instance == nullptr){
        instance = new Logger();
    }
    return instance;
}

void Logger::newLogSection() const {
    std::ofstream fichier {"log.txt",std::ios::app};
    fichier << std::endl << "------------------------------- NEW LOG ---------------------------------" << std::endl;
    fichier.close();
}
//TODO regler problème args multiples
void Logger::addInfoLog(char *format, ...) const {
    va_list list;
    va_start(list, format);
    char* msg = new char[90];

    int i = 0, j=0;
    std::ofstream fichier {"log.txt",std::ios::app};
    while(format[i] != '\0' && j < 90){
        if (format[i] == '%') {
            i++;

            if (format[i] == 'c'){

                char c = va_arg(list,int);
                msg[j] = c;
                //printf("getting char = %c\n",c);
                //printf("%c", (char)c);
                i++;
                j++;
            }
            else if(format[i] == 's'){
                char *s = va_arg(list,char*);
                int k = 0;
                while(s[k] != '\n'){
                    msg[j] = s[k];
                    k++;
                    j++;
                }
                //printf("getting string = %s\n",s);

                i++;
            }
            else if(format[i] == 'd'){
                int k = 0;
                int l = va_arg(list,int );
                char chars[9]{'\n'};
                sprintf(chars,"%d",l);
                while(chars[k] != '\n'&& k < 9){
                    msg[j] = chars[k];
                    k++;
                    j++;
                }
                //printf("getting int = %d\n",j);

                i++;
            }

            else if(format[i] == 'f'){
                double f = va_arg(list,double );
                char chars[9]{'\n'};
                int k = 0;
                //printf("getting float = %f\n",f);
                sprintf(chars,"%.3f",f);
                while(chars[k] != '\n' && k < 9){
                    msg[j] = chars[k];
                    k++;
                    j++;
                }
                i++;

            }
            else if(format[i] == 'p'){
                void* ptr = va_arg(list,void*);
                char chars[10]{'\n'};
                int k = 0;
                //printf("getting float = %f\n",f);
                sprintf(chars,"%p",ptr);
                while(chars[k] != '\n' && k < 10){
                    msg[j] = chars[k];
                    k++;
                    j++;
                }
                i++;
            }

            else if(format[i] == '.'&& isdigit(format[i+1])&& format[i+2] == 'f'){
                i++;
                int k = 0;
                char str[5]={'%','.',format[i],'f','\0'};

                double f = va_arg(list,double );
                printf(str,f);
                i+=2;

            }
            else{
                msg[j] = format[i-1];
                j++;
//                i++;
            }
        } else{
            msg[j] = format[i];
            i++;
            j++;
        }


    }
    msg[j] = '\0';
    std::string str(msg);
    addInfoLog(str);
}

