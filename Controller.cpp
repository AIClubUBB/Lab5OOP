#include "Controller.h"

// constructor

Controller::Controller()
{

}

/*checks if given string could be interpreted as integer

@val - string

@return - bool - true if condition is satisfied
               - false otherwise
*/
bool Controller::isInt(string val)
{
    for(int i=0;i<val.length();i++)
    {
        if(val[i]<48 || val[i]>57)
            return false;
    }
    return true;
}

/*turns given string into corresponding integer

@val - string

@return - int
*/
int Controller::stringToInt(string val)
{
    int ret=0;
    for(int i=0;i<val.length();i++)
    {
        ret=ret*10+(val[i]-48);
    }
    //this->repo.fillRepo();
    return ret;
}

/*shows all movies in given vector

@slide - stl vector of type Movie

@return - void
*/

void Controller::showAllMovies(vector<Movie> slide)
{
    for(int cont=0;cont<slide.size();cont++)
    {
        cout<<"Movie with index: "<<cont<<" has the following characteristics:"<<endl;
        cout<<"Title: "<<slide[cont].getTitle()<<"\nGenre: "<<slide[cont].getGen()<<"\nYear: "<<slide[cont].getYear()<<"\nLikes: "<<slide[cont].getLikes()<<"\n";
    }
}

/*checks if given movie is already in given list

@mov - Movie
@lista - stl vector of type Movie

@return - true if mov is in lista
        - false otherwise
*/
bool Controller::isMovieUnique(Movie mov,vector<Movie> lista)
{
    for(int i=0;i<lista.size();i++)
    {
        if(lista[i].getTitle()==mov.getTitle() && lista[i].getYear()==mov.getYear())
            return false;
    }
    return true;
}



/*returns all movies of a given genre, if none are found the whole repo is returned
@gen - string

@return - stl vector of type Movie
*/

vector<Movie> Controller::showByGenre(string gen)
{
    vector<Movie> ret;
    for(int i=0;i<repo.movieList.size();i++)
    {
        if(gen==repo.movieList[i].getGen())
        {
            ret.push_back(repo.movieList[i]);
        }
    }
    if(ret.size()>0)
        return ret;
    else
        return repo.movieList;
}

/*adds movies to watchlist handling user input
@slide - vector<Movie>

@return - void
*/
void Controller::runSlide(vector<Movie> slide)
{
    cout<<"You have entered slide mode,\nthe movies from the selected genre will start showing on your screen"<<endl;
    string s="y";
    int cont=0;
    while(s!="n")
    {
        cout<<"The information about the current movie is: "<<endl;
        if(cont==slide.size())
            cont=0;
        cout<<"Title: "<<slide[cont].getTitle()<<"\nGenre: "<<slide[cont].getGen()<<"\nYear: "<<slide[cont].getYear()<<"\nLikes: "<<slide[cont].getLikes()<<"\n";
        cout<<"Do you want the trailer of the movie to start playing in your browser? [y/n]"<<endl;
        cin>>s;
        bool ok=true;
        if(s=="y")
        {
            system(std::string("start " + slide[cont].getTrailer()).c_str());
            cout<<"The trailer has started playing in your browser"<<endl;
        }
        else if(s!="n")
        {
            cout<<"The received input does not match the options, please enter your choice again"<<endl;
            ok=false;
        }
        if(ok==true)
        {
            cout<<"Would you like to add the movie to the watch list? [y/n]"<<endl;
            cin>>s;
            if(s=="y")
            {
                if(isMovieUnique(slide[cont],WL.movieList))
                {
                    this->WL.movieList.push_back(slide[cont]);
                    cout<<"The movie was successfully added to your watch list"<<endl;
                }
                else
                {
                    cout<<"The movie is already in your list, but we are glad that you like it that much!"<<endl;
                }
            }
            else if(s!="n")
            {
                cout<<"The received input does not match the options, please enter your choice again"<<endl;
                ok=false;
            }
        }
        if(ok==true)
        {
            cout<<"Would you like to see the next movie from your chosen genre? [y/n]"<<endl;
            cin>>s;
            if(s=="y")
            {
                cont++;
            }
            else if(s!="n")
            {
                cout<<"The received input does not match the options, please enter your choice again"<<endl;
            }
            else
                break;
        }
    }
}

/*deletes movies from watchlist based on user input

@return - void
*/
void Controller::deleteFromWL()
{
    this->showAllMovies(WL.movieList);
    cout<<"Please insert the index of the movie you want to delete"<<endl;
    string s;
    cin>>s;
    if(this->isInt(s)==true)
    {
        int val=this->stringToInt(s);
        if(val>=0 && val<WL.movieList.size())
        {
            string na=WL.movieList[val].getTitle();
            int year=WL.movieList[val].getYear();
            WL.movieList.erase(WL.movieList.begin()+val);
            cout<<"The movie was successfully deleted from your watch list"<<endl;
            cout<<"Would you like rate the movie?[y/n]"<<endl;
            cin>>s;
            if(s=="y")
            {
                cout<<"Did you like the movie? [y/n]"<<endl;
                cin>>s;
                if(s=="y")
                {
                    for(int i=0;i<repo.movieList.size();i++)
                    {
                        if(na==repo.movieList[i].getTitle() && year==repo.movieList[i].getYear())
                        {
                            repo.movieList[i].setLikes(repo.movieList[i].getLikes()+1);
                        }
                    }
                    cout<<"Your vote was registered, thank you for your time"<<endl;
                }
                else if(s=="n")
                {
                    for(int i=0;i<repo.movieList.size();i++)
                    {
                        if(na==repo.movieList[i].getTitle() && year==repo.movieList[i].getYear())
                        {
                            repo.movieList[i].setLikes(repo.movieList[i].getLikes()-1);
                        }
                    }
                    cout<<"Your vote was registered, thank you for your time"<<endl;
                }
                else
                {
                    cout<<"The received input does not match the options, please enter your choice again"<<endl;
                    this->deleteFromWL();
                }
            }
            else if(s!="n")
            {
                cout<<"The received input does not match the options, please enter your choice again"<<endl;
                this->deleteFromWL();
            }
        }
        else
        {
            cout<<"The value you entered is not in the list of options, please try again"<<endl;
            this->deleteFromWL();
        }
    }
    else
    {
        cout<<"The value you entered is not a natural number, please try again!"<<endl;
        this->deleteFromWL();
    }
}

/*searches for a movie by title and release year

@title - string
@year - int
@genre - string&
@likes - int&
@trailer - string&

@return - bool - false if movie not in list
               - true otherwise, genre, likes and trailer are set to their respective values
*/

bool Controller::searchFilm(string title, int year, string& genre, int& likes, string& trailer)
{
    int index = 0;
    for(auto it = this->repo.movieList.begin(); it != this->repo.movieList.end(); it++, index++)
        if((*it).getTitle() == title && (*it).getYear() == year)
            break;
    if(index < this->repo.movieList.size())
    {
        genre = this->repo.movieList.at(index).getGen();
        likes = this->repo.movieList.at(index).getLikes();
        trailer = this->repo.movieList.at(index).getTrailer();
        return true;
    }
    return false;
}

/*adds new movie to list

@newFilm - Movie

@return - void; if another movie of identical title and release year is found genre, likes and trailer are updated
                else a new Movie object is added to the list
*/

void Controller::addFilm(Movie newFilm)
{

    int index = 0;
    for(auto it = this->repo.movieList.begin(); it != this->repo.movieList.end(); it++, index++)
        if((*it).getTitle() == newFilm.getTitle() && (*it).getYear() == newFilm.getYear())
            break;
    if(index < this->repo.movieList.size())
    {
        this->repo.changeGenre(index, newFilm.getGen());
        this->repo.changeLikes(index, newFilm.getLikes());
        this->repo.changeTrailer(index, newFilm.getTrailer());
    }
    else
        this->repo.addFilm(newFilm);
}

/*updates the attributes of a movie

@old_title - string
@old_year - int
@new_title - string
@new_year - int
@new_genre - string
@new_likes - int
@new_trailer - string


@return - false if movie not in list
        - true if successfully updated

*/

bool Controller::editFilm(string old_title, int old_year, string new_title, int new_year, string new_genre, int new_likes, string new_trailer)
{
    int index = 0;
    for(auto it = this->repo.movieList.begin(); it != this->repo.movieList.end(); it++, index++)
        if((*it).getTitle() == old_title && (*it).getYear() == old_year)
            break;
    if(index < this->repo.movieList.size())
    {
        this->repo.changeTitle(index, new_title);
        this->repo.changeYear(index, new_year);
        this->repo.changeGenre(index, new_genre);
        this->repo.changeLikes(index, new_likes);
        this->repo.changeTrailer(index, new_trailer);
        return true;
    }
    return false;
}

/*removes movie

@title - string
@year - int

@return - bool - false if movie not found
               - true if successfully removed
*/

bool Controller::deleteFilm(string title, int year)
{
    int index = 0;
    for(auto it = this->repo.movieList.begin(); it != this->repo.movieList.end(); it++, index++)
        if((*it).getTitle() == title && (*it).getYear() == year)
            break;
    if(index < this->repo.movieList.size())
    {
      this->repo.deleteFilm(index);
      return true;
    }
    return false;
}
