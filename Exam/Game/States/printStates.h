//
// Created by plex on 10/17/16.
//

#ifndef EXAM_MACRO_H
#define EXAM_MACRO_H
namespace pokemonGame
{

    class printStates
    {
    public:
        static void print(unsigned int lvl, const std::string &name)
        {
            for (unsigned int i = 0; i < lvl; i++)
                std::cout << "*" << std::flush;
            std::cout << " " << name << std::endl;
        }
    };
}

#endif //EXAM_MACRO_H
