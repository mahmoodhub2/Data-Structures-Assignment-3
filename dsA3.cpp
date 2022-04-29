/*
  FILE : dsA3.cpp
* PROJECT :  Assignment 3#
* PROGRAMMER : Mahmood Al-Zubaidi
* FIRST VERSION : 08/August/2021
* DESCRIPTION : The purpose of this function is to orgnize the inputted artist, title, and rating in structures and display them based on thier rating then traverse them based on rating
				then traversing them alphebaticlly based on the artist name.
*/


#include < map >
#include < string >
#include < iostream >
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;


void clearCRLF(char* str);

int main(void) {

	multimap<int, string> mm;
	multimap<string, int> mmArtist;


	string artist;
	string title;
	int rating;
	int total = 0;
	int total2 = 0;

	int prev[100];
	int inc=0;

	while (true) {

		cout << "Please enter the Artist of the song: ";
		getline(cin, artist);
		
		if (artist == ".") {
			break;
		}

		cout << "Please enter the title of the song: ";
		getline(cin, title);
		if (artist != "\t\t\t\t\t") {
			artist += "\t\t\t\t\t" + title;
		}
		else {
			artist += title;
		}

		
		cout << "Please enter the Rating of the song: ";
		int temp;
		cin >> temp;
		if (temp >= 1 && temp <= 5) {
			rating = temp;
		}
		else {
			cout << "out of range!";
		}

		//loop through the prev array
		//compare the rating with each array element
		// if one of the elements was identical to the rating
		for (int j = 1; j < 100; j++) {
			int found = 0;
		
		if (rating == prev[j]) {
			total = 0;
			total += (int)artist[0]; // get the ascii value of the first element of the newly inputted artist
			

			// loop through the multimap that contains the previously inputted values
			for (multimap<int, string>::iterator i = mm.begin(); i != mm.end(); ++i) {
				string str = i->second;
				total2 = 0;
				total2 += (int) str[0];
				
				// if the newly inputted rating is the same as the previously saved rating and the prevsly saved first elemtn of artist is more than the newly inputted one
				if ((i->first == rating) && (total2 > total)) {
					string sec = i->second; // get that saved artist first
					mm.erase(i); // delete the that iteration 
					mm.insert(make_pair(rating, artist)); // insert the newly inputted artist
					mm.insert(make_pair(rating, sec)); // then insert the deleted iteration
					found++;
					break;
				}
			}

		}
		if (found != 0) {
			break;
		}

		if (rating != prev[j]) {
			mm.insert(make_pair(rating, artist));
			break;
		}

		}
		
			
		inc++;
		prev[inc] = rating;


		mmArtist.insert(make_pair(artist, rating));

		cin.ignore();
	}

	cout << "\n\nlisted Based on rating" << endl;
	char a[10] = "Artist";
	char t[10] = "Title";
	char r[10] = "Rating";
	printf("\n%-35s 	%-35s	%-35s\n\n", a, t, r);
	for (multimap<int, string>::iterator i = mm.begin(); i != mm.end(); ++i) {
		cout << i->second << "\t\t\t\t\t" << i->first;
		cout << "\n";
	}



	cout << "\n\nlisted Based on artist" << endl;
	printf("\n%-35s 	%-35s	%-35s\n\n", a, t, r);
	for (multimap<string, int>::iterator i = mmArtist.begin(); i != mmArtist.end(); ++i) {
		cout << i->first << "\t\t\t\t\t" << i->second;
		cout << "\n";
	}


	string searchingSong;
	string searchingTitle;
	int oldRating;
	int newRating;
	cout << "\n\nEnter the artist of the searching song: ";
	getline(cin, searchingSong);
	searchingSong += "\t\t\t\t\t";
	cout << "Enter the title of the searching song: ";
	getline(cin, searchingTitle);
	string searchingInfo = searchingSong + searchingTitle;

	cout << "Enter the old rating of the searching song: ";
	cin >> oldRating;


	for (multimap<int, string>::iterator i = mm.begin(); i != mm.end(); ++i) {
		if (i->second == searchingInfo && i->first == oldRating) {
			cout << "Enter New rating: ";
			int temp2;
			cin >> temp2;
			if (temp2 >= 1 && temp2 <= 5) {
				newRating = temp2;
			}

			if (i->first != newRating) {
				string keeper = i->second;
				mm.erase(i);
				mm.insert(make_pair(newRating, keeper));
				break;
			}
		}
		
	}


	cout << "\n\nNew list based on the Artist" << endl;
	printf("\n%-35s 	%-35s	%-35s\n\n", a, t, r);
	for (multimap<string, int>::iterator i = mmArtist.begin(); i != mmArtist.end(); ++i) {
		cout << i->first << "\t\t\t\t\t" << i->second;
		cout << "\n";
	}

	cout << "\n\nNew list based on the rating" << endl;
	printf("\n%-35s 	%-35s	%-35s\n\n", a, t, r);
	for (multimap<int, string>::iterator i = mm.begin(); i != mm.end(); ++i) {
		cout << i->second << "\t\t\t\t\t" << i->first;
		cout << "\n";
	}


	return 0;
}




/** Function: clearCRLF
* Description: this function replaces the '\n' with the '\0' for the end of the line of the string.
* Parameters: a pointer to the variable that contains the user's input
* Returns: nothing.
*/
void clearCRLF(char* str) {
	char* whereIsCRLF = strchr(str, '\n');
	if (whereIsCRLF != NULL)
	{
		*whereIsCRLF = '\0';
	}
}