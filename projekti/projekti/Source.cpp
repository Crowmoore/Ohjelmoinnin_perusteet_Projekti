/*
***Harjoitustyö***
Kuvaus: Ohjelmaan voi tallentaa elokuvien ja albumien nimet sekä julkaisuvuodet.
		Ohjelma tallentaa tiedot erillisiin .txt tiedostoihin ja tarvittaessa tulostaa tiedot näytölle.
		Tiedostot on myös mahdollista tyhjentää.
Tekijä: Joel Kortelainen
Versio: 1.0
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct movieInfo{
	string movieName;
	string releaseYear;
};

struct albumInfo{
	string artistName;
	string albumName;
	string releaseYear;
};

vector<albumInfo> album;
vector<movieInfo> movie;
string getUserInputString();
int getUserInputInteger();
void clearConsole();
void menu();
void addNewMovie();
void printSavedMovies();
void saveMoviesToFile();
void clearSavedMovieFile();
void addNewAlbum();
void printSavedAlbums();
void saveAlbumsToFile();
void clearSavedAlbumFile();
int menuSelection();

int main()
{
	system("title Personal Movie and Album Database");
	menu();
	return EXIT_SUCCESS;
}


void menu()
{
	int selection = -1;
	while (selection != 0)
	{
		clearConsole();
		cout << "What would you like to do?" << endl;
		cout << endl << "0. Exit";
		cout << endl << "1. Add a new movie" << "           " << "5. Add a new album";
		cout << endl << "2. Print saved movies" << "        " << "6. Print saved albums";;
		cout << endl << "3. Save movies" << "               " << "7. Save albums";
		cout << endl << "4. Delete saved movies" << "       " << "8. Delete saved albums" << endl;
		selection = menuSelection();
	}
}

int menuSelection()
{
	int userSelection = getUserInputInteger();
	switch (userSelection)
	{
	case 0: exit(0);
	case 1: addNewMovie();
		break;
	case 2: printSavedMovies();
		break;
	case 3: saveMoviesToFile();
		break;
	case 4: clearSavedMovieFile();
		break;
	case 5: addNewAlbum();
		break;
	case 6: printSavedAlbums();
		break;
	case 7: saveAlbumsToFile();
		break;
	case 8: clearSavedAlbumFile();
		break;
	default: cout << "Choose from the listed actions. Press enter to continue. ";
		cin.get();
	}
	return 1;
}

void saveMoviesToFile()
{
	fstream saveFile;
	saveFile.open("movies.txt", fstream::out | fstream::app);
	for each (movieInfo element in movie)
	{
		saveFile << element.movieName << " " << "(" << element.releaseYear << ")" << endl;
	}
	saveFile.close();
	menu();
}

void printSavedMovies()
{
	clearConsole();
	fstream loadFile;
	loadFile.open("movies.txt", fstream::in);
	cout << "Your saved movies:" << endl;
	while (loadFile.good())
	{
		cout << (char)loadFile.get();
	}
	loadFile.close();
	cout << endl << "Press enter to go back to the menu.";
	cin.get();
	menu();
}

void addNewMovie()
{
	clearConsole();
	movieInfo newMovie;
	cout << "Movie title: ";
	newMovie.movieName = getUserInputString();
	cout << "Release year: ";
	newMovie.releaseYear = getUserInputString();
	movie.push_back(newMovie);
	menu();
}

void clearSavedMovieFile()
{
	clearConsole();
	char yesOrNo;
	cout << "Are you sure you want to delete all contents from movies.txt? y/n" << endl;
	cin >> yesOrNo;
	if (yesOrNo == 'y')
	{
		fstream saveFile;
		saveFile.open("movies.txt", fstream::in | fstream::out | fstream::trunc);
		saveFile.close();
		clearConsole();
		cout << "All contents successfully deleted. Press enter to go back to the menu.";
		cin.ignore(1, '\n');
		cin.get();
		menu();
	}
	menu();
}

void addNewAlbum()
{
	clearConsole();
	albumInfo newAlbum;
	cout << "Artist name: ";
	newAlbum.artistName = getUserInputString();
	cout << "Album title: ";
	newAlbum.albumName = getUserInputString();
	cout << "Release year: ";
	newAlbum.releaseYear = getUserInputString();
	album.push_back(newAlbum);
	menu();
}

void saveAlbumsToFile()
{
	fstream saveFile;
	saveFile.open("albums.txt", fstream::out | fstream::app);
	for each (albumInfo element in album)
	{
		saveFile << element.artistName << " - " << element.albumName << " " << "(" << element.releaseYear << ")" << endl;
	}
	saveFile.close();
	menu();
}

void printSavedAlbums()
{
	clearConsole();
	fstream loadFile;
	loadFile.open("albums.txt", fstream::in);
	cout << "Your saved albums:" << endl;
	while (loadFile.good())
	{
		cout << (char)loadFile.get();
	}
	loadFile.close();
	cout << endl << "Press enter to go back to the menu.";
	cin.get();
	menu();
}

void clearSavedAlbumFile()
{
	clearConsole();
	char yesOrNo;
	cout << "Are you sure you want to delete all contents from albums.txt? y/n" << endl;
	cin >> yesOrNo;
	if (yesOrNo == 'y')
	{
		fstream saveFile;
		saveFile.open("albums.txt", fstream::in | fstream::out | fstream::trunc);
		saveFile.close();
		clearConsole();
		cout << "All contents successfully deleted. Press enter to go back to the menu.";
		cin.ignore(1, '\n');
		cin.get();
		menu();
	}
	menu();
}

int getUserInputInteger()
{
	int userInteger;
	cin >> userInteger;
	cin.ignore(1, '\n');
	return userInteger;
}

string getUserInputString()
{
	string userString;
	getline(cin, userString);
	return userString;
}

void clearConsole()
{
	system("cls");
}