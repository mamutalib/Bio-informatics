#include<bits/stdc++.h>
using namespace std;

int arr[100];

vector<int>delX , X, vec;

void checking(int num)
{
    int i=0, diff=0, cnt = 0;

    int lenX = X.size();

    while(i < lenX)
    {
        //compute subtraction
        diff = abs(X[i] - num);

        if(arr[diff] > 0)
        {
            cnt += 1;

            vec.push_back(diff);
        }

        i++;
    }

    if(cnt == lenX)
    {
        for(i=0; i<vec.size(); i++)
        {
            arr[vec[i]]--;
        }

        X.push_back(num);
    }

    vec.clear();
}

int main()
{
    delX = {2, 2, 3, 3, 4, 5, 6, 7, 8, 10}; // the given multi set

    int i, j, diff=0, len = delX.size();

    sort(delX.begin(), delX.end()); // sorted the multi set

    X.push_back(0);
    X.push_back(delX[len-1]); // taken X and push back first two elements

    //count each number in the del X
    for(i=0; i<len; i++)
    {
        arr[delX[i]]++;
    }

//    for(i=0; i<len; i++)
//    {
//        cout << delX[i] << " " << arr[delX[i]] << "\n";
//    }

    i = 0 , j = 0;

    while(i < delX.size())
    {
        //checked the conditions
        checking(delX[i]);

        i++;
    }

    //sort the elements of the X
    sort(X.begin(), X.end());

    for(int i=0; i<X.size(); i++)
    {
        cout << X[i] << " ";
    }

    return 0;
}