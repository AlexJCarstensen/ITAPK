//
// Created by ubuntuudvikling on 10/10/16.
//

#ifndef EXAM_ELEMENT_H
#define EXAM_ELEMENT_H
namespace pokemonGame {


    enum Elements
    {
        eFire,
        eLightning,
        eGrass,
        eWater,
        eGround

    };

   class Element
   {
   public:
        Element(){};
        virtual ~Element(){};
        virtual Elements getElement() = 0;
   private:
       Elements elements_;

   };

    class Fire : public Element
    {
    public:
        Fire() {};
        ~Fire(){};
        Elements getElement(){ return  elements_;};
    private:
        Elements elements_{Elements::eFire};
        Elements weakness_{Elements::eWater};
        Elements super_{Elements::eGrass};

    };

    class Water : public Element
    {
    public:
        Water() {};
          ~Water(){};
        Elements getElement(){ return  elements_;};
    private:
        Elements elements_{Elements::eWater};
        Elements weakness_{Elements::eLightning};
        Elements super_{Elements::eGround};

    };

    class Lightning : public Element
    {
    public:
        Lightning() {};
          ~Lightning(){};
        Elements getElement(){ return  elements_;};
    private:
        Elements elements_{Elements::eLightning};
        Elements weakness_{Elements::eGround};
        Elements super_{Elements::eWater};

    };

    class Ground : public Element
    {
    public:
        Ground() {};
          ~Ground(){};
        Elements getElement(){ return  elements_;};
    private:
        Elements elements_{Elements::eGround};
        Elements weakness_{Elements::eWater};
        Elements super_{Elements::eLightning};

    };

    class Grass : public Element
    {
    public:
        Grass() {};
          ~Grass(){};
        Elements getElement(){ return  elements_;};
    private:
        Elements elements_{Elements::eGrass};
        Elements weakness_{Elements::eFire};
        Elements super_{Elements::eWater};

    };



}
#endif //EXAM_ELEMENT_H
