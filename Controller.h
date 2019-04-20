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
    bool isInt(string val);
    int stringToInt(string val);
    Controller();
    ///User Mode methods and public variables

    ///Admin Mode methods and public variables

};
