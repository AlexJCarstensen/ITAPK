#include <iostream>

using namespace std;


/*
template<size_t N>
struct IsNotBinaryDigit
{
};

template<>
struct IsNotBinaryDigit<0>
{
    static const size_t value = 0;
};

template<>
struct IsNotBinaryDigit<1>
{
    static const size_t value = 1;
};

template<size_t N>
struct Binary
{
    static const size_t value = Binary<N / 10>::value << 1 | IsNotBinaryDigit<N % 10>::value;
};


template<>
struct Binary<0>
{
    static const size_t value = 0;
};
*/

struct NullType {};
template<typename L, typename R>
struct TypeList
{
    typedef L First;
    typedef R Rest;
};

// --------------------------------------------------
template<typename T, typename U>
struct IsSame{
    static const int value = 1;
};

template<typename T>
struct IsSame<T,T>{
    static const int value = 0;
};
template<typename T, typename U>
struct Is_Same{
    static const bool value = true;
};

template<typename T>
struct Is_Same<T,T>{
    static const bool value = false;
};

// --------------------------------------------------

template<typename T, typename U>
struct contains {
    static const bool value =
            IsSame<typename T::First, U>::value   // Base case
            || contains<typename T::Rest, U>::value; // Recursion
};

template <typename T>
struct contains<NullType, T>
{
    // Termination condition
    static const bool value = false;
};



#define TYPELIST1(t1) TypeList<t1, NullType>
#define TYPELIST2(t1, t2) TypeList<t1, TYPELIST1(t2) >
#define TYPELIST3(t1, t2, t3) TypeList<t1, TYPELIST2(t2, t3) >

#define JOHNPOUL(t1, t2, t3) TypeList<t1, TypeList<t2, TypeList<t3, NullType > > >

//typedef TypeList<int, TypeList<char, NullType>> TL;
//typedef TypeList<string, TypeList<string, NullType>> TS;





int main()
{
    typedef TYPELIST3(int, char, long) TL;
    std::cout << "Contains <TL , int >:: value=" << contains <TL, unsigned int >:: value << std::endl;
   // std::cout << "IsSame <int , int >:: value=" << IsSame <int , int >::value << std::endl;
    //std::cout << "IsSame <int , char >:: value=" << IsSame <int , char >::value << std::endl;
    //std::cout << Binary<10100111001>::value << std::endl;
    return 0;
}