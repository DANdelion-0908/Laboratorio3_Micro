// C++ program to find factorial of given number
#include <iostream>
using namespace std;
#include <omp.h>

// function to find factorial of given number
unsigned int factorial(unsigned int n)
{
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            #pragma omp single
            {
                if (n == 0){
                return 1;
                }
            }
        }

        #pragma omp section 
        {
        return n * factorial(n - 1);
        }
    }
}

// Driver code
int main() {
    int num;

    cout << "Type a number:";
    cin >> num;
    
    int result = factorial(num);

    cout << "Factorial of "
    << num << " is " << result << endl;
    return 0;
}
// Based on the code made by Shivi_Aggarwal