// TripleX.cpp : This file contains the 'main' function. Program execution begins and ends there.

//(Preprocessor Directive -> #include, Header File -> <iostream>.
#include <iostream>
#include <ctime>
// instead of using std for 3 different object of classes, we can use “using namespace std;” so we don't have to use it for specific object of classes.
using std::cout;
using std::endl;
using std::cin;
//using namespace std;


void IntroductionImage(int Difficulty)
{
    cout << "________________________________________________" << endl;
    cout <<"/                                                \\" << endl;
    cout <<"| _______________________________________________ |" << endl;
    cout <<"| |                                             | |" << endl;
    cout <<"| |  N = ?, ?, ?                                | |" << endl;
    cout <<"| |  C:\\> _                                     | |" << endl;
    cout <<"| |                                             | |" << endl;
    cout <<"| |                                             | |" << endl;
    cout <<"| |                                             | |" << endl;
    cout <<"| |                                             | |" << endl;
    cout <<"| |                                             | |" << endl;
    cout <<"| |                                             | |" << endl;
    cout <<"| |                                             | |" << endl;
    cout <<"| |_____________________________________________| |" << endl;
    cout <<"\\________________________________________________/" << endl;
    cout << "      \___________________________________/" << endl;

    cout << "Level: " << Difficulty << endl;
}


// void means this function will return no data.
bool MyGame(int Difficulty)
{ // Curly braces are the body function.
    IntroductionImage(Difficulty);

    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;
    int Sum = CodeA + CodeB + CodeC;
    int Product = CodeA * CodeB * CodeC;

    cout << "There are 3 numbers in the Code, They add up to " << Sum << " and multiplication up to " << Product <<" What are the 3 numbers?\n";

    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == Sum && GuessProduct == Product)
    {
        cout << "Encrypted \n";
        return true;
    }
    else
    {
        cout << "Failed \n";
        return false;
    }

    /*
    cout << "Just for loop\n";
    bool sss = true;
    while (sss == true)
    {
        int i = 0;
        for (i = 0; i <= 5; i++)
        {
            cout << i << "\n";
        }

        if (i >= 5)
        {
            sss = false;
        }
    }
    */
}


int main() // The parentheses are used to pass arguments into the function.
{
    srand(time(NULL)); // creates a new random sequence based on the time of day.

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    bool Loop = true;

    while (Loop)
    {
        bool LevelComplete = MyGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discards the buffer

        if (LevelComplete == true)
        {
            LevelDifficulty++;
        }
        else if (LevelComplete == false)
        {
            LevelDifficulty--;
        }

        
        if (LevelDifficulty <= 0)
        {
            Loop = false;
            cout << "FAILED, ALARM ACTIVATED";
        }
        else if (LevelDifficulty >= MaxDifficulty)
        {
            Loop = false;
            cout << "HACKED, IN FILES" << endl;
        }
    }
    return 0;
}


