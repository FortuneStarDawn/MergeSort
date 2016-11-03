#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &A);

int main()
{
    string line;
    stringstream ss;
    int element;
    vector<int> A;

    getline(cin, line);
    ss<<line;
    while(ss>>element) A.push_back(element);

    mergeSort(A);
    for(int i=0; i<A.size(); i++) cout<<A.at(i)<<' ';
    cout<<endl;
    return 0;
}

void mergeSort(vector<int> &A)
{
    int left, right, mid, end, now;
    vector<int> temp = A;

    for(int width=1; width<A.size(); width*=2)
    {
        for(int start=0; start<A.size(); start+=2*width)
        {
            mid = start + width -1;
            end = start + 2*width -1;

            if(mid >= A.size()) mid = A.size()-1;
            if(end >= A.size()) end = A.size()-1;

            left = start;
            right = mid + 1;
            now = start;

            while(left<=mid && right<=end)
            {
                if(A.at(left) <= A.at(right))
                {
                    temp.at(now) = A.at(left);
                    left++;
                }
                else
                {
                    temp.at(now) = A.at(right);
                    right++;
                }
                now++;
            }
            while(left<=mid)
            {
                temp.at(now) = A.at(left);
                left++;
                now++;
            }
            while(right<=end)
            {
                temp.at(now) = A.at(right);
                right++;
                now++;
            }
        }
        A = temp;
    }
}
