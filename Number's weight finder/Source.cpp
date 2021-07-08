#include <iostream>
#include <fstream>
using namespace std;
void main() {

	ifstream fin;
	ofstream fout;
	int weight[15];
	int number[15];
	int choosed_number;
	int current_number;
	int specifity;
	int curr_spec = 0;
	char cache[16];
	char buff[2] = { 0 ,'\0' };
	int step = 0;
	int c = 0;
	int errors = 0;
	bool finded = false;
	cout << "choose a number (0-9)" << endl;
	cin >> choosed_number;
	fin.open("file.txt");
	for (int i = 0; i <= choosed_number; i++) {
		fin >> cache;
		if (i == choosed_number)
			for (int c = 0; c < 15; c++)
			{
				buff[0] = cache[c];
				
				weight[c] = atoi(buff);
			}
	}
	fin.close();
	cout << "your number: " << endl;
	for (int c = 0; c < 15; c++)
	{
		if (c != 0 && c % 3 == 0)
			cout << endl;
		if (weight[c] == 0)
		{
			cout << "  ";
			continue;
		}
		cout << weight[c] << ' ';
	}
	cout << endl;
	cout << "Enter specifity" << endl;
	cin >> specifity;
	while (finded != true) {
		step++;
		finded = true;
		cout << "Step " << step << endl;
		for (int i = 0; i <= 9; i++) {
			finded = true;
			current_number = i;
			fin.open("file.txt");
			for (int j = 0; j <= current_number; j++) {
				fin >> cache;
				if (j == current_number) {
					for (int c = 0; c < 15; c++)
					{
						buff[0] = cache[c];
						number[c] = atoi(buff);
					}
					break;
				}
			}
			fin.close();
			for (int c = 0; c < 15; c++)
			{
				if (number[c] != 0)
					curr_spec = curr_spec + weight[c];
			}
			if (choosed_number == current_number) {
				if (curr_spec > specifity)
					cout << "Number " << current_number << " detected successfully" << endl;
				else {
					cout << "Number " << current_number << " detected wrong" << endl;
					errors++;
					for (int k = 0; k < 15; k++)
					{
						if (number[k] == 1) {
							weight[k]++;
						}
					}
					cout << "Current weight state:" << endl;
					for (int c = 0; c < 15; c++)
					{
						if (c != 0 && c % 3 == 0)
							cout << endl;
						cout << weight[c] << '\t';
					}
					cout << endl;
				}
			}
			else {
				if (curr_spec > specifity) {
					cout << "Number " << current_number << " detected wrong" << endl;
					errors++;
					for (int k = 0; k < 15; k++)
					{
						if (number[k] == 1) {
							weight[k]--;
						}
					}
					cout << "Current weight state:" << endl;
					for (int c = 0; c < 15; c++)
					{
						if (c != 0 && c % 3 == 0)
							cout << endl;
						cout << weight[c] << '\t';
					}
					cout << endl;
				}
				else cout << "Number " << current_number << " detected successfully" << endl;
			}
			curr_spec = 0;
		}
		if (errors != 0) finded = false;
		errors = 0;
	}
	cout << "Finded weight: " << endl;
	for (int c = 0; c < 15; c++)
	{
		if (c != 0 && c % 3 == 0)
			cout << endl;
		cout << weight[c] << '\t';
	}
}