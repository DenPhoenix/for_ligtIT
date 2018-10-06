#include <iostream>
#include <string>
#include <vector>
#include "Test 2 classes.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"Rus");
    cout<<"\t\t\ttest 2: Èìèòàöèÿ èãðû <Äóðàê>"<<endl; 
    cout<<"\nÂâåäèòå êîëè÷åñòâî èãðîêîâ(îò îäíîãî äî ïÿòè):";
    int N(0);cin>>N;
    if(N>=6){cout<<"Ââåäåíî ÷èñëî áîëüøå 5.Êàðò íà âñåõ èãðîêîâ íå õâàòèò(ñ ó÷åòîì êîçûðÿ).Çûêðûâàþ ïðîãðàììó...";}
    else{
    card_deck Coloda;//îáúÿâëÿþ è ñîçäàþ êîëîäó èç 36 êàðò
    Coloda.resort();// ïåðåòàñîâóþ êîëîäó
    card trump=Coloda.give_card();//âûáèðàþ èç êîëîäû îäíó êàðòó â êà÷åñòâå êîçûðÿ(óäàëÿÿ åå èç êîëîäû)
    cout<<"Êîçûðü:";trump.show();
    vector<hand> players;//ìàññèâ èç êàðò íà ðóêàõ èãðîêîâ
    int max_value(0);int max_value_idx(0);
    const int card_in_hand=6;//êîëè÷åñòâî êàðò â ðóêå íà îäíîãî èãðîêà
    for(int i=0;i<N;i++){
        hand tmp(Coloda.give_card(card_in_hand));
        cout<<"\nÈãðîê "<<i+1<<":"<<endl;tmp.show();
        //cout<<"Çíà÷èìîñòü:"<<tmp.value(trump);
        players.push_back(tmp);
        //Èùó íàáîð êàðò ñ ìàêñèìàëüíîé çíà÷èìîñòüþ
        if(max_value<players[i].value(trump)){max_value=players[i].value(trump);max_value_idx=i;}
    }
    cout<<"\nÑàìàÿ ñèëüíàÿ ðóêà ó èãðîêà "<<max_value_idx+1;
    }
    cin.get();
    cin.ignore();
    return 0;
}
