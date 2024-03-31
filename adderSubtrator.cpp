#include <iostream>
using namespace std;
char carry = '0';

char check_carry(char a, char b, char c){
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

string perform_addition(string A, string B){
    string result;
    char a0, b0;
    int i, len = A.size();

    for (i = len - 1; i >= 0; i--){
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
        carry = check_carry(a0, b0, carry);
    }
    return result;
}

string find_complement(string A){
    string temp;
    for (int i = A.size() - 1; i >= 0; i--){
        if (A[i] == '1')
            temp = '0' + temp;
        else
            temp = '1' + temp;
    }
    return temp;
}

string equal_size(string A, int size2){
    for(int i = A.size(); i<size2; i++)
        A = '0' + A;
    return A;
}

int main(){
    string A, B, B_temp, B_comp, result, store1;
    char operation;
    cout << "Enter the first number: ";
    cin >> A;
    cout << "Enter the operation you want to perform\n1) +\n2) -\n:- ";
    cin >> operation;
    cout << "Enter the second number: ";
    cin >> B;

    if(A.size()>B.size())
        B = equal_size(B, A.size());
    else
        A = equal_size(A, B.size());

    switch (operation){
    case '+':
        result = perform_addition(A, B);
        cout << "The result of " << A << " + " << B << " is " << carry + result;
        break;
    case '-':
        B_temp = B;

        // one's complement of B
        B = find_complement(B);

        int i;
        for (i = 0; i < B.size(); i++)
            store1 = '0' + store1;
        store1[store1.size() - 1] = '1';

        // two's complement of B
        B_comp = perform_addition(B, store1);
        cout << B_comp << endl;

        // addition of A and complement of B providing the result
        result = perform_addition(A, B_comp);
        if (carry == '1')
            cout << "The result of " << A << " - " << B_temp << " is +" << result << endl;
        else{
            result = find_complement(result);
            result = perform_addition(result, store1);
            cout << "The result of " << A << " - " << B_temp << " is -" << result << endl;
        }
    default:
        cout << "Sorry Invalid Operation" << endl;
        break;
    }
}