#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &A, int start, int end);
void merge(vector<int> &A, int start, int mid, int end);

int main()
{
    string line;
    stringstream ss;
    int element;
    vector<int> A;

    getline(cin, line);
    ss<<line;
    while(ss>>element) A.push_back(element);

    mergeSort(A, 0, A.size()-1);
    for(int i=0; i<A.size(); i++) cout<<A.at(i)<<' ';
    cout<<endl;
    return 0;
}

void mergeSort(vector<int> &A, int start, int end)
{
    if(start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(A, start, mid);
    mergeSort(A, mid+1, end);
    merge(A, start, mid, end);
}

void merge(vector<int> &A, int start, int mid, int end)
{
    int left, right, now;
    vector<int> temp;

    left = start;
    right = mid + 1;
    now = start;
    temp = A;

    while(left<=mid && right<=end)
    {
        if(temp.at(left) <= temp.at(right))
        {
            A.at(now) = temp.at(left);
            left++;
        }
        else
        {
            A.at(now) = temp.at(right);
            right++;
        }
        now++;
    }

    while(left<=mid)
    {
        A.at(now) = temp.at(left);
        left++;
        now++;
    }
    while(right<=end)
    {
        A.at(now) = temp.at(right);
        right++;
        now++;
    }
}
