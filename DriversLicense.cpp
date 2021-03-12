/*
Patrick Langley
Chapter 1-7: Final
Driver's License Exam-Determine who passes or fails the exam, by comparing the exam answers to the exam takers' answers.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Get_Takers_Answers(string textFile, const int SZ);
void Put_File_Answers_To_Array(string textFile, char takerAnswers[], const int SIZE);

int main()
{
	const int SIZE = 20;
	const char EXAM_ANSWERS[SIZE] = { 'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B' };
	char takerAnswers[SIZE]; // array for exam taker's answers
	string textFile;
	int i, correctAnswers, wrongAnswers;

	cout << "\nEnter a text file name>";
	getline(cin, textFile);

	Get_Takers_Answers(textFile, SIZE);

	Put_File_Answers_To_Array(textFile, takerAnswers, SIZE);

	correctAnswers = 0;
	wrongAnswers = 0;
	cout << "\nThe numbers of the questions answered incorrectly are:\n";
	for (i = 0; i < SIZE; i++)
	{
		if (takerAnswers[i] == EXAM_ANSWERS[i])
		{
			correctAnswers++;
		}
		else
		{
			wrongAnswers++;
			cout << i + 1 << " ";
		}
	}
	cout << endl;
	cout << "\nThe number answered correctly is " << correctAnswers << endl;
	cout << "\nThe number answered incorrectly is " << wrongAnswers << endl;
	if (correctAnswers >= 15)
	{
		cout << "\nCongratulations...you passed the exam!";
	}
	else
	{
		cout << "\nSorry, you did not pass the exam";
	}

	cout << endl << endl;
	system("pause");
	return (0);
}
void Get_Takers_Answers(string textFile, const int SZ)
{
	ofstream takersFile(textFile);
	char answer;

	for (int i = 0; i < SZ; i++)
	{
		cout << "\nEnter exam taker's answer #" << i + 1 << ">";
		cin >> answer;
		while (answer < 'A' || answer > 'D')
		{
			cout << "\nInput error, answer must be A, B, C, or D";
			cout << "\nre-enter answer>";
			cin >> answer;
		}

		takersFile << answer << "\n";
	}
	takersFile.close();
}
void Put_File_Answers_To_Array(string textFile, char takerAnswers[], const int SIZE)
{
	char answer;
	int i;
	ifstream takersText;
	takersText.open(textFile);
	if (takersText.fail())
	{
		cout << "\nText file not found, program will terminate!";
		cout << endl << endl;
		system("pause");
		exit(0);
	}
	i = 0;
	takersText >> answer;
	while (takersText)
	{
		takerAnswers[i] = answer;
		i++;
		takersText >> answer;
	}
	takersText.close();
}