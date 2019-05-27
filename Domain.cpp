#include "Domain.h"

//constructor implicit Movie

Movie::Movie()
{
    title="";
    genre="";
    publYear=-1;
    numLikes=-1;
    trailerLink="";
}

//constructor Movie

Movie::Movie(string t,string g,int y,int numL,string trailer)
{
    title=t;
    genre=g;
    publYear=y;
    numLikes=numL;
    trailerLink=trailer;
}

//getter title

string Movie::getTitle()
{
    return this->title;
}

//getter genre

string Movie::getGen()
{
    return this->genre;
}

//getter year

int Movie::getYear()
{
    return this->publYear;
}

//getter likes

int Movie::getLikes()
{
    return this->numLikes;
}

//getter trailer

string Movie::getTrailer()
{
    return this->trailerLink;
}

//setter title

void Movie::setTitle(string newTitle)
{
    this->title = newTitle;

}

//setter genre

void Movie::setGen(string newGenre)
{
    this->genre = newGenre;
}

//setter year

void Movie::setYear(int newYear)
{
    this->publYear = newYear;

}

//setter likes

void Movie::setLikes(int newLikes)
{
    this->numLikes = newLikes;
}

//setter trailer

void Movie::setTrailer(string newTrailer)
{
    this->trailerLink = newTrailer;
}
