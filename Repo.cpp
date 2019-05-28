#include "Repo.h"

///Repo methods

Repo::Repo(vector<Movie> mov_list)
{
    this->movieList = mov_list;
}

Repo::Repo()
{
    fillRepo();
}
//initializes repo

void Repo::fillRepo()
{
    movieList.push_back(Movie("Star Wars a New Hope","Sci-Fi",1977,1000000,"https://www.youtube.com/watch?v=1g3_CFmnU7k"));
    movieList.push_back(Movie("Harry Potter and the Goblet of fire","Fantasy",2005,600000,"https://www.youtube.com/watch?v=PFWAOnvMd1Q"));
    movieList.push_back(Movie("Lord of the Rings Return of the King","Fantasy",2003,706013,"https://www.youtube.com/watch?v=r5X-hFf6Bwo"));
    movieList.push_back(Movie("Pirates of the Caribbean The Curse of the Black Pearl","Action",2003,551325,"https://www.youtube.com/watch?v=0Z1XpfbuZOA"));
    movieList.push_back(Movie("Titanic","Drama",1997,456521,"https://www.youtube.com/watch?v=2e-eXJ6HgkQ"));
    movieList.push_back(Movie("The Grand Budapest Hotel","Comedy",2014,256144,"https://www.youtube.com/watch?v=zru-1DbbcsA"));
    movieList.push_back(Movie("The Godfather", "Crime", 1972, 10000, "https://www.youtube.com/watch?v=sY1S34973zA"));
    movieList.push_back(Movie("Annie Hall", "Comedy", 1977, 877, "https://www.youtube.com/watch?v=OqVgCfZX-yE"));
    movieList.push_back(Movie("The Shining", "Horror", 1980, 5221, "https://www.youtube.com/watch?v=5Cb3ik6zP2I"));
    movieList.push_back(Movie("The Matrix", "Sci-Fi", 1999, 4897, "https://www.youtube.com/watch?v=m8e-FF8MsqU"));
    movieList.push_back(Movie("Pulp Fiction", "Crime", 1994, 6663, "https://www.youtube.com/watch?v=s7EdQ4FqbhY"));
}

/*adds film to repo

@movie - instance of class Movie

@return - void
*/

void Repo::addFilm(Movie movie)
{
    this->movieList.push_back(movie);
}


/*changes the title of a movie
@index - int - index of movie in list
@newTitle - string - new title of movie

@return - void - title is updated to newTitle
*/

void Repo::changeTitle(int index, string newTitle)
{
    this->movieList.at(index).setTitle(newTitle);
}


/*changes the genre of a movie
@index - int - index of movie in list
@newGenre - string - new genre of movie

@return - void - genre is updated to newGenre
*/

void Repo::changeGenre(int index, string newGenre)
{
    this->movieList.at(index).setGen(newGenre);
}

/*changes the release year of a movie
@index - int - index of movie in list
@newGenre - int - new release year of movie

@return - void - year is updated to newYear
*/

void Repo::changeYear(int index, int newYear)
{
    this->movieList.at(index).setYear(newYear);
}

/*changes the number of likes of a movie
@index - int - index of movie in list
@newLikes - int - new number of likes of movie

@return - void - likes is updated to newLikes
*/

void Repo::changeLikes(int index, int newLikes)
{
    this->movieList.at(index).setLikes(newLikes);
}

/*changes the trailer link of a movie
@index - int - index of movie in list
@newTrailer - string - new trailer link of movie

@return - void - trailer is updated to newTrailer
*/

void Repo::changeTrailer(int index, string newTrailer)
{
    this->movieList.at(index).setTrailer(newTrailer);
}

/*removes movie from list
@index - int - index of movie in list

@return - void - movie is removed from list
*/

void Repo::deleteFilm(int index)
{
    this->movieList.erase(this->movieList.begin() + index);
}

///Watch list methods
watchlist::watchlist()
{

}
