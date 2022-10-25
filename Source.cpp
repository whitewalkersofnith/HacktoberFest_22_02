#include<iostream>
#include<vector>
#define S 1000
using namespace std;
void DFS(vector<int> Alist[],int sel[], int index) {
	sel[index] = 1;
	for (int i = 0; i < Alist[index].size(); i++) {
		if (!sel[Alist[index][i]]) {
			DFS(Alist, sel, Alist[index][i]);
		}
	}

}
int main() {
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int res = 0;
		int N, M;
		cin >> N >> M;
		int sel[S] = { 0 };
		vector<int> Alist[S];
		int x, y;
		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			Alist[x].push_back(y);
			Alist[y].push_back(x);
		}
		for (int i = 1; i <= N; i++) {
			if (!sel[i]) {
				DFS(Alist,sel,i);
				res++;
			}
		}
		cout << test_case << "  " << res << endl;
	}
}