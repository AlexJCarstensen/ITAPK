//
// Created by carty on 9/21/16.
//

#ifndef CONTAINERS_ALGORITHMS_AND_ITERATORS_PRODUCT_H
#define CONTAINERS_ALGORITHMS_AND_ITERATORS_PRODUCT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <string>

using namespace std;

class Product
{
public:
    Product(const string &name, float price, unsigned int sold = 0)
            : name_(name), price_(price), sold_(sold)
    {}

    Product()
            : name_(""), price_(0), sold_(0)
    {}

    const string &name() const
    {
        return name_;
    }

    float price() const
    {
        return price_;
    }

    void setPrice(float newPrice)
    {
        price_ = newPrice;
    }

    unsigned int sold() const
    {
        return sold_;
    }

    friend istream &operator>>(istream &i, Product &p);

    friend ostream &operator<<(ostream &o, const Product &p);

private:
    string name_;
    float price_;
    int sold_;
};


typedef vector<Product>  ProductList;


ostream& operator<< ( ostream& o, const Product& p )
{
    return o << p.name_ << " " << p.price_ << " " << p.sold_;
}

istream& operator>> ( istream& i, Product& p )
{
    return i >> p.name_ >> p.price_ >> p.sold_;
}

/**
 * Read products from file
 */
void productDBRead(ProductList& pl, const string& fileName)
{
    pl.clear();
    std::ifstream pFile( fileName.c_str() );
    while( !pFile.eof() )
    {
        Product p;
        pFile >> p;
        if( pFile ) pl.push_back( p );
    }
}


/**
 * Printout all products
 */
void printAll(const ProductList& pl)
{
    cout << "##################################################" << endl;
    cout << "Printing out all products..." << endl;
    cout << "----------------------------" << endl;
    for(ProductList::const_iterator iter = pl.begin(); iter != pl.end(); ++iter)
    {
        cout << *iter << endl;
    }
    cout << "##################################################" << endl;
}



/**
   Add item
*/
void addItem(ProductList& pl)
{
}


/**
   Write data to db file
*/
void productDBWrite(const ProductList& pl, const string& fileName)
{
}


/**
 * Print poorly selling products
 */
void printPoorlySellingProducts(const ProductList& pl)
{
}


/**
 * Set a discount on all products - Using for_each()
 */
void addDiscountUsingForEach(ProductList& pl)
{
}


/**
 * Set a discount on all products - Using transform()
 */
void addDiscountUsingTransform(ProductList& pl)
{
}


/**
 * Calculate the total amount of sold products
 */
void calcTotalSoldProducts(ProductList& pl)
{
}


/**
 * Setting discount using bind2nd - OPTIONAL
 */
#endif //CONTAINERS_ALGORITHMS_AND_ITERATORS_PRODUCT_H
