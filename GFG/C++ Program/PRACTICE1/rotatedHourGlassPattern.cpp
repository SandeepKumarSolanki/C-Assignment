 #include <iostream>
 using namespace std;
 void pattern(int n)
 {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        int spaces = 2 * (n - i);
        for (int j = 0; j < spaces; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "* ";

        }
        cout << endl;
    }
    // Printing bottom part.
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        int spaces = 2 * (n - i);
        for (int j = 0; j < spaces; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
 }
 int main()
 {
    int n;
    cout<<"Enter number of rows you want to print clock hour : ";
    cin>>n;
    pattern(n);
    return 0;
 }