#include <iostream>

using namespace std;

    bool is_prime (int n)
    {

         if (n<=1)
        {
            return false;
        }
            for (int i=2; i<=n/2; i++)
            {
                 if (n%i==0)
             {
                 return false;
             }
            }

        return true;
    }
    int main ()
    {
        cout <<"The All Prime Numbers Between 300 to 500 are :";
        for (int i = 300; i<=500; i++)
        {
            if (is_prime(i))
            {
                cout << i<<",";
            }
        }
        return 0;
    }

