#include "UI.h"

///The default constructor of the UI class
UI::UI()
{

}
void UI::printMenuUser()
{
    string s;
    s+="1 - Show movies from watch list\n";
    s+="2 - Add movie to watch list from genre\n";
    s+="3 - Delete movie from watch list\n";
    s+="0 - Back to main menu\n";
    cout<<s<<endl;
}
void UI::printMenuMain()
{
    string s;
    s+="1 - Administrator menu\n";
    s+="2 - User menu\n";
    s+="0 - Exit\n";
    cout<<s<<endl;
}

void UI::printMenuAdmin()
{
    string s;
    s+="1 - Add new film\n";
    s+="2 - Edit existing film\n";
    s+="3 - Delete film\n";
    s+="4 - Show all available film\n";
    s+="0 - Back to main menu\n";
    cout<<s<<endl;
}

ostream& operator<<(ostream& os, const Movie& film)
{
    os << "\t" << film.title << ' ' << film.publYear << ' ' << film.genre << ' ' << film.numLikes << ' ' << film.trailerLink << endl;
    return os;
}

void UI::printFilms(vector<Movie> film_list)
{
    for ( auto film : film_list )
        cout << film << endl;
}

Movie UI::readFilm()
{
    string title, genre, trailer, read;
    int year, likes;
    cout << "Insert the TITLE of the new film: ";
    cin >> title;
    while(1)
    {
        cout << "Insert the RELEASE YEAR of the new film: ";
        cin >> read;
        if(!contr.isInt(read))
            cout << "The release year must be an integer! " << endl;
        else if(contr.stringToInt(read) < 0)
            cout << "The release year must be a positive number! " << endl;
        else if(contr.stringToInt(read) < 1890 || contr.stringToInt(read) > 2019)
            cout << "The release year must be between 1890 and 2019! " << endl;
        else
        {
            year = contr.stringToInt(read);
            break;
        }
    }
    while(1)
    {
        cout << "List of available genres: " << endl;
        cout << "Action, Crime, Fantasy, Western, Historical, Romance, Animation, Horror, Sci-Fi" << endl;
        cout << "Insert the GENRE of the new film: ";
        cin >> read;
        if(read != "Action" && read != "Crime" && read != "Fantasy" && read != "Western" && read != "Historical" &&
           read != "Romance" && read != "Animation" && read != "Horror" && read != "Sci-Fi")
            cout << "The given data is invalid! " << endl;
        else
        {
            genre = read;
            break;
        }
    }
    while(1)
    {
        cout << "Insert the NUMBER OF LIKES of the new film: ";
        cin >> read;
        if(!contr.isInt(read))
            cout << "The number of likes must be an integer! " << endl;
        else if(contr.stringToInt(read) < 0)
            cout << "The number of likes must be a positive number! " << endl;
        else
        {
            likes = contr.stringToInt(read);
            break;
        }
    }
    while(1)
        {
            cout << "Insert a LINK to the TRAILER of the new film: ";
            cin >> read;
            if (!regex_match (read, regex("^https://www.youtube.com/watch?.*$") ))
                cout << "The link is not a valid url! " << endl;
            else
            {
                trailer = read;
                break;
            }
        }
    return Movie(title, genre, year, likes, trailer);
}

void UI::userMenu()
{
    bool ok=true;
    string s;
    while(ok==true)
    {
        this->printMenuUser();
        cout<<"Please insert the value of the option you want!"<<endl;
        cin>>s;
        if(contr.isInt(s)==true && contr.stringToInt(s)>=0 && contr.stringToInt(s)<=3)
        {
            if(contr.stringToInt(s)==0)
                ok=false;
            else if(contr.stringToInt(s)==1)
            {
                if(contr.WL.movieList.size()==0)
                    cout<<"The watch list is empty"<<endl;
                else
                    this->contr.showAllMovies(contr.WL.movieList);
            }
            else if(contr.stringToInt(s)==2)
            {
                cout<<"Please insert the genre you would like: ";
                string gen;
                cin>>gen;
                contr.runSlide(contr.showByGenre(gen));
            }
            else if(contr.stringToInt(s)==3)
            {
                this->contr.deleteFromWL();
            }
        }
        else
            cout<<"The value you inserted is not valid, please try again!"<<endl;
    }
}
void UI::adminMenu()
{
    bool ok=true;
    string s;
    while(ok==true)
    {
        this->printMenuAdmin();
        cout<<"Please insert the value of the option you want!"<<endl;
        cin>>s;
        if(contr.isInt(s) == true && contr.stringToInt(s) >= 0 && contr.stringToInt(s) <= 4)
        {
            if(contr.stringToInt(s) == 0)
                ok = false;
            else if(contr.stringToInt(s) == 1)
            {
                Movie newFilm = this->readFilm();
                this->contr.addFilm(newFilm);
                cout << "The film has been successfully added!" << endl;
            }
            else if(contr.stringToInt(s) == 2)
            {
                string title, old_title, genre, old_genre, trailer, old_trailer, read;
                int year, old_year, likes, old_likes;
                cout << "Write the TITLE of the film: " << endl;
                cin >> old_title;
                while(1)
                {
                    cout << "Write the RELEASE YEAR of the film: ";
                    cin >> read;
                    if(!contr.isInt(read))
                        cout << "The release year must be an integer! " << endl;
                    else
                    {
                        year = contr.stringToInt(read);
                        break;
                    }
                }
                if(!this->contr.searchFilm(old_title, old_year, old_genre, old_likes, old_trailer))
                {
                    cout << "The requested film is unavailable! " << endl;
                }
                else
                {
                    string answer;
                    do
                    {
                        cout << "The current TITLE of the film is " << old_title << ". " << endl << "Would you like to change the TITLE? [y/n] " << endl;
                        cin >> answer;

                    }while(answer != "y" && answer != "n");

                    if(answer == "y")
                    {
                        cout << "What would you like the new TITLE to be?" << endl;
                        cin >> title;
                    }
                    else
                        title = old_title;
                     do
                    {
                        cout << "The current RELEASE YEAR of the film is " << old_year << ". " << endl << "Would you like to change the RELEASE YEAR? [y/n] " << endl;
                        cin >> answer;

                    }while(answer != "y" && answer != "n");

                    if(answer == "y")
                    {
                        while(1)
                        {
                            cout << "What would you like the new RELEASE YEAR to be?" << endl;
                            cin >> read;
                            if(!contr.isInt(read))
                                cout << "The release year must be an integer! " << endl;
                            else if(contr.stringToInt(read) < 0)
                                cout << "The release year must be a positive number! " << endl;
                            else if(contr.stringToInt(read) < 1890 || contr.stringToInt(read) > 2019)
                                cout << "The release year must be between 1890 and 2019! " << endl;
                            else
                            {
                                year = contr.stringToInt(read);
                                break;
                            }
                        }
                    }
                    else
                        year = old_year;
                     do
                    {
                        cout << "The current GENRE of the film is " << old_genre << ". " << endl << "Would you like to change the GENRE? [y/n] " << endl;
                        cin >> answer;

                    }while(answer != "y" && answer != "n");

                    if(answer == "y")
                    {
                        while(1)
                        {
                            cout << "List of available genres: " << endl;
                            cout << "Action, Crime, Fantasy, Western, Historical, Romance, Animation, Horror, Sci-Fi" << endl;
                            cout << "What would you like the new GENRE to be?" << endl;
                            cin >> read;
                            if(read != "Action" && read != "Crime" && read != "Fantasy" && read != "Western" && read != "Historical" &&
                               read != "Romance" && read != "Animation" && read != "Horror" && read != "Sci-Fi")
                                cout << "The given data is invalid! " << endl;
                            else
                            {
                                genre = read;
                                break;
                            }
                        }
                    }
                    else
                        genre = old_genre;
                     do
                    {
                        cout << "The current NUMBER OF LIKES of the film is " << old_likes << ". " << endl << "Would you like to change the NUMBER OF LIKES? [y/n] " << endl;
                        cin >> answer;

                    }while(answer != "y" && answer != "n");

                    if(answer == "y")
                    {

                        while(1)
                        {
                            cout << "What would you like the new NUMBER OF LIKES to be?" << endl;
                            cin >> read;
                            if(!contr.isInt(read))
                                cout << "The number of likes must be an integer! " << endl;
                            else if(contr.stringToInt(read) < 0)
                                cout << "The number of likes must be a positive number! " << endl;
                            else
                            {
                                likes = contr.stringToInt(read);
                                break;
                            }
                        }
                    }
                    else
                        likes = old_likes;
                    do
                    {
                        cout << "The current LINK to the TRAILER of the film is " << old_trailer << ". " << endl << "Would you like to change the TRAILER LINK? [y/n] " << endl;
                        cin >> answer;

                    }while(answer != "y" && answer != "n");

                    if(answer == "y")
                    {
                        while(1)
                        {
                            cout << "What would you like the new TRAILER LINK to be?" << endl;
                            cin >> read;
                            if (!regex_match ( read, regex("^https://www.youtube.com/watch?.*$") ))
                                cout << "The link is not a valid url! " << endl;
                            else
                            {
                                trailer = read;
                                break;
                            }
                        }
                    }
                    else
                        trailer = old_trailer;
                    this->contr.editFilm(old_title, old_year, title, year, genre, likes, trailer);
                    cout << "The information has been successfully updated! " << endl;
                }
            }
            else if(contr.stringToInt(s) == 3)
            {
                string title;
                int year;
                cout << "Write the TITLE of the film: " << endl;
                cin >> title;
                cout << "Write the RELEASE YEAR of the film: " << endl;
                cin >> year;
                if(!this->contr.deleteFilm(title, year))
                    cout << "No such film has been found!" << endl;
                else
                    cout << "The film has been successfully removed! " << endl;
            }
            else if(contr.stringToInt(s) == 4)
            {
                UI::printFilms(this->contr.repo.movieList);
            }
        }
        else
            cout<<"The value you inserted is not valid, please try again!"<<endl;
    }
}
void UI::run()
{
    bool ok=true;
    string s;
    while(ok==true)
    {
        this->printMenuMain();
        cout<<"Please insert the value of the option you want!"<<endl;
        cin>>s;
        if(contr.isInt(s)==true && contr.stringToInt(s)>=0 && contr.stringToInt(s)<=2)
        {
            if(contr.stringToInt(s)==0)
                ok=false;
            else if(contr.stringToInt(s)==1)
            {
                this->adminMenu();
            }
            else if(contr.stringToInt(s)==2)
            {
                this->userMenu();
            }
        }
        else
            cout<<"The value you inserted is not valid, please try again!"<<endl;
    }
}
