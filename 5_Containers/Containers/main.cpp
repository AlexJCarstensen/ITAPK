#include <iostream>
#include "Product.h"

#define PRODUCT_DB_FILE		"product.db"
int main()
{
    bool        running = true;
    ProductList pl;

    while(running)
    {
        char choice;

        cout << "********************" << endl;
        cout << "Help menu: " << endl;
        cout << "'1' Read product database" << endl;
        cout << "'2' Print all items" << endl;
        cout << "'3' Add item" << endl;
        cout << "'4' Write product database" << endl;
        cout << "'5' Print poorly selling products" << endl;
        cout << "'6' Set a discount on all products (using for_each() )" << endl;
        cout << "'7' Set a discount on all products (using transform() )" << endl;
        cout << "'8' Calculate the total amount of sold products" << endl;


        cout << "'q' Quit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch(choice)
        {
            case '1':
                productDBRead(pl, PRODUCT_DB_FILE);
                break;

            case '2':
                printAll(pl);
                break;
            case '3':
                addItem(pl);
                break;

            case '4':
                productDBWrite(pl, PRODUCT_DB_FILE);
                break;

            case '5':
                printPoorlySellingProducts(pl);
                break;

            case '6':
                addDiscountUsingForEach(pl);
                break;

            case '7':
                addDiscountUsingTransform(pl);
                break;

            case '8':
                calcTotalSoldProducts(pl);
                break;

            case 'q':
            case 'Q':
                running = false;
        }


    }

}