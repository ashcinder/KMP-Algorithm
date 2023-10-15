#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> GetNext(string s) {

	vector<int> next(s.size());

	int j = 0, i = 1;//jΪǰ׺ĩβ��iΪ��׺ĩβ��ͬʱjҲ������Сǰ��׺�ĳ���
	next[0] = 0;

	for (;i < s.size();i++) {
		while (j>0&&s[i] != s[j]) {//��ƥ�䣬����
			j = next[j - 1];
		}

		if (s[i] == s[j]) {//ƥ��
			j++;
		}

		next[i] = j;//iλ�õ���Сǰ��׺�ĳ���
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
		while (j > 0 && a[i] != b[j]) {//��ƥ��
			j = next[j - 1];
		}

		if (a[i] == b[j]) {//ƥ��
			j++;
		}

		if (j == b.size()) {//ƥ�䵽
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
			j = next[j - 1];//j�ٻ��˵�next�����j-1��λ����
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