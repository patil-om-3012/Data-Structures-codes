//Tower of Hanoi
#include<bits/stdc++.h>

using namespace std;

void towerOfHanoi(int n,int from,int to,int aux)
{
    if(n == 1)
    {
        cout << "Move disk 1 from " << from <<" to " << to << endl;
        return;
    }

    towerOfHanoi(n-1,from,aux,to); //move n-1 disks from src to aux
    cout << "Move disk " << n << " from " << from << " to " << to <<  endl; // move nth disk from source to dest
    towerOfHanoi(n-1,aux,to,from); // move n-1 disks from aux to dest
}

int main()
{
    int n;
    cin >> n;

    towerOfHanoi(n,1,3,2);
}