#include <iostream>
#include <string>
#include <vector>
#include "Test 2 classes.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"Rus");
    cout<<"\t\t\ttest 2: »митаци€ игры <ƒурак>"<<endl;
    cout<<"\n¬ведите количество игроков(от одного до п€ти):";
    int N(0);cin>>N;
    if(N>=6){cout<<"¬ведено число больше 5. арт на всех игроков не хватит(с учетом козыр€).«ыкрываю программу...";}
    else{
    card_deck Coloda;//объ€вл€ю и создаю колоду из 36 карт
    Coloda.resort();// перетасовую колоду
    card trump=Coloda.give_card();//выбираю из колоды одну карту в качестве козыр€(удал€€ ее из колоды)
    cout<<" озырь:";trump.show();
    vector<hand> players;//массив из карт на руках игроков
    int max_value(0);int max_value_idx(0);
    const int card_in_hand=6;//количество карт в руке на одного игрока
    for(int i=0;i<N;i++){
        hand tmp(Coloda.give_card(card_in_hand));
        cout<<"\n»грок "<<i+1<<":"<<endl;tmp.show();
        //cout<<"«начимость:"<<tmp.value(trump);
        players.push_back(tmp);
        //»щу набор карт с максимальной значимостью
        if(max_value<players[i].value(trump)){max_value=players[i].value(trump);max_value_idx=i;}
    }
    cout<<"\n—ама€ сильна€ рука у игрока "<<max_value_idx+1;
    }
    cin.get();
    cin.ignore();
    return 0;
}
