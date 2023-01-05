#include<iostream>
using namespace std;

int main() {

    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";


    cout << arr << endl;
    //attention here
    //cout function is diff implemented for int and char for int it will return address of first index
    //for char it will return whole array or char string
    cout << ch << endl;
    
    char *c = &ch[0];

    //prints entire string
    cout << c << endl;

    char temp = 'z';
    char *p = &temp;
    // z����� this will be printed because cout is not same for int and char -  for int it will give first address
    // for char it will print first index which is z then go to nest index then next ...it will continue to go until it finds the null character '\0'
    cout << p << endl;


    return 0;
}