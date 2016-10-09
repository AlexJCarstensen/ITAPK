//
// Created by ubuntuudvikling on 10/3/16.
//

#ifndef MYALLOCATOROWN_SMALLOBJECTALLOCATOR_H
#define MYALLOCATOROWN_SMALLOBJECTALLOCATOR_H
#include "SmallObjectHeap.h"

template <typename T>
class SmallObjectAllocator
{
public:
    typedef std::size_t	size_type;
    typedef ptrdiff_t	difference_type;
    typedef T*			pointer;
    typedef const T*	const_pointer;
    typedef T&			reference;
    typedef const T&	const_reference;
    typedef T			value_type;

    template <class U>
    struct rebind { typedef SmallObjectAllocator<U> other; };

    SmallObjectAllocator() {}
    SmallObjectAllocator( const SmallObjectAllocator& ) {}

    template <class U>
    SmallObjectAllocator( const SmallObjectAllocator<U>& ) {}

    ~SmallObjectAllocator() {}

    pointer address( reference x )				const { return &x; }
    const_pointer address( const_reference x )	const { return &x; }

    pointer allocate( size_type n, const_pointer = 0 )
    {
        return static_cast<pointer>( ::operator new( n * sizeof( T ) ) );
    }

    void deallocate( pointer p, size_type size )	{ ::operator delete( p ); }
    size_type max_size() const						{ return size_type( -1 ) / sizeof( T ); }

    void construct( pointer p, const value_type& x )	{ /* Constructing object */ }
    void destroy( pointer p )							{ /* Destructing object */ }
};

template<>
class SmallObjectAllocator<void>
{
    typedef void        value_type;
    typedef void*       pointer;
    typedef const void* const_pointer;

    template <class U>
    struct rebind { typedef SmallObjectAllocator<U> other; };
};


template <typename T>
bool operator == ( const SmallObjectAllocator<T>&, const SmallObjectAllocator<T>& )
{
    return true;
}

template <typename T>
bool operator != ( const SmallObjectAllocator<T>&, const SmallObjectAllocator<T>& )
{
    return false;
}

#endif //MYALLOCATOROWN_SMALLOBJECTALLOCATOR_H
