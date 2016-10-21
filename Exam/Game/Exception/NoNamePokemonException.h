//
// Created by ubuntuudvikling on 10/21/16.
//

#ifndef EXAM_NONAMEPOKEMONEXCEPTION_H
#define EXAM_NONAMEPOKEMONEXCEPTION_H

#include <iostream>

namespace pokemonGame
{
    class NoNamePokemonException : public std::exception
    {

    public:
        NoNamePokemonException(const char *msg) : err_msg(msg) {};

        ~NoNamePokemonException() throw() {};

        const char *what() const throw() { return this->err_msg.c_str(); };
    private:
        std::string err_msg;
    };
}
#endif //EXAM_NONAMEPOKEMONEXCEPTION_H
