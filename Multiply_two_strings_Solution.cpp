******************************************************  Question  ****************************************************************
Given two numbers as strings s1 and s2. Calculate their Product.

Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers.

Example 1:

Input:
s1 = "0033"
s2 = "2"
Output:
66
Example 2:

Input:
s1 = "11"
s2 = "23"
Output:
253
Your Task: You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which takes two strings s1 and s2 as input and returns their product as a string.

Expected Time Complexity: O(n1* n2)
Expected Auxiliary Space: O(n1 + n2); where n1 and n2 are sizes of strings s1 and s2 respectively.

Constraints:
1 ≤ length of s1 and s2 ≤ 103
  ******************************************************  Solution  ****************************************************************
  //{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */

       //Your code here
       void add(int product , int pos, int arr[] , int size)
    {
        if(product == 0 || pos >= size) return;
        int carry = 0;
        if(product >= 10)
        {
            carry = product / 10;
            product %= 10;
        }
        arr[pos] += product;
        if(arr[pos] >= 10)
        {
            carry += arr[pos] / 10;
            arr[pos] %=10;
        }
        add(carry, pos + 1, arr, size);
    }
    
    
    string multiplyStrings(string str1, string str2) 
    {
        int start1, start2;
        start1 = 0;
        start2 = 0;
        string ans = "";
        bool neg  =false;
        if(str1[start1] == '-')
        {
            if(str2[start2] == '-')
            {
                start1++;
                start2++;
            }
            else
            {
                neg = true;
                start1++;
            }
        }
        else if(str2[start2] == '-')
        {
            neg = true;
            start2++;
        }
        while(str1[start1] == '0') start1++;
        while(str2[start2] == '0') start2++;
       
        int n1 = str1.size();
        int n2 = str2.size();
       
        int arr[n1 + n2];
        for(int i = 0; i< n1 + n2; i++)
            arr[i] = 0;
        
        for(int i = n1- 1; i>= start1; i--)
        {
            int x = str1[i] - '0';
            for(int j = n2 - 1; j>= start2; j--)
            {
                int y = str2[j] - '0';
                int pos = (n1 + n2 - 2) - i - j;
                int p = x * y;
                add(p, pos, arr, n1+ n2);
            }
        }
    
        /*for(int i = 0; i < n1 + n2; i++)
        {
            cout<<arr[i]<< "  ";
        }*/
        //cout<<"\n";
        int j = n1+ n2 - 1;
        while(arr[j] == 0)
            j--;
        
        if(neg == true) ans += '-';
        for(int i = j; i >= 0 ; i--)
        {
            ans += (char) (arr[i] + '0');
        }
        
        return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
