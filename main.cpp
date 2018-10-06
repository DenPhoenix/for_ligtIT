#include <iostream>
#include <string>
#include <vector>
#include "Test 2 classes.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"Rus");
    cout<<"\t\t\ttest 2: �������� ���� <�����>"<<endl;
    cout<<"\n������� ���������� �������(�� ������ �� ����):";
    int N(0);cin>>N;
    if(N>=6){cout<<"������� ����� ������ 5.���� �� ���� ������� �� ������(� ������ ������).�������� ���������...";}
    else{
    card_deck Coloda;//�������� � ������ ������ �� 36 ����
    Coloda.resort();// ����������� ������
    card trump=Coloda.give_card();//������� �� ������ ���� ����� � �������� ������(������ �� �� ������)
    cout<<"������:";trump.show();
    vector<hand> players;//������ �� ���� �� ����� �������
    int max_value(0);int max_value_idx(0);
    const int card_in_hand=6;//���������� ���� � ���� �� ������ ������
    for(int i=0;i<N;i++){
        hand tmp(Coloda.give_card(card_in_hand));
        cout<<"\n����� "<<i+1<<":"<<endl;tmp.show();
        //cout<<"����������:"<<tmp.value(trump);
        players.push_back(tmp);
        //��� ����� ���� � ������������ �����������
        if(max_value<players[i].value(trump)){max_value=players[i].value(trump);max_value_idx=i;}
    }
    cout<<"\n����� ������� ���� � ������ "<<max_value_idx+1;
    }
    cin.get();
    cin.ignore();
    return 0;
}
