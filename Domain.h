#pragma once
#include <string>
#include <iostream>
using namespace std;

/**********************************************************************************
We have decided that what makes a movie unique is the title and the year of release

If another movie of identical title and release year is found genre, likes and trailer are updated
**********************************************************************************/


//The declaration of the Movie class with all its methods and attributes
class Movie
{
//The declaration of all the private variables
private:
    string title;
    string genre;
    int publYear;
    int numLikes;
    string trailerLink;
//The declaration of all the public variables,setters and getters
public:
    Movie();
    Movie(string t,string g,int y,int numL,string trailer);
    string getTitle();
    string getGen();
    int getYear();
    int getLikes();
    string getTrailer();
    void setTitle(string newTitle);
    void setGen(string newGenre);
    void setYear(int newYear);
    void setLikes(int newLikes);
    void setTrailer(string newTrailer);
    friend ostream& operator<<(ostream&, const Movie&);
};
