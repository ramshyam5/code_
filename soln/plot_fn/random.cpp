
#include <bits/stdc++.h>
using namespace std;
void multiplicativeCongruentialMethod(
    int Xo, int m, int a,
    vector<int> &randomNums,
    int noOfRandomNums)
{

    randomNums[0] = Xo;
    for (int i = 1; i < noOfRandomNums; i++)
    {

        randomNums[i] = (randomNums[i - 1] * a) % m;
    }
}

// Driver Code
int main()
{
    int Xo = 3; // seed value
    int m = 15; // modulus parameter
    int a = 7;  // multiplier term
    int noOfRandomNums = 15;
    vector<int> randomNums(noOfRandomNums);

    // Function Call
    multiplicativeCongruentialMethod(
        Xo, m, a, randomNums,
        noOfRandomNums);
    for (int i = 0; i < noOfRandomNums; i++)
    {
        cout << randomNums[i] << " ";
    }
    return 0;
}