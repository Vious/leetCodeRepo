#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		if (num == 0) return "";
		string result = "";
		string strRound = "IVX";
		string order[4];
		int roundNum = 0;
		while (num) {
			int remain = num % 10;
			num /= 10;
			switch (roundNum)
			{
			case 0:
				strRound = "IVX";
				if (remain == 0) break;
				else if (remain <= 3) {
					for (int i = 0; i < remain; i++) {
						order[roundNum] += strRound[0];
					}
				}
				else if (remain == 4) {
					order[roundNum] += strRound[0];
					order[roundNum] += strRound[1];
				}
				else if (remain >= 5 && remain < 9) {
					order[roundNum] += strRound[1];
					for (int i = 0; i < remain - 5; i++) {
						order[roundNum] += strRound[0];
					}
				}
				else {
					order[roundNum] += strRound[0];
					order[roundNum] += strRound[2];
				}
				break;
			case 1:
				strRound = "XLC";
				if (remain == 0) break;
				else if (remain <= 3) {
					for (int i = 0; i < remain; i++) {
						order[roundNum] += strRound[0];
					}
				}
				else if (remain == 4) {
					order[roundNum] += strRound[0];
					order[roundNum] += strRound[1];
				}
				else if (remain >= 5 && remain < 9) {
					order[roundNum] += strRound[1];
					for (int i = 0; i < remain - 5; i++) {
						order[roundNum] += strRound[0];
					}
				}
				else {
					order[roundNum] += strRound[0];
					order[roundNum] += strRound[2];
				}
				break;
			case 2:
				strRound = "CDM";
				if (remain == 0) break;
				else if (remain <= 3) {
					for (int i = 0; i < remain; i++) {
						order[roundNum] += strRound[0];
					}
				}
				else if (remain == 4) {
					order[roundNum] += strRound[0];
					order[roundNum] += strRound[1];
				}
				else if (remain >= 5 && remain < 9) {
					order[roundNum] += strRound[1];
					for (int i = 0; i < remain - 5; i++) {
						order[roundNum] += strRound[0];
					}
				}
				else {
					order[roundNum] += strRound[0];
					order[roundNum] += strRound[2];
				}
				break;
			case 3:
				for (int i = 0; i < remain; i++) {
					order[roundNum] += "M";
				}
				break;
			default:
				break;
			}
			roundNum++;
		}

		for (int i = 3; i >= 0; i--)
			if (order[i] != "\0")
				result += order[i];

		return result;
	}
};



int main()
{
	Solution sl;
	while (1) {
		int input;
		cout << "please input a number: ";
		cin >> input;
		if (input == 0) break;
		cout << "Anwser is: " << sl.intToRoman(input) << '\n';
	}
	system("pause");
	return 0;
}