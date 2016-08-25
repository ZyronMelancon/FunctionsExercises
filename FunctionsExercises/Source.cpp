/*
Exercise 1 answer:
3
2
1
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>

using namespace std;

int ex2func(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

float ex2func(float input[3]) //Exercise 3. This is called prototyping and redefinition.
{
	float biggernum;
	float t;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (input[y] > input[y + 1])
			{
				t = input[y];
				input[y] = input[y + 1];
				input[y + 1] = t;
			}
		}
	}

	biggernum = input[0];
	return biggernum;

}

float ex2()
{
	float input[3];

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter value " << i + 1 << ": ";
		cin >> input[i];
		cout << endl;
	}

	cout << "The smaller number is: " << ex2func(input[0], input[1]) << endl;

	system("pause");
	system("cls");
	return 0;
}



float ex3func(float numtohalf)
{
	float result = numtohalf / 2;
	return result;
}



string CoinToss()
{
	int headsortails = rand() % 2 + 1;
	string side;

	if (headsortails == 2)
		side = "Heads";
	else
		side = "Tails";

	return side;
}

int ex5()
{
	int numbercoins;
	int tossnumber = 0;

	cout << "How many coins would you like to toss?" << endl;
	cin >> numbercoins;

	for (; numbercoins > 0; numbercoins--)
	{
		tossnumber++;
		cout << "Toss #" << tossnumber << " landed on: " << CoinToss() << endl;
	}

	system("pause");
	system("cls");
	return 0;
}


/*
Exercise 6 answers:

a. This function needs to return a value.
b. This function would create an error at "else".
c. Main needs to return a value.

*/


int SumTo(int n)
{
	int sum = 0;

	for (; n > 0; n--)
		sum = sum + n;

	return sum;
}

int ex7()
{
	int result = SumTo(3); //result = 1 + 2 + 3 = 6
	std::cout << result << std::endl;
	result = SumTo(15); //result should now be 120
	std::cout << result << std::endl;

	system("pause");
	system("cls");
	return 0;
}



int SumArray(int arrayin[], int numarray)
{
	int sum = 0;
	numarray--;

	for (; numarray >= 0; numarray--)
		sum = arrayin[numarray] + sum;

	return sum;
}

int ex8()
{
	int integer_array[5] = { 7, 3, 2, 4, 9 };
	int result = SumArray(integer_array, 5); //result = 25
	std::cout << result << std::endl;

	system("pause");
	system("cls");
	return 0;
}



int MinInArray(int arrayin[], int numarray)
{
	int t;
	int minarray;

	for (int x = 0; x < numarray; x++)
	{
		for (int y = 0; y < numarray-1; y++)
		{
			if (arrayin[y] > arrayin[y + 1])
			{
				t = arrayin[y];
				arrayin[y] = arrayin[y + 1];
				arrayin[y + 1] = t;
			}
		}
	}

	minarray = arrayin[0];

	return minarray;
}

int ex9()
{
	int integer_array[7] = { 10, 15, 7, 4, 13, 19, 8 };
	int result = MinInArray(integer_array, 7); //result = 4
	std::cout << result << std::endl;	system("pause");	system("cls");	return 0;
}



void MultiplyByIndex(int arrayin[], int arrayout[], int numarray)
{
	numarray--;
	for (; numarray >= 0; numarray--)
		arrayout[numarray] = arrayin[numarray] * numarray;
}

int ex10()
{
	int integer_array[7] = { 10, 15, 7, 4, 13, 19, 8 };
	int output_array[7] = {};
	MultiplyByIndex(integer_array, output_array, 7);
	//output_array should be {0, 15, 14, 12, 52, 95, 48};
	return 0;
}



void duoarraysum(int arrayone[], int arraytwo[], int numarray, int arraysum[])
{
	numarray--;
	for (; numarray >= 0; numarray--)
		arraysum[numarray] = arrayone[numarray] + arraytwo[numarray];
}

int ex11()
{
	int arrayone[5] = { 5, 6, 7, 8, 9 };
	int arraytwo[5] = { 5, 6, 7, 8, 9 };
	int arraysum[5] = {};
	duoarraysum(arrayone, arraytwo, 5, arraysum);
	for (int i = 0; i < 5; i++)
		cout << arraysum[i] << endl;

	system("pause");
	system("cls");
	return 0;
}



void arrayrunsum(int arrayin[], int num)
{
	for (int i = 0; i < num-1; i++)
		arrayin[i + 1] = arrayin[i] + arrayin[i + 1];
}

int ex12()
{
	int input_array[4] = { 3, 2, 4, 7 };
	arrayrunsum(input_array, 4);

	for (int i = 0; i < 4; i++)
		cout << input_array[i] << endl;

	system("pause");
	system("cls");
	return 0;
}



int finder(int arrayin[], int num, int find)
{
	int slot = 0;
	for (; slot < num; slot++)
	{
		if (arrayin[slot] == find)
			return slot;
		else
			continue;
	}
	return -1;
}



int ex13()
{
	int arrayin[4] = { 1, 2, 3, 4 };
	cout << "The number you are looking for is in slot #" << finder(arrayin, 4, 3) << endl;
	system("pause");
	system("cls");
	return 0;
}



int Split(int arrayin[], int num, int arrayout[], int arrayout2[])
{
	int posnum = 0;

	for (int i = 0; i < num - 1; i++)
		if (arrayin[i] >= 0)
		{
			arrayout[i] = arrayin[i];
			posnum++;
		}
		else
			arrayout2[i] = arrayin[i];

	return posnum;
}



int ex14()
{
	int myarray[4] = { -4, 3, 1, -3 };
	int posarray[4] = {};
	int negarray[4] = {};

	cout << "The amount of positive numbers in the array is: " << Split(myarray, 4, posarray, negarray) << endl;

	system("pause");
	system("cls");

	return 0;
}



int ex15(int x, int y)
{
	for (int i = 0; i < y; i++)
		x = x * x;
	return x;
}

/*Write a function that takes in an array of integers, and the size of the array. The function
should print out the “look and say” sequence for the array. The look and say sequence
works by printing out how many of the same number there are in a row followed by that
number.
For example, if the array was {1, 1, 1, 1} the function would print out “4, 1” because there
are four ones.
If the array was {1, 2, 2, 2, 3, 4} the function would print out “1,1,3,2,1,3,1,4” because there
is “one 1, three 2s, one 3, one 4”.
If the array is {1,2,2,1,5,1,1,7,7,7,7,1,1,1,1,1,1,1,1} the function should print out
“1,1,2,2,1,1,1,5,2,1,4,7,8,1”
Write your own code to test the function.*/

int lookAndSay(int arrayin[], const int num)
{
	int repeat = 1;

	for (int i = 0; i < num - 1; i++)
	{
		if (arrayin[i] == arrayin[i + 1])
			repeat++;
		else
		{
			cout << repeat << ", " << arrayin[i] << endl;
			repeat = 1;
		}
	}
	cout << repeat << ", " << arrayin[num-1] << endl;

	return 0;
}

int ex16()
{
	int arrayin[19] = { 1,2,2,1,5,1,1,7,7,7,7,1,1,1,1,1,1,1,1 };

	lookAndSay(arrayin, 19);

	system("pause");
	system("cls");

	return 0;
}


int rockpaperscissors()
{
	return rand() % 3 + 1;
}

bool checkchoice(int choice)
{
	if (choice > 0 && choice < 4)
		return true;
	else
		return false;
}

int whowins(int choice, int computer)
{
	if (choice == 1 && computer == 3)
		return 1;
	else if (choice == computer)
		return 3;
	else if (choice > computer && choice != 3)
		return 1;
	else
		return 2;
}

int ex17()
{
	int choice;
	int compchoice;
	int winner;
	bool end = false;

	while (!end)
	{
		string choices[3] = { "rock", "paper", "scissors" };

		cout << "Welcome to Rock, Paper, Scissors!" << endl;
		cout << "Type 1 for rock, 2 for paper, or 3 for scissors: ";
		cin >> choice;

		if (checkchoice(choice))
		{
			compchoice = rockpaperscissors();

			cout << "You have chosen " << choices[choice - 1] << " and the computer has chosen " << choices[compchoice - 1] << "!" << endl;

			winner = whowins(choice, compchoice);

			switch (winner)
			{
			case 1:
				cout << "You won!" << endl;
				end = true;
				break;
			case 2:
				cout << "You lost!" << endl;
				end = true;
				break;
			case 3:
				cout << "Rematch!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		else
		{
			cout << "That is an invalid choice! Try again." << endl;
			system("pause");
			system("cls");
			continue;
		}
	}

	system("pause");
	system("cls");

	return 0;
}

int main()
{
/*	ex2();
	ex5();
	ex7();
	ex8();
	ex9();
	ex11();
	ex12();
	ex13();
	ex14();*/
	ex16();
	ex17();
	return 0;
}