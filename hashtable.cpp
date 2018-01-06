#include <iostream>
#include <ctime>
#include <random>
#include <fstream>


int table[997];

int hashfunc1(int key)
{
    return  (int)((key % 1000) +  pow(2,key % 10) + 1)% 997;
}

int hashfunc2(int key)
{
    return  (3 * key) % 19 + 1;
}
void init()
{
    for (int i = 0; i <997; i++)
    {
        table[i] = 0;
    }
}

void add(int key)
{
    int index = hashfunc1(key);
    while (table[index] != 0 and table[index] != key and table[index] != -1)
    {
        index= (index + 1) % 997;
    }
    table[index] = key;
}
void printHash(int x,int y)
{
    for (int x; x < y; x++)
    {
        if(table[x] != 0)
            std::cout<<x<<" "<<table[x]<<std::endl;
    }
}

void remove(int key)
{
//    while(table[index] != key)
//    {
//        index= (index + 1) % 997;
//    }
//    std::cout<<" item removed "<<std::endl;
//    table[index]=-1;

    int index = hashfunc1(key);
    for (int i = 0; i < 997; ++i)
    {
        if(table[index] == key)
        {
            std::cout<<"item removed"<<index<<" "<<table[index]<<std::endl;
            table[index]=-1;
        }
        index= (index + 1) % 997;
    }
    std::cout<<"not found"<<std::endl;
}

void search(int key)
{
    int index = hashfunc1(key);
    for (int i = 0; i < 997; ++i)
    {
        if(table[index] == key)
        {
            std::cout<<"found element "<<index<<" "<<table[index]<<std::endl;
            return;
        }
    }
    std::cout<<"not found"<<std::endl;
}

void adddouble(int key)
{
    int index = hashfunc1(key);
    int two = hashfunc2(key);
    while (table[index] != 0 and table[index] != -1 and table[index] != key)
    {
            index = (index + two) % 997;
    }
    table[index] = key;
}
void random(int n,int number)
{

    for (int i = 0; i < n; i++)
    {
        int tmp;
        while (true)
        {
            bool rands = false;
            tmp = (rand() % 20000) + 20000;
            for(int j = 0; j < i; j++)
            {
                if(table[j] == tmp)
                {
                    rands = true;
                    break;
                }
            }
            if(!rands)
                break;
        }
        if(number == 0)
        {
            add(tmp);
        } else
        {
            adddouble(tmp);
        }

    }
}




int main() {
    clock_t begin = clock();
    srand(time(NULL));
    int n,k1,k2,k3,k4;
    std::fstream file;
    file.open("inlab06.txt");
    file>>n>>k1>>k2>>k3>>k4;
    init();
    remove(k1);
    add(k1);
    printHash(0,100);
    random(n,0);
    add(k2);
    add(k3);
    add(k4);
    printHash(0,100);
    remove(k2);
    remove(k3);
    printHash(500,600);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout <<"time: "<< elapsed_secs;
}