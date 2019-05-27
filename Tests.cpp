#include "Tests.h"
#include <assert.h>
#include <iostream>
#include <string>
using namespace std;

void test_searchFilm()
{
    Movie mov1 = Movie("The Godfather", "Crime", 1972, 10000, "https://www.youtube.com/watch?v=sY1S34973zA");
    Movie mov2 = Movie("The Shining", "Horror", 1980, 5221, "https://www.youtube.com/watch?v=5Cb3ik6zP2I");
    vector<Movie> movies = {mov1, mov2};
    Repo movie_list = Repo(movies);
    Controller my_ctrl;
    my_ctrl.repo = movie_list;
    string genre, trailer;
    int likes;
    assert(my_ctrl.searchFilm("The Godfather", 1972, genre, likes, trailer));
    assert(genre == "Crime" && likes == 10000 && trailer == "https://www.youtube.com/watch?v=sY1S34973zA");
    assert(!my_ctrl.searchFilm("The Godfather", 2012, genre, likes, trailer));
    assert(!my_ctrl.searchFilm("The Goodfather", 2012, genre, likes, trailer));
    assert(my_ctrl.searchFilm("The Shining", 1980, genre, likes, trailer));
    assert(genre == "Horror" && likes == 5221 && trailer == "https://www.youtube.com/watch?v=5Cb3ik6zP2I");
}

void test_isMovieUnique()
{
    Movie mov1 = Movie("The Godfather", "Crime", 1972, 10000, "https://www.youtube.com/watch?v=sY1S34973zA");
    Movie mov2 = Movie("Annie Hall", "Comedy", 1977, 877, "https://www.youtube.com/watch?v=OqVgCfZX-yE");
    Movie mov3 = Movie("The Shining", "Horror", 1980, 5221, "https://www.youtube.com/watch?v=5Cb3ik6zP2I");
    Movie mov4 = Movie("The Matrix", "Sci-Fi", 1999, 4897, "https://www.youtube.com/watch?v=m8e-FF8MsqU");
    Movie mov5 = Movie("Titanic", "Drama", 1997, 8971, "https://www.youtube.com/watch?v=-iRajLSA8TA");
    Movie mov6 = Movie("Pulp Fiction", "Crime", 1994, 6663, "https://www.youtube.com/watch?v=s7EdQ4FqbhY");
    vector<Movie> movies = {mov1, mov2, mov3};
    Repo movie_list = Repo(movies);
    Controller my_ctrl;
    my_ctrl.repo = movie_list;
    assert(my_ctrl.isMovieUnique(mov4, movies) && my_ctrl.isMovieUnique(mov5, movies) && my_ctrl.isMovieUnique(mov6, movies));
    assert(!my_ctrl.isMovieUnique(mov1, movies) && !my_ctrl.isMovieUnique(mov2, movies) && !my_ctrl.isMovieUnique(mov3, movies));


}

void test_addFilm()
{
    Movie mov1 = Movie("The Shining", "Horror", 1980, 5221, "https://www.youtube.com/watch?v=5Cb3ik6zP2I");
    Movie mov2 = Movie("The Matrix", "Sci-Fi", 1999, 4897, "https://www.youtube.com/watch?v=m8e-FF8MsqU");
    vector<Movie> movies = {mov1};
    Repo movie_list = Repo(movies);
    Controller my_ctrl;
    my_ctrl.repo = movie_list;
    string genre, trailer;
    int likes;
    my_ctrl.addFilm(mov2);
    assert(my_ctrl.searchFilm("The Matrix", 1999, genre, likes, trailer));
    assert(genre == "Sci-Fi" && likes == 4897 && trailer == "https://www.youtube.com/watch?v=m8e-FF8MsqU");
    Movie mov3 = Movie("The Matrix", "Animation", 1999, 20, "https://www.youtube.com/watch?different_trailer");
    my_ctrl.addFilm(mov3);
    assert(my_ctrl.searchFilm("The Matrix", 1999, genre, likes, trailer));
    assert(genre == "Animation" && likes == 20 && trailer == "https://www.youtube.com/watch?different_trailer");
    Movie mov4 = Movie("The Matrix", "Romance" , 2019, 100, "https://www.youtube.com/watch?trailer_3");
    my_ctrl.addFilm(mov4);
    assert(my_ctrl.searchFilm("The Matrix", 1999, genre, likes, trailer));
    assert(genre == "Animation" && likes == 20 && trailer == "https://www.youtube.com/watch?different_trailer");
    assert(my_ctrl.searchFilm("The Matrix", 2019, genre, likes, trailer));
    assert(genre == "Romance" && likes == 100 && trailer == "https://www.youtube.com/watch?trailer_3");
}

void test_deleteFilm()
{
    Movie mov1 = Movie("The Godfather", "Crime", 1972, 10000, "https://www.youtube.com/watch?v=sY1S34973zA");
    Movie mov2 = Movie("Annie Hall", "Comedy", 1977, 877, "https://www.youtube.com/watch?v=OqVgCfZX-yE");
    Movie mov3 = Movie("The Shining", "Horror", 1980, 5221, "https://www.youtube.com/watch?v=5Cb3ik6zP2I");
    vector<Movie> movies = {mov1, mov2};
    Repo movie_list = Repo(movies);
    Controller my_ctrl;
    my_ctrl.repo = movie_list;
    assert(!my_ctrl.deleteFilm("The Godfather", 2019));
    assert(!my_ctrl.isMovieUnique(mov1, my_ctrl.repo.movieList));
    assert(my_ctrl.deleteFilm("The Godfather", 1972));
    assert(my_ctrl.isMovieUnique(mov1, my_ctrl.repo.movieList));
    assert(my_ctrl.deleteFilm("Annie Hall", 1977));
    assert(my_ctrl.isMovieUnique(mov2, my_ctrl.repo.movieList));
}

void test_isInt()
{
    Controller my_ctrl;
    assert(!my_ctrl.isInt("-123"));
    assert(!my_ctrl.isInt("ffafad"));
    assert(!my_ctrl.isInt("4fh440"));
    assert(my_ctrl.isInt("100"));
    assert(my_ctrl.isInt("1265"));
    assert(my_ctrl.isInt("42"));
}

void test_stringToInt()
{
    Controller my_ctrl;
    assert(my_ctrl.stringToInt("1234") == 1234);
    assert(my_ctrl.stringToInt("34") == 34);
    assert(my_ctrl.stringToInt("42") == 42);
}

void test_showByGenre()
{
    Movie mov1 = Movie("The Godfather", "Crime", 1972, 10000, "https://www.youtube.com/watch?v=sY1S34973zA");
    Movie mov2 = Movie("Annie Hall", "Comedy", 1977, 877, "https://www.youtube.com/watch?v=OqVgCfZX-yE");
    Movie mov3 = Movie("The Shining", "Horror", 1980, 5221, "https://www.youtube.com/watch?v=5Cb3ik6zP2I");
    Movie mov4 = Movie("Pulp Fiction", "Crime", 1994, 6663, "https://www.youtube.com/watch?v=s7EdQ4FqbhY");
    Controller my_ctrl;
    vector<Movie> movies = {mov1, mov2, mov3, mov4};
    Repo movie_list = Repo(movies);
    my_ctrl.repo = movie_list;
    vector<Movie> output;
    output = my_ctrl.showByGenre("Horror");
    assert(my_ctrl.isMovieUnique(mov1, output) && my_ctrl.isMovieUnique(mov2, output) && my_ctrl.isMovieUnique(mov4, output));
    assert(!my_ctrl.isMovieUnique(mov3, output));
    output = my_ctrl.showByGenre("Crime");
    assert(my_ctrl.isMovieUnique(mov2, output) && my_ctrl.isMovieUnique(mov3, output));
    assert(!my_ctrl.isMovieUnique(mov1, output) && !my_ctrl.isMovieUnique(mov4, output));
    output = my_ctrl.showByGenre("Romance");
    assert(!my_ctrl.isMovieUnique(mov1, output) && !my_ctrl.isMovieUnique(mov2, output) && !my_ctrl.isMovieUnique(mov3, output) && !my_ctrl.isMovieUnique(mov4, output));
}

void testAll()
{
    test_searchFilm();
    test_isMovieUnique();
    test_addFilm();
    test_deleteFilm();
    test_isInt();
    test_stringToInt();
    test_showByGenre();
}
