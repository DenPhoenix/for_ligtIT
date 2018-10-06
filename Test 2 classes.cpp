#include <string>
#include <iostream>
#include <vector>
#include <cstdlib> //ôóíêöèÿ srand(),rand()
#include <ctime> //ôóíêöèÿ time()
#include "Test 2 classes.h"
using namespace std;//пр

//class Card
   card::card(string C,string N):color(C),name(N){};
   string card::get_color()  { return color;}
   string card::get_name() { return name;}
   void card::show(){cout<<card::get_name()<<"-"<<card::get_color()<<";"<<endl;}
   int card::value (){
        int val(0);
        if(name=="Øåñòåðêà"){val=1;}
        if(name=="Ñåìåðêà"){val=2;}
        if(name=="Âîñüìåðêà"){val=3;}
        if(name=="Äåâÿòêà"){val=4;}
        if(name=="Äåñÿòêà"){val=5;}
        if(name=="Âàëåò"){val=6;}
        if(name=="Äàìà"){val=7;}
        if(name=="Êîðîëü"){val=8;}
        if(name=="Òóç"){val=9;}
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
        vector<string> color{"Áóáíà","×èðâà","Ïèêà","Êðåñò"};
        vector<string> name{"Øåñòåðêà","Ñåìåðêà","Âîñüìåðêà","Äåâÿòêà","Äåñÿòêà","Âàëåò","Äàìà","Êîðîëü","Òóç"};
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
        cout<<"Êîëîäà ïåðåòàñîâàíà..."<<endl;
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
