#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

#include "szablon.h"
#include "testy.h"


int main()
{
    int test;
    test=testuj_int();
    int test_ch;
    test_ch=testuj_char();
    if (test==7 && test_ch==7)
        cout<<"Testy wypadly pomyslnie!"<<endl;
   return 0;
}
