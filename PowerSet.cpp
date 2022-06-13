//Using BIT manupulation
//For strings
#include<bits/stdc++.h>
using namespace std;
vector<string> AllPossibleStrings(string s) {
	int n = s.length();
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			//check if the ith bit is set or not
			if (num & (1 << i)) {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}
int main()
{


	string s="abc";
	vector<string>ans = AllPossibleStrings(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}

}
//for integer
#include<bits/stdc++.h>
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> answer;
    int n=v.size();
    for(int num=0;num<(1<<n);num++)
    {
        vector<int> sub;
        for(int i=0;i<n;i++)
        {
            if(num&(1<<i))
                sub.push_back(v[i]);
        }
        answer.push_back(sub);
    }
    sort(answer.begin(),answer.end());
    return answer;
}






//Using recursion
//Vectors need to be passed by refrence

//String
#include<bits/stdc++.h>
using namespace std;
void solve(int i, string s, string &f) {
	if (i == s.length()) {
		cout << f << " ";
		return;
	}
	//picking 
	f = f + s[i];
	solve(i + 1, s,  f);
	//poping out while backtracking
	f.pop_back();
	solve(i + 1, s,  f);
}
int main() {
	string s = "abc";
	string f = "";
	cout<<"All possible subsequences are: "<<endl;
	solve(0, s, f);
}

//Integers
#include<bits/stdc++.h>
using namespace std;
void powerset(int arr[], vector<int> &ans,int index,int n)
{
    if(index==n)
    {
        for(auto it: ans)
        cout<<it<<" ";
        if(ans.size()==0)
    {
        cout<<"{}";
    }
    cout<<endl;
        return;
    }
    
    ans.push_back(arr[index]);
    powerset(arr,ans,index+1,n);
    ans.pop_back();
    powerset(arr,ans,index+1,n);
}
int main()
{
   int arr[]={3,1,2};
   vector<int>ans;
   powerset(arr,ans,0,3);
    return 0;
}
