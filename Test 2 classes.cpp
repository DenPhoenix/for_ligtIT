#include <string>
#include <iostream>
#include <vector>
#include <cstdlib> //функция srand(),rand()
#include <ctime> //функция time()
#include "Test 2 classes.h"
using namespace std;

//class Card Карта
   card::card(string C,string N):color(C),name(N){};
   string card::get_color()  { return color;}
   string card::get_name() { return name;}
   void card::show(){cout<<card::get_name()<<"-"<<card::get_color()<<";"<<endl;}
   int card::value (){
        int val(0);
        if(name=="Шестерка"){val=1;}
        if(name=="Семерка"){val=2;}
        if(name=="Восьмерка"){val=3;}
        if(name=="Девятка"){val=4;}
        if(name=="Десятка"){val=5;}
        if(name=="Валет"){val=6;}
        if(name=="Дама"){val=7;}
        if(name=="Король"){val=8;}
        if(name=="Туз"){val=9;}
        return val;
    }
    int card::value(card& Trump){
        int val(0);
        if (color==Trump.color){val=value()+9;}
        else{val=value();}
        return val;
    }

//class card_deck
    card_deck::card_deck(){
        vector<string> color{"Бубна","Чирва","Пика","Крест"};
        vector<string> name{"Шестерка","Семерка","Восьмерка","Девятка","Десятка","Валет","Дама","Король","Туз"};
        for (unsigned int i=0;i<color.size();i++){
            for (unsigned int j=0;j<name.size();j++){
                card tmp(color[i],name[j]);
                pack.push_back(tmp);
            }
        }
    }
    int card_deck::size(){return pack.size();}
    card card_deck::operator [](int i){return pack[i];}
    void card_deck::resort(){
        int N=pack.size();
        vector<card> tmp;
        while(N>1){
            srand(time(0));
            int idx=rand()%N;
            tmp.push_back(pack[idx]);
            pack.erase(pack.begin()+idx);
            N--;
        }
        tmp.push_back(pack[0]);
        pack.pop_back();
        pack=tmp;
        cout<<"Колода перетасована..."<<endl;
    }
    card card_deck::give_card(){card res=pack[pack.size()-1];pack.pop_back();return res;}
    vector<card> card_deck::give_card(int N){
        vector<card>res;
        for( int i=0;i<N;i++){
            res.push_back(give_card());
        }
        return res;
    }

    //class hand
    hand::hand(vector<card> H){pack=H;}
    int hand::value(card& trump){
        int res(0);
        for (unsigned int i=0;i<pack.size();i++){
            res=res+pack[i].value(trump);
        }
        return res;
    }
    void hand::show(){
        for (unsigned int i=0;i<pack.size();i++){
            pack[i].show();
        }
    }
