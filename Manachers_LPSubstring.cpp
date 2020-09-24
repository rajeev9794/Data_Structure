#include<bits/stc++.h>
using namespace std;
//For finding LPS Longest Palindromic Substring in O(n) time apply logic to it.
//With help of dp we find result in O(n*n) time
//By using this algo we find result in O(n) time and space. 

/*
 3 logic selecting next element is not center
 1.Totally contained under current palindrome will not be new center (beacuse it fails to give larger length palindrome)
    before end of current palindromic element.
 2. If current center palindrome expands till end of input then our maximum length palindrome is explored
    no need to check further for elements. 
3.  if next centers palindrome is expanding till right end of current palindromic index but its
    mirror is expands beyond left edge so it could not be new center (we check for palindrome exist
    with that string and apply.)

 //Now at which point we are considering new centers
 Palindrome expands till right edge and its mirror is prefix. Beacuse from this center there is a chance of
 finding maximum length substring. 
 

 */
/*
*/
class LPS{
    public:
        string inputString;
        bool CheckPalindrome();
        string BruteForce_Longest_Palindromic_Substring();
        string Longest_Palindromic_Substring_Dynamic();
        string Longest_Palindromic_Substring_Manachers();
};

bool LPS::CheckPalindrome()
{
    int n=inputString.size();
    for(int i=0;i<n;i++)
    {
        if(inputString[i]!=inputString[n-i-1])
        return false;
    }
    return true;
}


string Manachers_Longest_Palindromic_Substring(string s)
{
    int n=s.size();
    string OddString;
    if(n%2==0)
    {
        for(int i=0;i<n;i++)
        {
            OddString.push_back('$');
            OddString.push_back(s[i]);
        }
        OddString.push_back('$');
    }
    else
    {
        OddString=s;
    }

    //Now find longest palindrome with given string and generate result
    int n1=OddString.size();
    int len=-1,center;
    int LPS[n1],currCenter=0;
    while(currCenter<n)
    {
        int left=currCenter-1,right=currCenter+1;
        int c=1;
        while(left>=0 && right<n && OddString[left]==OddString[right])
        {
            left--;
            right++;
            c+=2;
        }
        LPS[currCenter]=c;

        //Now check 3 situation of not allocating center to next element
        int prevCenter=currCenter;
        int freq=c/2;
        bool modifiedCenter=false;
        for(int i=currCenter+1;i<=currCenter+freq;i++)
        {
            //Completely lying under prevCenter Palindrome


        }
    }
    for(int i=0;i<n;i++)
    {

    }
    
}
