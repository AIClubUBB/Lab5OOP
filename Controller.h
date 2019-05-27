#include "Repo.h"
#pragma once

class Controller
{
private:
    ///Common private variables of User and Admin

    ///User Mode private variables

    ///Admin Mode private variables

public:
    ///Common methods and public variables of User and Admin
    Controller();
    Repo repo = Repo();
    bool isInt(string val);
    int stringToInt(string val);
    bool isMovieUnique(Movie mov,vector<Movie> lista);
    void showAllMovies(vector<Movie> lista);
    ///User Mode methods and public variables
    watchlist WL=watchlist();
    vector<Movie> showByGenre(string gen);
    void runSlide(vector<Movie> slide);
    void deleteFromWL();
    ///Admin Mode methods and public variables
    void addFilm(Movie);
    bool searchFilm(string, int, string&, int&, string&);
    bool editFilm(string, int, string, int, string, int, string);
    bool deleteFilm(string, int);

};
