#include "Domain.h"

Movie::Movie()
{
    title="";
    genre="";
    publYear=-1;
    numLikes=-1;
    trailerLink="";
}
Movie::Movie(string t,string g,int y,int numL,string trailer)
{
    title=t;
    genre=g;
    publYear=y;
    numLikes=numL;
    trailerLink=trailer;
}
string Movie::getTitle()
{
    return this->title;
}
string Movie::getGen()
{
    return this->genre;
}
int Movie::getYear()
{
    return this->publYear;
}
int Movie::getLikes()
{
    return this->numLikes;
}
string Movie::getTrailer()
{
    return this->trailerLink;
}
void Movie::setTitle(string newTitle)
{

}
void Movie::setGen(string newGenre)
{

}
void Movie::setYear(int newYear)
{

}
void Movie::setLikes(int newLikes)
{
    this->numLikes=newLikes;
}
void Movie::setTrailer(string newTrailer)
{

}
