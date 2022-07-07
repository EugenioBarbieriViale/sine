#include <bits/stdc++.h>
using namespace std;

int main() {
	int s,p;
	cin >> s >> p;
	vector<int> ris;
	int a = -abs(p);
	int stop=0;

	while (a<=abs(p)) {
		if (a!=0) {
			if (p%a==0)
				ris.push_back(p/a);
		}
		a++;
	}

	for (int i:ris) {
		for (int j:ris) {
			if (i+j==s && j*i==p && stop==0) {
				cout << i << " " << j << endl;
				stop=1;
			}
		}
	}
	if (stop!=1) cout << "Nothing Found." << endl;
}


