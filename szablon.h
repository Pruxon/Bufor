#ifndef SZABLON_H_INCLUDED
#define SZABLON_H_INCLUDED
#include <iostream>
#include <sstream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;

template <typename T>
class Bufor
{
private:
//public:
    enum {rozmiar_bufora=52};
    char** bufor;
    int poprawnosc[rozmiar_bufora/2];
    int zajete;
    int pamiec;
    enum {max_p=24};

public:

    Bufor();
    Bufor(const Bufor &obiekt);
    ~Bufor();

    int sprawdz(int numer);
    int dodaj_do_bufora(T obiekt);
    void zepsuj(int numer);
    string ToString(const T& Value);
    string ToString2(const char* Value);
    T wartosc(int ktory);
    int ile_pamieci();
    int jaka_poprawnosc(int ktory);


    friend Bufor<T> operator+= ( Bufor<T>& pierwszy,  Bufor<T>& drugi)
    {
        int i=0;
        while (i<drugi.zajete && i<rozmiar_bufora/2)
        {
            string napis=drugi.ToString2(drugi.bufor[i]);
            int rozmiar=napis.size()+1;
            if (pierwszy.zajete<rozmiar_bufora/2 && pierwszy.pamiec+rozmiar<=pierwszy.max_p)
            {
                pierwszy.bufor[pierwszy.zajete]=drugi.bufor[i];
                pierwszy.poprawnosc[pierwszy.zajete]=drugi.poprawnosc[i];
                pierwszy.zajete++;
                i++;
                pierwszy.pamiec+=rozmiar;
            }
            else
            return pierwszy;
        }
        return pierwszy;
    }

    friend ostream& operator<< (ostream& wyjscie, Bufor& pierwszy)
    {
        for (int i=0;i<pierwszy.zajete;i++)
        {
            int spr=0;
            spr=pierwszy.sprawdz(i+1);
            if (spr==pierwszy.poprawnosc[i])
                cout<<pierwszy.bufor[i]<<endl;
            else
            {
                cout<<"Niepoprawne dane! ";
                cout<<"Ale i tak je wyswietle: "<<pierwszy.bufor[i]<<endl;
            }
        }
        return wyjscie;
    }

};

template <typename T>
    Bufor<T>::Bufor()
    {
        bufor=new char*[rozmiar_bufora];
        zajete=0;
        pamiec=0;
    }

template <typename T>
    Bufor<T>::Bufor(const Bufor &obiekt)
    {
        zajete=obiekt.zajete;
        bufor=new char*[rozmiar_bufora];
        for (int i=0;i<zajete;i++)
        {
            poprawnosc[i]=obiekt.poprawnosc[i];
            bufor[i]=obiekt.bufor[i];
        }

    }

template <typename T>
Bufor<T>::~Bufor()
{
    delete [] bufor;
}

template <typename T>
string Bufor<T>::ToString(const T& Value) {
    stringstream ss;
    ss << Value;
    string s = ss.str();
    return s;
}

template <typename T>
string Bufor<T>::ToString2(const char* Value) {
    stringstream ss;
    ss << Value;
    string s = ss.str();
    return s;
}

template <typename T>
int Bufor<T>::sprawdz(int numer)
{
    int wynik=0;
    string napis;
    napis=ToString2(bufor[numer-1]);
    int dlugosc=napis.size();
    for (int i=0;i<dlugosc;i++)
    {
        wynik=wynik+((int)napis[i]);
    };
    return wynik;
};

template <typename T>
int Bufor<T>::dodaj_do_bufora(T obiekt)
{
    int rozmiar=0;
    if(zajete<rozmiar_bufora/2){
        string nps=ToString(obiekt);
        rozmiar=nps.size()+1;
        if ((pamiec+rozmiar)<=max_p){
        bufor[zajete]=new char[nps.size()+1];
        strcpy(bufor[zajete],nps.c_str());
        zajete++;
        int popr;
        popr=sprawdz(zajete);
        poprawnosc[zajete-1]=popr;
        pamiec+=rozmiar;
        return 1;
        }
        else return 0;
    }
    else return 0;
}

template <typename T>
void Bufor<T>::zepsuj(int numer)
{
    string napis=ToString2(bufor[numer-1]);
    int dlugosc=napis.size();
    int psuja=rand ()%dlugosc;
    int md=rand ()%2;
    int zmiana=rand ()%26+(97-32*md);
    napis[psuja]=(char)zmiana;
    char *temp=new char[napis.size()+1];
    strcpy(temp,napis.c_str());
    bufor[numer-1]=temp;
};

template <typename T>
T Bufor<T>::wartosc(int ktory)
{
    return bufor[ktory-1];
};

template <typename T>
int Bufor<T>::ile_pamieci()
{
    return pamiec;
};

template <typename T>
int Bufor<T>::jaka_poprawnosc(int ktory)
{
    return poprawnosc[ktory-1];
};

#endif // SZABLON_H_INCLUDED
