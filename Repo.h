#pragma once
#include "Domain.h"
#include <vector>
#include <fstream>

//The declaration of the Repo class with all its methods and attributes
class Repo
{
//The declaration of all the private variables
private:
//The declaration of all the public variables,setters and getters
public:
    Repo();
    Repo(vector<Movie>);
    void fillRepo();
    vector<Movie> movieList;
    void addFilm(Movie);
    void changeTitle(int, string);
    void changeGenre(int, string);
    void changeYear(int, int);
    void changeLikes(int, int);
    void changeTrailer(int, string);
    void deleteFilm(int);
    void readFromFileFilm();
    void writeToFileFilm();
};

//The declaration of the Watchlist class with all its methods and attributes
class watchlist
{
//The declaration of all the private variables
private:
//The declaration of all the public variables,setters and getters
public:
    vector<Movie> movieList;
    void readFromFileUser();
    void writeToFileUser();
    watchlist();
};
