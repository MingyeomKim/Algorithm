#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std; 

struct Person {
	int age; 
	string name;
};

bool cmp(const Person& u, const Person& v) {
	return u.age < v.age; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n; cin >> n; 
	vector<Person> persons(n);
	for (int i = 0; i < n; i++)
		cin >> persons[i].age >> persons[i].name; 
	stable_sort(persons.begin(), persons.end(), cmp); 

	for (int i = 0; i < n; i++)
		cout << persons[i].age << " " << persons[i].name << endl;
	return 0; 
}