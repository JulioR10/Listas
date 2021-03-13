#ifndef TIPODATO_H
#define TIPODATO_H

#include <iostream>

struct TipoDato {
    std::string film;
    int year;
    int number_stars;
};

// A function to define order
bool less_than(const TipoDato& lhs, const TipoDato& rhs);

// A function to compare two instances
bool equal(const TipoDato& lhs, const TipoDato& rhs);
/*
// A function to define order
bool less_than(const TipoDato &lhs, const TipoDato &rhs)
{
    return lhs.year < rhs.year;  // Order by year
}

// A function to compare two instances
bool equal(const TipoDato &lhs, const TipoDato &rhs)
{
    // Two films are equal if the have the same name and year.
    return (lhs.film == rhs.film) && (lhs.year == rhs.year);
}
*/
#endif // TIPODATO_H
