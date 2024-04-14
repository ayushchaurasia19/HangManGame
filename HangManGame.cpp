#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector>
#define MAX_ATTEMPTS 6 //macro for defining max attempts is 6
using namespace std;

class HangManGame{
    private:
        string secretWord, currentWord;
        int attemptsLeft;
        vector <int> guessedLetters;
        
        string getRandomWord(){
            vector <string> words = {"maruti","honda","audi","toyota","mercedes","hyundai","mahindra","skoda"};
            int index = rand() % words.size();
            return words[index]; //returns a random car brand string
        }
        
        //returns true if the letter exists in the guessedLetters string, else returns false since the pointer is equal to guessedLetters.end()
        bool alreadyGuessed(char letter){
            return find (guessedLetters.begin(),guessedLetters.end(),letter) != guessedLetters.end(); 
        }

        //checks if the letter entered is a correct guess, if true, currentWord's index gets replaced by the letter, else returns false
        bool updateCurrentWord(char letter){
            bool correctGuess = false;
            for(int i = 0; i < secretWord.length(); i++){
                if(secretWord[i] == letter){
                    correctGuess = true;
                    currentWord[i] = letter;
                }
            }
            guessedLetters.push_back(letter);
            return correctGuess;
        }

        //displays the currentWord, attempts left, and history of guessed letters by the user
        void displayGameInfo(){
            cout << "Word : " << currentWord << endl;
            cout << "Attempts Left : " << attemptsLeft << endl;
            cout << "Guessed Letters : ";
            for(char letter : guessedLetters){
                cout << letter;
            }
            cout << endl;
        }

        // function to progressively draw the hangman 
        void drawHangman(int attemptsLeft) 
        { 
            if (attemptsLeft == 5) { 
                cout << "   _____" << endl; 
                cout << "  |     |" << endl; 
                cout << "  |     O" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
            } 
            else if (attemptsLeft == 4) { 
                cout << "   _____" << endl; 
                cout << "  |     |" << endl; 
                cout << "  |     O" << endl; 
                cout << "  |     |" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
            } 
            else if (attemptsLeft == 3) { 
                cout << "   _____" << endl; 
                cout << "  |     |" << endl; 
                cout << "  |     O" << endl; 
                cout << "  |    /|" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
            } 
            else if (attemptsLeft == 2) { 
                cout << "   _____" << endl; 
                cout << "  |     |" << endl; 
                cout << "  |     O" << endl; 
                cout << "  |    /|\\" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
            } 
            else if (attemptsLeft == 1) { 
                cout << "   _____" << endl; 
                cout << "  |     |" << endl; 
                cout << "  |     O" << endl; 
                cout << "  |    /|\\" << endl; 
                cout << "  |    /" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
            } 
            else if (attemptsLeft == 0) { 
                cout << "   _____" << endl; 
                cout << "  |     |" << endl; 
                cout << "  |     O" << endl; 
                cout << "  |    /|\\" << endl; 
                cout << "  |    / \\" << endl; 
                cout << "  |" << endl; 
                cout << "  |" << endl; 
            } 
        } 


    public:
        //constructor to initialize the game    
        HangManGame(){
            srand(static_cast<unsigned int> (time(nullptr))); //seeds the random number generator with the current time, to ensure that the 
            secretWord = getRandomWord();                     //sequence of numbers produced by rand() is different each time the program runs
            currentWord = string (secretWord.length() , '_');
            attemptsLeft = MAX_ATTEMPTS;
        }

        void play(){
            cout << "Welcome to the Hang Man game!" << endl;
            cout << "The secret word is a famous car brand." << endl;
            cout << "Attempts Left : " << attemptsLeft << endl;
            while (attemptsLeft > 0){
                displayGameInfo();
                char letter;
                cout << "Enter a Letter : " << endl;
                cin >> letter;
                if(isalpha(letter)){
                    letter = tolower(letter);
                    if(alreadyGuessed(letter)){
                        cout << "You have already guessed this letter :( " << endl; 
                    }
                    else{
                        bool correctGuess = updateCurrentWord(letter); // checks if the guess is correct and updates the currentWord accordingly
                        if(correctGuess){
                            cout << "Good Guess!" << endl;
                            if(currentWord == secretWord){
                                displayGameInfo();
                                cout << "You guessed the word correctly, congrats :) " << endl;
                                return;
                            }
                        }
                        else{
                            cout << "Incorrect Guess :( " << endl;
                            attemptsLeft--;
                            drawHangman(attemptsLeft);
                        }
                    }
                }
                else{
                    cout << "Please Enter a valid character" << endl;
                }
            }
            if(attemptsLeft == 0){
                displayGameInfo();
                cout << "Game Over :( You have run out of attempts " << endl;
                cout << "The word was : " << secretWord << endl;
            }
        }
};

int main(){
    HangManGame game1;
    game1.play();
    return 0;
}