#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> A);
vector<int> merge(vector<int> left, vector<int> right);

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
    all = merge(leftSorted, rightSorted);
    return all;
}

vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> all;
    vector<int>::iterator itl, itr;
    itl = left.begin();
    itr = right.begin();

    while(itl!=left.end() && itr!=right.end())
    {
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
    while(itl!=left.end())
    {
        all.push_back(*itl);
        itl++;
    }
    while(itr!=right.end())
    {
        all.push_back(*itr);
        itr++;
    }
    return all;
}
