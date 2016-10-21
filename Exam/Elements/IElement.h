//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_ELEMENT_H
#define EXAM_ELEMENT_H

#include "Elements.h"

namespace pokemonGame
{
    class IElement
    {
    public:
        IElement() = default;

        virtual ~IElement() = default;

        virtual Elements getElement() = 0;

        virtual Elements getWeakness() = 0;

        virtual Elements getSuper() = 0;

        bool operator==(IElement &other) const
        {
            if (this->elements_ == other.elements_)
                return true;
            return false;
        }

        bool isSuperEffective(IElement *e)
        {
            return (e->getElement() == this->getSuper());
        }

        bool isNotEffective(IElement *e)
        {
            return (e->getElement() == this->getWeakness());
        }

    private:
        Elements elements_;
    };
}
#endif //EXAM_ELEMENT_H
