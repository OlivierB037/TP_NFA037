//
// Created by aperi on 05/12/2022.
//

#ifndef TP_NFA037_LABYRINTH_EXCEPTION_H
#define TP_NFA037_LABYRINTH_EXCEPTION_H
#include <string>
#include <utility>
#include <stdexcept>

class Labyrinth_Exception : public std::logic_error {
public:

    explicit Labyrinth_Exception(const char *_cause) : logic_error(_cause){}




};


#endif //TP_NFA037_LABYRINTH_EXCEPTION_H
