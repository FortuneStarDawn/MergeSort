#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> A);

int main()
{
    string line;
    stringstream ss;
    int element;
    vector<int> A;

    getline(cin, line);
    ss<<line;
    while(ss>>element) A.push_back(element);

    A = mergeSort(A);
    for(int i=0; i<A.size(); i++) cout<<A.at(i)<<' ';
    cout<<endl;
    return 0;
}

vector<int> mergeSort(vector<int> A)
{
    if(A.size()==1) return A;

    vector<int> left, right, leftSorted, rightSorted, all;
    left.assign(A.begin(), A.begin() + A.size()/2);
    right.assign(A.begin() + A.size()/2, A.end());
    leftSorted  = mergeSort(left);
    rightSorted = mergeSort(right);
    vector<int>::iterator itl, itr;
    itl = leftSorted.begin();
    itr = rightSorted.begin();
    while(1)
    {
        if(itl==leftSorted.end())
        {
            while(itr!=rightSorted.end())
            {
                all.push_back(*itr);
                itr++;
            }
            break;
        }
        if(itr==rightSorted.end())
        {
            while(itl!=leftSorted.end())
            {
                all.push_back(*itl);
                itl++;
            }
            break;
        }
        if(*itl<=*itr)
        {
            all.push_back(*itl);
            itl++;
        }
        else
        {
            all.push_back(*itr);
            itr++;
        }
    }
    return all;
}
