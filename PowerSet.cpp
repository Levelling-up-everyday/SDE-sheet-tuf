//Using BIT manupulation
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
