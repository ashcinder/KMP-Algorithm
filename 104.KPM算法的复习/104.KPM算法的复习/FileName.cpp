#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> GetNext(string s) {

	vector<int> next(s.size());

	int j = 0, i = 1;//j为前缀末尾，i为后缀末尾。同时j也代表最小前后缀的长度
	next[0] = 0;

	for (;i < s.size();i++) {
		while (j>0&&s[i] != s[j]) {//不匹配，回退
			j = next[j - 1];
		}

		if (s[i] == s[j]) {//匹配
			j++;
		}

		next[i] = j;//i位置的最小前后缀的长度
	}

	return next;
}

int Find(string a, string b) {
	if (b.empty()) {
		throw("Error!");
	}

	vector<int> next = GetNext(b);
	int j = 0, i = 1;
	
	for (;i < a.size();i++) {
		while (j > 0 && a[i] != b[j]) {//不匹配
			j = next[j - 1];
		}

		if (a[i] == b[j]) {//匹配
			j++;
		}

		if (j == b.size()) {//匹配到
			return i - b.size() + 1;
		}
	}

	return -1;
}

vector<int> FindAll(string a, string b) {

	if (b.empty()) {
		throw("Error!");
	}

	vector<int> result;
	vector<int> next = GetNext(b);
	int j = 0, i = 1;

	for (;i < a.size();i++) {
		while (j > 0 && a[i] != b[j]) {
			j = next[j - 1];
		}

		if (a[i] == b[j]) {
			j++;
		}

		if (j == b.size()) {
			result.push_back(i - b.size() + 1);
			j = next[j - 1];//j再回退到next数组的j-1的位置上
		}
	}

	return result;
}

int main() {
	string a = "FUCK YOU YOUYOU";
	string b = "YOU";

	cout << Find(a, b) << endl;
	
	vector<int> All = FindAll(a, b);
	for (auto it : All) {
		cout << it << " ";
	}

	return 0;
}