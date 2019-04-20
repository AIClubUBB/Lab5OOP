#pragma once
#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
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
};
