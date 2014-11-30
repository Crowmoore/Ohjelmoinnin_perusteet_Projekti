/*
***Harjoitustyö***
Kuvaus: Ohjelmaan voi tallentaa elokuvien ja albumien nimet sekä julkaisuvuodet.
		Ohjelma tallentaa tiedot erillisiin .txt tiedostoihin ja tarvittaessa tulostaa tiedot näytölle aakkosjärjestyksessä.
		Tiedostot on myös mahdollista tyhjentää.
Tekijä: Joel Kortelainen
Versio: 1.0
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <cctype>
#include <algorithm>
#include <ctype.h>
#include <utility>

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

vector<string> savedMovies;
vector<string> savedAlbums;
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
void loadSavedMovies();
int menuSelection();
bool compareStrings(string, string);

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
	case 0: return 0;
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
	clearConsole();
	fstream saveFile;
	saveFile.open("movies.txt", fstream::out | fstream::app);
	for each (movieInfo element in movie)
	{
		saveFile << element.movieName << " " << "(" << element.releaseYear << ")" << endl;
	}
	saveFile.close();
	movie.clear();
	cout << "All contents successfully saved. Press enter to go back to the menu.";
	cin.get();
}

void loadSavedMovies()
{
	savedMovies.erase(savedMovies.begin(), savedMovies.end());
	string savedMovie;
	fstream loadfile("movies.txt", fstream::in);
	while (getline(loadfile, savedMovie))
	{
		savedMovies.push_back(savedMovie);
	}
	loadfile.close();
}

void loadSavedAlbums()
{
	savedAlbums.erase(savedAlbums.begin(), savedAlbums.end());
	string savedAlbum;
	fstream loadfile("albums.txt", fstream::in);
	while (getline(loadfile, savedAlbum))
	{
		savedAlbums.push_back(savedAlbum);
	}
	loadfile.close();
}

void printSavedMovies()
{
	vector<string>::iterator stringSort;
	clearConsole();
	loadSavedMovies();
	sort(savedMovies.begin(), savedMovies.end(), compareStrings);
	for (stringSort = savedMovies.begin(); stringSort != savedMovies.end(); stringSort++)
	{
		cout << *stringSort << endl;
	}
	cout << endl << "Press enter to go back to the menu.";
	cin.get();
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
}

void clearSavedMovieFile()
{
	clearConsole();
	char yesOrNo;
	cout << "Are you sure you want to delete all contents from movies.txt? y/n" << endl;
	cin >> yesOrNo;
	if (yesOrNo == 'y')
	{
		savedMovies.clear();
		fstream saveFile;
		saveFile.open("movies.txt", fstream::in | fstream::out | fstream::trunc);
		saveFile.close();
		clearConsole();
		cout << "All contents successfully deleted. Press enter to go back to the menu.";
		cin.ignore(1, '\n');
		cin.get();
	}
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
}

void saveAlbumsToFile()
{
	clearConsole();
	fstream saveFile;
	saveFile.open("albums.txt", fstream::out | fstream::app);
	for each (albumInfo element in album)
	{
		saveFile << element.artistName << " - " << element.albumName << " " << "(" << element.releaseYear << ")" << endl;
	}
	saveFile.close();
	album.clear();
	cout << "All contents successfully saved. Press enter to go back to the menu.";
	cin.get();

}

void printSavedAlbums()
{
	vector<string>::iterator stringSort;
	clearConsole();
	loadSavedAlbums();
	sort(savedAlbums.begin(), savedAlbums.end(), compareStrings);
	for (stringSort = savedAlbums.begin(); stringSort != savedAlbums.end(); stringSort++)
	{
		cout << *stringSort << endl;
	}
	cout << endl << "Press enter to go back to the menu.";
	cin.get();
}

void clearSavedAlbumFile()
{
	clearConsole();
	char yesOrNo;
	cout << "Are you sure you want to delete all contents from albums.txt? y/n" << endl;
	cin >> yesOrNo;
	if (yesOrNo == 'y')
	{
		savedAlbums.clear();
		fstream saveFile;
		saveFile.open("albums.txt", fstream::in | fstream::out | fstream::trunc);
		saveFile.close();
		clearConsole();
		cout << "All contents successfully deleted. Press enter to go back to the menu.";
		cin.ignore(1, '\n');
		cin.get();
	}
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

bool compareStrings(string firstString, string secondString)
{
	transform(firstString.begin(), firstString.end(), firstString.begin(), ::toupper);
	transform(secondString.begin(), secondString.end(), secondString.begin(), ::toupper);
	return firstString.compare(secondString) < 0;
}