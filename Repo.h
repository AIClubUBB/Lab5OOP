#pragma once
#include "Domain.h"
#include <vector>

//The declaration of the Repo class with all its methods and attributes
class Repo
{
//The declaration of all the private variables
private:
//The declaration of all the public variables,setters and getters
public:
    Repo();
    void fillRepo();
    vector<Movie> movieList;
};

//The declaration of the Watchlist class with all its methods and attributes
class watchlist
{
//The declaration of all the private variables
private:
//The declaration of all the public variables,setters and getters
public:
    vector<Movie> movieList;
    watchList();
};
