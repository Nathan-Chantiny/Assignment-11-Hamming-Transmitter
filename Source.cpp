#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool userInputCheck(string input) {
	for (int i = 0; i < input.size(); i++) {
		char c = input[i];
		if (c >= 48 && c <= 57) {}
		else {
			return false;
		}
	}

	if (stoi(input) >= 0 && stoi(input) <= 15) {
		return true;
	}
	else {
		return false;
	}
}

vector<int> decToBaseTwo(int num) {
	vector<int> result;

	int a = num;
	int b = 0;

	while (a > 0) {
		a = a / 2;
		b++;
	}

	int mod = 0;
	int d = num;

	for (int i = 0; i < b; i++) {
		d = num;
		for (int j = 0; j < b - i; j++) {
			mod = d % 2;
			d = d / 2;
		}

		result.push_back(mod);
	}

	while (result.size() < 4) {
		result.insert(result.begin(), 0);
	}

	return result;
}

vector<int> base2ToHam(vector<int> num) {
	int S1 = (num[0] + num[1] + num[3]) % 2;
	int S2 = (num[0] + num[2] + num[3]) % 2;
	int S4 = (num[1] + num[2] + num[3]) % 2;

	return { S1, S2, num[0], S4, num[1], num[2], num[3] };
}

void output(int num, vector<int> result) {
	cout << "\nOriginal number: " << num << "\n";
	cout << "Hamming    code: [ ";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	cout << " ]\n";
}

int main() {
	// 15
	output(15, base2ToHam(decToBaseTwo(15)));

	// 7
	output(7, base2ToHam(decToBaseTwo(7)));

	// 12
	output(12, base2ToHam(decToBaseTwo(12)));

	// 2
	output(2, base2ToHam(decToBaseTwo(2)));

	// 6
	output(6, base2ToHam(decToBaseTwo(6)));

	while (true) {
		cout << "\nEnter a number: ";
		string num;
		cin >> num;

		if (userInputCheck(num)) {
			int n = stoi(num);
			output(n, base2ToHam(decToBaseTwo(n)));
		}
		else {
			cout << "not a valid number\n";
		}

		cout << "\nWould you like to go again(Y or N)? ";
		string answer;
		cin >> answer;

		if (answer != "Y" && answer != "y") {
			break;
		}
	}

	cout << "Goodbye!\n";
}