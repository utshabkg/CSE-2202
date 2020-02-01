#include <bits/stdc++.h>
using namespace std;

void merge_sort(int* num, int lo, int hi)
{
    if(lo == hi) return;

    int mid = lo + (hi - lo) / 2;

    merge_sort(num, lo, mid);
    merge_sort(num, mid+1, hi);

    int temp[hi-lo+5];

    for(int i = lo, j = mid+1, k = 0, kk = lo; kk <= hi; kk++, k++)
    {

        if(i == mid+1) temp[k] = num[j++];
        else if(j == hi+1) temp[k] = num[i++];
        else if(num[i] < num[j]) temp[k] = num[i++];
        else temp[k] = num[j++];
    }

    for(int xx = lo, yy = 0; xx <= hi; xx++, yy++)
        num[xx] = temp[yy];
}

int bin_serach(int* num, int lo, int hi, int target)
{
    if(lo > hi) return -1;
    int mid =  (hi + lo) / 2;
    if(num[mid] == target) return mid;
    else if (num[mid] > target) return bin_serach(num, lo, mid-1, target);
    else return bin_serach(num, mid+1, hi, target);
}

int main()
{

    freopen("F:\Input.txt", "r", stdin);
    freopen("F:\Output_2.txt", "w", stdout);

    //vector <int> ara;
    int ara[50000];
    int index = 0, temp;

    while(scanf("%d", &temp) == 1)
    {
        ara[index++] = temp;

    }

    merge_sort(ara, 0, index-1);

    clock_t start = clock();

    for(int i = 0; i < index; i++)
    {
        for(int j = 0; j < index; j++)
        {
            int tempsum = ara[i]+ara[j];
            tempsum *= -1;
            int t2 = bin_serach(ara, 0, index-1, tempsum);
            if(t2 != -1)
            {
                cout << ara[i] << " " << ara[j] << " " << ara[t2] << endl;
            }
        }
    }
    clock_t stop = clock();

    double duration = (double)(stop - start);
    duration /= CLOCKS_PER_SEC;

    printf( "Total time taken : %.4lf seconds.\n", duration);
}


