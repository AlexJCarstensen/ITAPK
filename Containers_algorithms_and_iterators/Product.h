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
#include <boost/variant.hpp>
#include <sstream>

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


typedef vector<Product> ProductList;


ostream &operator<<(ostream &o, const Product &p)
{
    return o << p.name_ << " " << p.price_ << " " << p.sold_;
}

istream &operator>>(istream &i, Product &p)
{
    return i >> p.name_ >> p.price_ >> p.sold_;
}

/**
 * Read products from file
 */
void productDBRead(ProductList &pl, const string &fileName)
{
    pl.clear();
    ifstream pFile(fileName.c_str());

    istream_iterator<Product> in_iter(pFile);
    istream_iterator<Product> eof;

    while (in_iter != eof)
    {
        Product p;
        p = *in_iter;
        //back_inserter(pl);
        pl.push_back(p);
        in_iter++;

    }

//    while( !pFile.eof() )
//    {
//        Product p;
//        pFile >> p;
//        if( pFile ) pl.push_back( p );
//    }
}


/**
 * Printout all products
 */
void printAll(const ProductList &pl)
{
    cout << "##################################################" << endl;
    cout << "Printing out all products..." << endl;
    cout << "----------------------------" << endl;
    ostream_iterator<Product> outputProduct(cout);

    for (ProductList::const_iterator iter = pl.begin(); iter != pl.end(); ++iter)
    {
        *outputProduct = *iter;
        cout  << endl;
    }
    cout << "##################################################" << endl;
}

bool isFloat(const string& s){
    istringstream iss (s);
    float f;
    iss >> noskipws >> f;
    return  iss.eof() && !iss.fail();

}
bool isInt(const string& s){
    string::const_iterator it = s.begin();
    while(it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
/**
   Add item
*/
void addItem(ProductList &pl)
{
    //boost::variant<string, float, int> myVal;
    cout << "File Name: " << flush;
    istream_iterator<string> inputIter(cin);
    string name = *inputIter;
    cout << "Price: " << flush;
    inputIter++;
    while(!isFloat(*inputIter)) {cout << "please input a number: " << flush; inputIter++;}
    float price = stof(*inputIter);
    cout << "Sold: " << flush;
    inputIter++;
    while(!isInt(*inputIter)) {cout << "please input a number: " << flush; inputIter++;}
    unsigned int sold = stoi(*inputIter);

    Product p(name, price, sold);
    pl.push_back(p);


}



/**
   Write data to db file
*/
void productDBWrite(const ProductList &pl, const string &fileName)
{
}


/**
 * Print poorly selling products
 */
void printPoorlySellingProducts(const ProductList &pl)
{
}


/**
 * Set a discount on all products - Using for_each()
 */
void addDiscountUsingForEach(ProductList &pl)
{
}


/**
 * Set a discount on all products - Using transform()
 */
void addDiscountUsingTransform(ProductList &pl)
{
}


/**
 * Calculate the total amount of sold products
 */
void calcTotalSoldProducts(ProductList &pl)
{
}


/**
 * Setting discount using bind2nd - OPTIONAL
 */
#endif //CONTAINERS_ALGORITHMS_AND_ITERATORS_PRODUCT_H
