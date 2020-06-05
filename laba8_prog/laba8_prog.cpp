#include <iostream>
#include <ctime>
#include <list>
#include <iterator>
#include <forward_list>
using namespace std;

struct node
{
    int P1{};
    node* next{};
    node* prev{};
};

void lvl1(){
    /*создать линейный однонаправленный список из вещественных чисел.
удалить из списка элемент после первого элемента с положительным знаением.*/
   forward_list <double> Numbers = {-1.5,-2.35,3.75,-4.7,5.16,6.4,7.2 };
   forward_list <double> ::iterator Num, Obj;
   cout << "Список перед изменением: \n";
    for (Num = Numbers.begin(); Num != Numbers.end(); Num++)
    {
        cout << *Num << " ";
    }
    for (Num = Numbers.begin(); Num != Numbers.end(); Num++)
    {
        if (*Num >0) {
            Obj = Num;
            break;
        }
    }
    cout << endl;
      Numbers.erase_after(Obj);

    cout << "Список после изменения: \n";
    for (Num = Numbers.begin(); Num != Numbers.end(); Num++)
    {
        cout << *Num << " ";
    }
    cout << endl;
    
}
void lvl2() {
    /*создать линейный однонаправленный список из вещественных чисел.
    удалить из списка первый элемент меньший по модулю 5. */
    forward_list <double> Numbers = { 7.2, 6.4, 5.16, -4.7, 3.75, -2.35, -1.5 };
    forward_list <double> ::iterator Num, Obj;
    cout << "Список перед изменением: \n";
    for (Num = Numbers.begin(); Num != Numbers.end(); Num++)
    {
        cout << *Num << " ";
    }
    cout << endl;
    for (Num = Numbers.begin(); Num != Numbers.end(); Num++)
    {
        if (abs(*Num) < 5) {            
            Obj = Num;
            break;
        }
    }
    cout << endl;
    Numbers.remove(*Obj);
    //Numbers.erase_after(Obj);
    cout << "Список после изменения: \n";
    for (Num = Numbers.begin(); Num != Numbers.end(); Num++)
    {
        cout << *Num << " ";
    }
    cout << endl;
}
node* pushForwardList(node* head, int P1)
{
    return new node{ P1, head };
}

node* convertToDouble(node* head)
{
    while (head->next)
    {
        head->next->prev = head;
        head = head->next;
    }
    return head;
}

void fprint(node* head)
{
    while (head)
    {
        cout << head->P1 << ' ';
        head = head->next;
    }
    cout << endl;
}

void rprint(node* tail)
{
    while (tail)
    {
        cout << tail->P1 << ' ';
        tail = tail->prev;
    }
    cout << std::endl;
}

void clear(node*& head, node*& tail)
{
    while (head)
    {
        node* to_del = head;
        head = head->next;
        delete to_del;
    }
    if (tail) tail = head;
}


void lvl3() {
    /*Дан указатель Р1 на начало односвязного линейного списка. 
    Преобразовать исходную (односвязную) цепочку в двусвязную,
    в которой каждый элемент связан не только с последующим элементом
    (с помощью Next), но и с предыдущим (с помощью поля Prev).
    Поле Prev первого элемента положить равным 0. 
    вывести на экран преобразованную цепочку в обратном порядке. */
    node* head{};
    for (int i = 10; i; --i)
        head = pushForwardList(head, i);
    fprint(head);
    node* tail = convertToDouble(head);
    rprint(tail);
    clear(head, tail);
    /*
    Node1* p = NULL;
    p->Prev = 0;
    for (; p->Next; p = p->Next)
        p->Next->Prev = p;
*/

}
int main()
{
    setlocale(LC_ALL, "Russian");
    int varForSwitch;
    cout << "Выберите уровень сложности :" << endl << "1. Легкий" << endl << "2. Базовый" << endl << "3. Сложный \n";
    cout << "Ваш выбор:  ";
    cin >> varForSwitch;
    switch (varForSwitch)
    {
    case 1:
        lvl1();
        break;
    case 2:
        lvl2();
        break;
    case 3:
        lvl3();
        break;
    default:
        cout << "Error 404! Action not found." << endl;
        break;
    }
    system("pause");
    return 0;
}

