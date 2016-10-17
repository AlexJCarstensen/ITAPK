//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_ELEMENT_H
#define EXAM_ELEMENT_H
namespace pokemonGame {


   enum Elements
    {
        FIRE,
        LIGHTNING,
        GRASS,
        WATER,
        GROUND

    };

   class Element
   {
   public:
        Element(){};
        virtual ~Element(){};
        virtual Elements getElement() = 0;
        virtual Elements getWeakness() = 0;
        virtual Elements getSuper() = 0;

       bool operator==(Element& other)const {
           if (this->elements_ == other.elements_)
               return true;
           return false;
       }
       bool isSuperEffective(Element* e)
       {
           return (e->getElement() == this->getSuper());
       }
       bool isNotEffective(Element* e)
       {
           return (e->getElement() == this->getWeakness());
       }

   private:
       Elements elements_;
   };

    class Fire : public Element
    {
    public:
        Fire() {};
        ~Fire(){};
        Elements getElement(){return  elements_;}
        Elements getWeakness(){return weakness_;}
        Elements getSuper() {return super_;}

    private:
        Elements elements_{Elements::FIRE};
        Elements weakness_{Elements::WATER};
        Elements super_{Elements::GRASS};

    };

    class Water : public Element
    {
    public:
        Water() {};
          ~Water(){};
        Elements getElement(){ return  elements_;}
        Elements getWeakness(){return weakness_;}
        Elements getSuper() {return super_;}
    private:
        Elements elements_{Elements::WATER};
        Elements weakness_{Elements::LIGHTNING};
        Elements super_{Elements::GROUND};

    };

    class Lightning : public Element
    {
    public:
        Lightning() {};
          ~Lightning(){};
        Elements getElement(){ return  elements_;}
        Elements getWeakness(){return weakness_;}
        Elements getSuper() {return super_;}

    private:
        Elements elements_{Elements::LIGHTNING};
        Elements weakness_{Elements::GROUND};
        Elements super_{Elements::WATER};

    };

    class Ground : public Element
    {
    public:
        Ground() {};
          ~Ground(){};
        Elements getElement(){ return  elements_;}
        Elements getWeakness(){return weakness_;}
        Elements getSuper() {return super_;}
    private:
        Elements elements_{Elements::GROUND};
        Elements weakness_{Elements::WATER};
        Elements super_{Elements::LIGHTNING};

    };

    class Grass : public Element
    {
    public:
        Grass() {};
          ~Grass(){};
        Elements getElement(){ return  elements_;}
        Elements getWeakness(){return weakness_;}
        Elements getSuper() {return super_;}
    private:
        Elements elements_{Elements::GRASS};
        Elements weakness_{Elements::FIRE};
        Elements super_{Elements::WATER};

    };



}
#endif //EXAM_ELEMENT_H
