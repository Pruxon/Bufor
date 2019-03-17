#ifndef TESTY_H_INCLUDED
#define TESTY_H_INCLUDED
using namespace std;
#include <iostream>
#include <sstream>
#include <string.h>
#include <cstdlib>
#include <string>
#include "szablon.h"

int testuj_int ()
{
    int wynik=0;
    Bufor<int> bufor;
    int nps1=123234;
    int nps2=34543;
    int nps3=98723;
    int nps4=646642342;
    if (bufor.dodaj_do_bufora(nps1)==1)
        wynik++;
    if (bufor.dodaj_do_bufora(nps2)==1)
        wynik++;
    if (bufor.dodaj_do_bufora(nps3)==1)
        wynik++;
    bufor.zepsuj(2);
    int sprawdz=bufor.sprawdz(2);
    int sprawdz_d=bufor.jaka_poprawnosc(2);
    if (sprawdz==sprawdz_d)
        {wynik++;
        wynik--;}
        else
            wynik++;
    if (bufor.dodaj_do_bufora(nps4)==0)
        wynik++;
    int pam=bufor.ile_pamieci();
    if (pam==19)
        wynik++;
    int popr_1=bufor.jaka_poprawnosc(1);
    if (popr_1==303)
        wynik++;
    return wynik;
}

int testuj_char ()
{
    int wynik=0;
    Bufor<const char*> bufor;
    const char* nps1="kkkkk";
    const char* nps2="KKKKKK";
    const char* nps3="popop";
    const char* nps4="popopopop";
    if (bufor.dodaj_do_bufora(nps1)==1)
        wynik++;
    if (bufor.dodaj_do_bufora(nps2)==1)
        wynik++;
    if (bufor.dodaj_do_bufora(nps3)==1)
        wynik++;
    bufor.zepsuj(2);
    int sprawdz=bufor.sprawdz(2);
    int sprawdz_d=bufor.jaka_poprawnosc(2);
    if (sprawdz==sprawdz_d)
        {wynik++;
        wynik--;}
        else
            wynik++;
    if (bufor.dodaj_do_bufora(nps4)==0)
        wynik++;
    int pam=bufor.ile_pamieci();
    if (pam==19)
        wynik++;
    int popr_1=bufor.jaka_poprawnosc(1);
    if (popr_1==535)
        wynik++;
    return wynik;
}


#endif // TESTY_H_INCLUDED
