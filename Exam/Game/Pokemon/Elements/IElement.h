//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_ELEMENT_H
#define EXAM_ELEMENT_H

#include <boost/shared_ptr.hpp>
#include "Elements.h"

namespace pokemonGame
{
    class IElement
    {
    public:
        IElement() = default;

        virtual ~IElement() = default;

        Elements getElement();

        Elements getWeakness();

        Elements getSuper();

        bool operator==(IElement &other) const
        {
            if (this->elementType_ == other.elementType_)
                return true;
            return false;
        }

        bool isSuperEffective(std::shared_ptr<IElement> e);

        bool isNotEffective(std::shared_ptr<IElement> e);


    protected:
        Elements elementType_;
        Elements weakness_;
        Elements super_;


    };
}
#endif //EXAM_ELEMENT_H
