#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

// creates a structure called Hockey with 5 members
struct hockey
{
	string name = "";
	int goals = 0;
	int penelty = 0;
	int assists = 0;
	int gamesPlayed = 0;
};

//function definitions have the array variables of structure type and a variable for the size of the array
void athleteinfo(hockey player[], int num);
void alphabetize(hockey player[], int num);
void display(hockey player[], int num);

int main() {
	hockey player[15]; // creates a variable of structure type, 15 is the max number of user inputs allowed. 
	int num;
	cout << "How many players do you wish to enter data for?\n";
	cin >> num; // value taken to set a limit for the array
	athleteinfo(player, num); // calls the athlete function
	alphabetize(player, num); // calss the alphabetize function
	display(player, num); // calls the display function
	return 0;
}

// athlete funciton takes in the information of the athlete and passes the structure array back to the main function
void athleteinfo(hockey player[], int num) {
	char name[20];
	for (int i = 0; i < num; i++)
	{
		cout << endl;
		cout << "Please enter the name for player #" << i + 1 << " in the form Smith, John." << endl;
		cin.ignore(20, '\n'); // this discards upto 20 characters or the '\n' operator
		cin.getline(name, 20); // takes in a string of characters to avoid the space delimiter
		player[i].name = name; // assigns the string characters to the name member of the hockey structure
		cout << "How many games did player #" << i + 1 << " play?\n";
		cin >> player[i].gamesPlayed; // takes in a value for the number of games played
		cout << "How many goals did player #" << i + 1 << " have?\n";
		cin >> player[i].goals; // takes in a value for the number of goals
		cout << "How many assists did player #" << i + 1 << " have?\n";
		cin >> player[i].assists; // takes in a value for the number of assists
		cout << "How many penelties did player #" << i + 1 << " have?\n";
		cin >> player[i].penelty; // takes in a value for the number of penelty/penelties
		
	}
	cout << endl;
	
}

// organizes the strings array in alphabetical order
void alphabetize(hockey player[], int num) {
	string tempName;
	int tempGoals, tempPlayed, tempPenelty, tempAssists;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (player[i].name < player[j].name)
			{
				tempName = player[i].name;
				player[i].name = player[j].name;
				player[j].name = tempName;
				tempGoals = player[i].goals;
				player[i].goals = player[j].goals;
				player[j].goals = tempGoals;
				tempPenelty = player[i].penelty;
				player[i].penelty = player[j].penelty;
				player[j].penelty = tempPenelty;
				tempPlayed = player[i].gamesPlayed;
				player[i].gamesPlayed = player[j].gamesPlayed;
				player[j].gamesPlayed = tempPlayed;
				tempAssists = player[i].assists;
				player[i].assists = player[j].assists;
				player[j].assists = tempAssists;
			}
		}
	}
}

// displays the arrays in a table
void display(hockey player[], int num) 
{
	int goals = 0, assists = 0, gamesPlayed = 0, penalties = 0;
	for (int n = 0; n < num; n++)
	{
		goals += player[n].goals;
		assists += player[n].assists;
		gamesPlayed += player[n].gamesPlayed;
		penalties += player[n].penelty;
	}

	cout << "Name: " << setw(29) << "Games Played: " << setw(15) << "Goals: " << setw(15) << "Assists: " << setw(15) << "Penelties: " << endl;
	for (int n = 0; n < num; n++)
	{
		cout << player[n].name << setw(15) << player[n].gamesPlayed << setw(22) << player[n].goals << setw(13) << player[n].assists << setw(13) << player[n].penelty << endl;
	}
	cout << "TOTAL:" << setw(16) << gamesPlayed << setw(22) << goals << setw(13) << assists << setw(13) << penalties << endl <<endl;
}
