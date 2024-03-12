#include <iostream>
#include <cstring>
using namespace std;

//THIS FUCNTION FINDS THE MINIMUM DISCTANCE TOWARDS GAS STATION
int findmin(char s[]) {
	long unsigned int m;
	int vMin = 999999;
	for (m = 0; m < strlen(s); m++) {
		if (s[m] >= 48) {
			if (s[m] < vMin) {
				vMin = s[m];
			}
		}
	}
	return vMin;
}
 //THIS FUCNTION FINDS THE NUMBER OF STARS SUCH AS NUMBER OF CLOSE DISTANT GAS STATIONS
int stars_count(char s[]) {
	long unsigned int i;
	int number = 0;
	for (i = 0; i < strlen(s); i++) {
		if (s[i] == '*') {
			number++;
		}
	}
	return number;
}

int main() {
	cout << "Input the gas station data:" << endl;
	char gas[100], updated_gas[100];
	char c;
	int i = 0;
	int k = 0;
	cin.get(c);
	while (c != '\n') {
		gas[i++] = c;
		cin.get(c);
	}
	gas[i++] = ' ';
	gas[i] = '\0';
	long unsigned int j;
	for (j = 0; j < strlen(gas); j++) {
		if (gas[j - 1] == 32 && gas[j + 1] == 32) {
			if (gas[j] >= 48 && gas[j] <= 53) {
				updated_gas[k++] = gas[j - 2];
				updated_gas[k++] = '(';
				updated_gas[k++] = gas[j];
				updated_gas[k++] = ')';
				updated_gas[k++] = ' ';
			}

		}
	}
	updated_gas[k] = '\0';
	char copy[100];
	char min;
	min = findmin(updated_gas);
	for (j = 0; j < strlen(updated_gas); j++) {
		if (updated_gas[j] == min) {
			updated_gas[j + 2] = '*';
		}

	}
	int w = 0;
	for (j = 0; j < strlen(updated_gas); j++) {
		if (updated_gas[j] != ' ') {
			copy[w++] = updated_gas[j];
		}
	}
	copy[w] = '\0';
	int num;
	num = stars_count(copy);
	cout << "The nearby gas stations map is:" << endl;
	for (j = 0; j < strlen(copy); j++) {
		if (65 <= copy[j] && copy[j] <= 90) {
			if (j == 4 || j == 5 || j == 8 || j == 9 || j == 10) { //THIS OUTPUTS THE NUMBER OF SPACES IN THE FIRST LINE OF MAP
				cout << " ";
			}
			if (12 <= j && j <= 15) { //THIS MAPS THE FIRST THREE GAS STAIONS OF THE MAP
				cout << endl;
			}
			if (16 <= j && j <= 25) { // THIS OUTPUTS THE NUMBER OF SPACES IN THE SECOND LINE OF MAP
				cout << " ";
			}
            //BELOW IF : THIS MAPS THE SECOND LINE OF THREE GAS STATIONS
			if ((j==24 && (0<=num && num<=4)) || (j == 25 && (1 <= num && num <= 5)) || (j == 26 && (2 <= num && num <= 6)) || (j == 27 && (3 <= num && num <= 7)) || (j == 28 && (4 <= num && num <= 8)) || (j == 29 && (5 <= num && num <= 9)) || (j == 30 && (6 <= num && num <= 10)) || (j == 30 && num == 7) || (j == 30 && num == 8) || (j == 30 && num == 9) || (j == 30 && num == 10)) {
				cout << endl;
			}
            //THIS OUTPUTS THE NUMBER OF SPACES IN THE THIRD LINE OF MAP
			if ((j==28 && (0 <= num && num <= 4)) || (j == 29 && (1 <= num && num <= 5)) || (j == 30 && (2 <= num && num <= 6)) || (j == 31 && (3 <= num && num <= 7)) || (j == 32 && (4 <= num && num <= 8)) || (j == 33 && (5 <= num && num <= 9)) || (j == 34 && (6 <= num && num <= 10)) || (j == 35 && (7 <= num && num <= 10)) || (j == 35 && (8 <= num && num <= 10)) || (j == 35 && num == 9) || (j == 35 && num == 10)) {
				cout << " ";
			}
            //THIS OUTPUTS THE NUMBER OF SPACES IN THE THIRD LINE OF MAP
			if ((j == 32 && (0 <= num && num <= 4)) || (j == 33 && (1 <= num && num <= 5)) || (j == 34 && (2 <= num && num <= 6)) || (j == 35 && (3 <= num && num <= 7)) || (j == 36 && (4 <= num && num <= 8)) || (j == 37 && (5 <= num && num <= 9)) || (j == 38 && (6 <= num && num <= 10)) || (j == 39 && num == 7) || (j == 40 && num == 8) | (j == 40 && num == 9) | (j == 40 && num == 10)) {
				cout << " ";
			}
            //BELOW IF : THIS MAPS THE THIRD LINE OF THREE GAS STATIONS
			if ((j == 36 && (0 <= num && num <= 4)) || (j == 37 && (1 <= num && num <= 5)) || (j == 38 && (2 <= num && num <= 6)) || (j == 39 && (3 <= num && num <= 7)) || (j == 40 && (4 <= num && num <= 8)) || (j == 41 && (5 <= num && num <= 9)) || (j == 42 && (6 <= num && num <= 10)) || (j == 43 && num == 7) || (j == 44 && num == 8) || (j == 45 && num == 9) || (j == 45 && num == 10)) {
				cout << endl;
			}

		}

		cout << copy[j];
	}

	return 0;
}