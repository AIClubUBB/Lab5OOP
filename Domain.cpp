#include "Domain.h"

Movie::Movie()
{
    string title="";
    string genre="";
    int publYear=-1;
    int numLikes=-1;
    string trailerLink="";
}
Movie::Movie(string t,string g,int y,int numL,string trailer)
{
    string title=t;
    string genre=g;
    int publYear=y;
    int numLikes=numL;
    string trailerLink=trailer;
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

}
void Movie::setTrailer(string newTrailer)
{

}
