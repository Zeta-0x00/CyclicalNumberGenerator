#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void getNumber(int &x)
{
    char j;
    cin>>j;
    if(isdigit(j))
    {
        x = j-'0';
    }
    else
    {
        cout<<"Nein";
        x = -1;
    }
}
bool isPrime(int &x)
{
    if(x == 2 || x == 1){return true;}
    else
    {
        for(int i=2; i<x; i++)
        {
            if(x%i == 0){return false;}
        }
        return true;
    }
}
list<int> Cicles(int &p)
{
    list<int> l;
    int cont = 2;
    list<int> j;
    bool flag;
    int k;
    while(cont<p)
    {
        if(!j.empty()){j.clear();}
        flag = true;
        k = 1;
        for (int i = 1; i<p; i++)
        {
            k = (k*cont)%p;
            if(!j.empty())
            {
                list<int>::iterator findIT = std::find(j.begin(), j.end(), k);
                if (findIT != j.end())
                {
                    flag = false;
                    break;
                }
            }
            j.push_back(k);
        }
        if(flag)
        {l.push_back(cont);}
        cont++;
    }
    return l;
}

int main()
{
    list<int> x;
    int p;
    cout<<"Enter a prime Number\n>>> ";
    cin>>p;
    if(isPrime(p))
    {
        x = Cicles(p);
        for (int v : x)
        {
            cout<<v<<" ";
        }
    }
    else
    {
        cout<<"Is not a prime number\n";
    }

    return 0;
}