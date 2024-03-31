#include <iostream>
using namespace std;

char check_carry(char a, char b, char c)
{
    if (a == '0' && b == '0' && c == '0')
        return '0';
    else if (a == '0' && b == '0' && c == '1')
        return '0';
    else if (a == '0' && b == '1' && c == '0')
        return '0';
    else if (a == '1' && b == '0' && c == '0')
        return '0';
    else
        return '1';
}

int main()
{
    string A, B, result;
    char a0, b0, carry;
    int len, i;
    cout << "Enter any two number of same length: ";
    cin >> A >> B;
    len = A.size();

    carry = '0';
    for (i = len-1; i >= 0; i--)
    {
        a0 = A[i];
        b0 = B[i];

        if (check_carry(a0, b0, carry) == '0'){
            if (a0 == '0' && b0 == '0' && carry == '0')
                result = '0' + result;
            else
                result = '1' + result;
        }
        else{
            if (a0 == '1' && b0 == '1' && carry == '1')
                result = '1' + result;
            else
                result = '0' + result;
        }
        carry = check_carry(a0, b0 , carry);
    }
    cout << "The sum of " << A << " And " << B << " is " << result << " and carry is " << carry;
}