//
// Created by ubuntuudvikling on 10/19/16.
//

#ifndef EXAM_NOFAVORITEPOKEMONEXCEPTION_H
#define EXAM_NOFAVORITEPOKEMONEXCEPTION_H
#include <iostream>

class NoFavoritePokemonException  : public std::exception{

public:
    NoFavoritePokemonException(const char *msg) : err_msg(msg) {};
    ~NoFavoritePokemonException() throw() {};
    const char *what() const throw() { return this->err_msg.c_str(); };
private:
    std::string err_msg;


};


#endif //EXAM_NOFAVORITEPOKEMONEXCEPTION_H
