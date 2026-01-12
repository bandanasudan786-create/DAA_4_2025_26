#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void complexRec(int n) {

 long long count=0;
   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           count++;

       }
       p >>= 1;
       
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       count++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       
   } else {
       reverse(small.begin(), small.end());
       
   }


   complexRec(n / 2);
   complexRec(n / 2);
   complexRec(n / 2);
   


}
int main()
{
    int n=1024;
    
    auto start = high_resolution_clock::now();
    complexRec(n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time for n = " << n << " : "
         << duration.count() << " ms\n";
   cout<<"1.----the recurrance relation of this code is:----";
   cout<<"3T(n/2)+n+nlogn \n";
   cout<<"---using the master theorem--- \n ";
   cout<<"a=3\n b=2 \n k=1 \n p=1 \n";
   cout<<"Here a>b^k \n";
   cout<<"therefore the time complexity is \n";
   cout<<"T(n)=n^log2(3) \n ";
   


}
