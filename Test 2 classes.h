#ifndef TEST_2_CLASSES_H_INCLUDED
#define TEST_2_CLASSES_H_INCLUDED

using namespace std;

class card {
    string color,name;
public:
    card(string C,string N);
    string get_color();
    string get_name();
    void show();
    int value ();
    int value(card& Trump);//ценность карты с учетом козыря "trump"
};

class card_deck{
    vector<card> pack;
public:
    card_deck();
    int size();
    card operator [](int i);
    void resort();
    card give_card();//возвращает одну карту удаляя ее из колоды
    vector<card> give_card(int N);// возвращает N-карт удаляя их из колоды
};

//класс рука - отображает карты в руке у игрока
class hand{
    vector<card> pack;
public:
    hand(vector<card> H);
    int value(card& trump);//ценность руки как сумма ценности всех карт в руке с учетом козыря "trump"
    void show();
};

#endif // TEST_2_CLASSES_H_INCLUDED
