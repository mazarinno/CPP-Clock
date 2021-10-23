#include<iostream>
#include<string>
#include <stdlib.h>

/* Clock program by Mitch Sfakianos, August 19, 2021 */

using namespace std;

int hour = 0; /* I initialized each time value as a global variable */
int twelveHour = 0;
int minute = 0;
int second = 0;

void fillLine() {  /* this function returns a full line for making the shapes of the clock and menu to avoid repetitive code */
	for (int j = 1; j <= 26; j++) {
		cout << "*";
	}
}

void displayMenu() {
	for (int i = 1; i <= 6; i++) {
		if (i == 1) { /* This represents the top line of the menu */
			fillLine();
		}
		else if (i < 6) {
			cout << endl;

			for (int j = 1; j <= 26; j++) { /* This block is the middle of the menu */
				if (j == 1 || j == 26) {
					cout << "*";
				}
				else if (i == 2 && j == 3) {
					string optionOne = "1 - Add One Hour";
					cout << optionOne;
					j = j + optionOne.length() - 1;
				}
				else if (i == 3 && j == 3) {
					string optionTwo = "2 - Add One Minute";
					cout << optionTwo;
					j = j + optionTwo.length() - 1;
				}
				else if (i == 4 && j == 3) {
					string optionThree = "3 - Add One Second";
					cout << optionThree;
					j = j + optionThree.length() - 1;
				}
				else if (i == 5 && j == 3) {
					string optionFour = "4 - Exit Program";
					cout << optionFour;
					j = j + optionFour.length() - 1;
				}
				else {
					cout << ' ';
				}
			}
		}
		else { /* This represents the bottom line of the menu */
			cout << endl;

			fillLine();
			
			cout << endl;
		}
	}
}

int getInput() {
	int input;
	cin >> input;
	return input;
}

string timeConverter(int timeValue) { /* This function will add a leading 0 to a number if it is under 10 */
	if (timeValue < 10) {
		string time = to_string(timeValue);
		return('0' + time);
	}
	else {
		string time = to_string(timeValue);
		return time;
	}
}

void displayClock(int input) {
	switch (input) {
		case 1:
			hour++;
			twelveHour++;
			break;
		case 2: 
			minute++;
			break;
		case 3: 
			second++;
			break;
		case 4:
			exit(200);
		default:
			exit(400); /* Switch statement ends with exiting at 400 if the input wasn't expected */
	}

	if (hour == 24) { /* Minutes and seconds share global variables, but I have made separate ones for the 12 and 24 hours */
		hour = 0;
	}

	if (minute == 60) { /* If the minute or second reaches 60, it is reset to 0 and the value above it increases by one */
		minute = 0;
		hour++;
		twelveHour++;
	}

	if (second == 60) {
		second = 0;
		minute++;
	}

	if (hour == 0) { /* Resetting the value back to 12 at midnight in military time */
		twelveHour = 12;
	}

	if (twelveHour == 13) { /* Then, for each time the standard clock reaches 12, it will then show 1 */
		twelveHour = 1;
	}

	string noonMarker = (hour >= 12) ? "PM" : "AM";  /* This shows AM or PM in the 12 clock based on the time*/

	for (int i = 1; i <= 4; i++) {
		if (i == 1) {  /* This if block represents the top lines of the 12 and 24 clocks */
			fillLine();

			cout << ' ';
			
			fillLine();
		}
		else if (i < 4) { /* This block represents the middle section of both clocks */
			cout << endl;

			for (int j = 1; j <= 26; j++) { /* This block is the 12 clock */
				if (j == 1 || j == 26) {
					cout << "*";
				}
				else if (j == 8 && i == 2) { /* Outputting the name of the clock in the middle of the box and adjusting the loop to accomodate for the space it took up */
					string clockName = "12-Hour Clock";
					cout << clockName;
					j = j + clockName.length() - 1;
				}
				else if (j == 10 && i == 3) { /* This is the bottom line of the 12 clock, which is affected by the user */
					string time = timeConverter(twelveHour) + ':' + timeConverter(minute) + ':' + timeConverter(second) + ' ' + noonMarker;
					cout << time;
					j = j + time.length() - 1;
				}
				else {
					cout << ' ';
				}
			}

			cout << ' ';

			for (int j = 1; j <= 26; j++) { /* This block is the 24 clock */
				if (j == 1 || j == 26) {
					cout << "*";
				}
				else if (j == 8 && i == 2) {
					string clockName = "24-Hour Clock";
					cout << clockName;
					j = j + clockName.length() - 1;
				}
				else if (j == 10 && i == 3) { /* This is the bottom line of the 24 clock, which is affected by the user */
					string time = timeConverter(hour) + ':' + timeConverter(minute) + ':' + timeConverter(second);
					cout << time;
					j = j + time.length() - 1;
				}
				else {
					cout << ' ';
				}
			}
		}
		else { /* This block represents the bottom line of both clocks */
			cout << endl;

			fillLine();

			cout << ' ';

			fillLine();

			cout << endl;
		}
	}
}

void clearScreen() { /* The clear screen function simply uses the system command to do so*/
	system("CLS");
}

int main() {
	while (true) {
		displayMenu();
		int input = getInput();
		clearScreen();
		displayClock(input);
	}
}