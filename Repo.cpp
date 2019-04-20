#include "Repo.h"

///Repo methods
Repo::Repo()
{

}
void Repo::fillRepo()
{
    movieList.push_back(Movie("Star Wars a New Hope","Sci-Fi",1977,1000000,"https://www.youtube.com/watch?v=1g3_CFmnU7k"));
    movieList.push_back(Movie("Harry Potter and the Goblet of fire","Fantasy",2005,600000,"https://www.youtube.com/watch?v=PFWAOnvMd1Q"));
    movieList.push_back(Movie("Lord of the Rings Return of the King","Fantasy",2003,706013,"https://www.youtube.com/watch?v=r5X-hFf6Bwo"));
    movieList.push_back(Movie("Pirates of the Caribbean The Curse of the Black Pearl","Action",2003,551325,"https://www.youtube.com/watch?v=0Z1XpfbuZOA"));
    movieList.push_back(Movie("Titanic","Drama",1997,456521,"https://www.youtube.com/watch?v=2e-eXJ6HgkQ"));
    movieList.push_back(Movie("The Grand Budapest Hotel","Comedy",2014,256144,"https://www.youtube.com/watch?v=zru-1DbbcsA"));
}

///Watch list methods
watchlist::watchList()
{

}
