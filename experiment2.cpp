#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	int number;
	int ordered_pairs;
	cout << "Enter number of elements in the set ";
	cin >> number;
	int a[number];
	int arr[number][number];
	for (int i = 0; i < number; i++) {
		cout << "Enter an element ";
		cin >> a[i];
	}
	cout << "Enter number of ordered pairs ";
	cin >> ordered_pairs;
	int first[ordered_pairs], second[ordered_pairs];
	for (int i = 0; i < ordered_pairs; i++) {
		cout << "Enter the first element of the ordered pair ";
		cin >> first[i];
		cout << "Enter the second element of the ordered pair ";
		cin >> second[i];
	}
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < ordered_pairs; i++) {
		int f = first[i];
		int h, k;
		for (int j = 0; j < number; j++) {
			if (a[j] == f) {
				h = j;
			}
		}
		int s = second[i];
		for (int j = 0; j < number; j++) {
			if (a[j] == s) {
				k = j;
			}
		}
		arr[h][k] = 1;
	}
	int reflexive_count = 0;
	for (int i = 0; i < number; i++) {
		if (arr[i][i] == 1) {
			reflexive_count += 1;
		}
	}
	cout<<endl<<endl;
	if (reflexive_count == number) {
		cout << "The given relation is reflexive: " <<"YES"<<endl;
	}
	else {
		cout << "The given relation is reflexive: " <<"NO"<<endl;
	}
	int symmetric = 0;
	int arr1[number][number];
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			arr1[i][j] = arr[j][i];
		}
	}
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (arr[i][j] == arr1[i][j]) {
				symmetric += 1;
			}
		}
	}
	if (symmetric == number * number) {
		cout << "The given relation is symmetric: " <<"YES"<<endl;
	}
	else {
		cout << "The given relation is  symmetric: " <<"NO"<<endl;
	}
	bool as = 0;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if ((arr[i][j] == 1) && (i != j)) {
				if (arr1[i][j] != 0) {
					as = 1;
				}
			}
		}
	}
	if (!as) {
		cout << "The given relation is antisymmetric: " <<"YES"<<endl;
	}
	else {
		cout << "The given relation is antisymmetric: " <<"NO"<<endl;
	}
	bool flag = 0;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			for (int k = 0; k < number; k++) {
				if ((arr[i][j] == 1) && (arr[j][k] == 1)) {
					if ((arr[i][k] != 1)) {
						flag = 1;
					}
				}
			}
		}
	}
	if (flag == 0) {
		cout << "The given relation is transitive: "<<"YES"<<endl;
	}
	else {
		cout << "The given relation is  transitive: "<<"NO"<<endl;
	}
}
//***************COMMENTS*******************************
//(1) No problems.The difficulty level is fine
//(2) It helped me to look at relations from a computer science perspective.
//(3) More problems should be solved by programming
