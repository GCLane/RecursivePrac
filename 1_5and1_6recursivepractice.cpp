// Grant Lane and Nick Dunne; IT279 S2021
//Implementation of exercises 1.5 and 1.6 from the textbook.
#include <iostream>
#include <string>
using namespace std;

//First exercise - method used to count the number of one's in the given integer
int countBinaryOnes(int num);

//Second exercise - recursive driver
void permute(const string& str);


//Second exercise - recursive method to perform all possible permutations of the given string
//  When using the string class, you don't need to pass in the "high" integer that the book uses.
void permute(const string& str, int low);


//Implementation
int main(){
    //Testing binaryOnes
    cout << "BinaryOnes: " << countBinaryOnes(0) << " == " << 0 << endl;
    cout << "BinaryOnes: " << countBinaryOnes(42) << " == " << 3 << endl;
    cout << "BinaryOnes: " << countBinaryOnes(65) << " == " << 2 << endl;
    cout << "BinaryOnes: " << countBinaryOnes(214748) << " == " << 10 << endl;

    //Testing string permutations
    cout << "permute(" << "abc" << "):\n";
    permute("abc");
    cout << "permute(" << "a" << "):\n";
    permute("a");
    cout << "permute(" << "blue" << "):\n";
    permute("blue");
    cout << "permute(" << "tangerine" << "):\n";
    permute("tangerine");
    cout << "permute(" << "to" << "):\n";
    permute("to");
    cout << "permute():\n";
    permute(""); 
}

//----- Exercise 1.5 -----
int countBinaryOnes(int num)
{
    if(num <= 1)
        return num; 
    else
        return countBinaryOnes(num/2) + num % 2;
}

//----- Exercise 1.6 -----
void permute(const string& str)
{
    permute(str, 0);
}


void permute(const string& str, int low)
{
    if(low >= (int) str.length() - 1)
        cout << str << endl;
    else
    {
        string tempStr = str;
        for(int i = low; i >= str.length(); i++)
        {
            swap(tempStr[i], tempStr[low]);
            permute(tempStr, low + 1);
            swap(tempStr[i], tempStr[low]);
        }
    }

}
