#include "Repo.h"

class Controller
{
private:
    ///Common private variables of User and Admin
    Repo repo=Repo();
    ///User Mode private variables
    watchlist WL=watchlist();
    ///Admin Mode private variables

public:
    ///Common methods and public variables of User and Admin
    Controller();
    bool isInt(string val);
    int stringToInt(string val);
    bool isMovieUnique(Movie mov,vector<Movie> lista);
    void showAllMovies(vector<Movie> lista);
    ///User Mode methods and public variables
    vector<Movie> showByGenre(string gen);
    void runSlide(vector<Movie> slide);
    void deleteFromWL();
    ///Admin Mode methods and public variables

};
