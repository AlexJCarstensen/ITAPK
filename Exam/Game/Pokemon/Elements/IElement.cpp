//
// Created by stud on 10/21/16.
//

#include "IElement.h"

namespace pokemonGame
{
    Elements IElement::getElement() {return elementType_;}

    Elements IElement::getSuper() {return super_;}

    Elements IElement::getWeakness() {return weakness_;}

    bool IElement::isSuperEffective(std::shared_ptr<IElement> e) {
        return (e->getElement() == this->getSuper());
    }

    bool IElement::isNotEffective(std::shared_ptr<IElement> e) {
        return (e->getElement() == this->getWeakness());
    }


}