#include <vector>
 using std::vector;


#include <iostream>
 using std::ostream;
using std::cout;
using std::endl;



void print_array(int i, const int a[]) {
	cout << "( ";
	
		for (int n = 0; n < i; n++) {
		cout << a[n] << " ";
		
	}
	cout << ")";
	
		
}

void selection_sort_in_place(int i, int a[]) {
	for (int index = 0; index < i; index++) {
		int finalIndex = index;
		for (int compare = index; compare < i; compare++) {
			if (a[compare] < a[index])
				 if (a[compare] < a[finalIndex])
				 finalIndex = compare;
			
		}
		int switch1 = a[index];
		int switch2 = a[finalIndex];
		a[index] = switch2;
		a[finalIndex] = switch1;
		
	}
	
}

ostream& operator<<(ostream& os, const vector<int> &v) {
	os << "( ";
	for (unsigned int i = 0; i < v.size(); i++) {
		os << v[i] << " ";
		
	}
	os << ")";
	return os;
	
}


//merge code based on code at http://www.bogotobogo.com/Algorithms/mergesort.php
vector<int> merge(vector<int> v1, vector<int>v2);


vector<int> merge_sort(const vector<int> & v) {
	if (v.size() == 1)
		 return v;
	
		int middle = (v.size() / 2);
	
		vector<int> left;
	vector<int> right;
	
		for (int i = 0; i < middle; i++) {
		left.push_back(v[i]);
		
	}
	for (int i = middle; i < v.size(); i++) {
		right.push_back(v[i]);
		
	}
	left = merge_sort(left);
	right = merge_sort(right);
	
		vector<int> sorted = merge(left, right);
	return sorted;
	
}

vector<int> merge(vector<int> v1, vector<int>v2) {
	vector<int> sorted;
	while (v1.size() > 0 || v2.size() > 0) {
		if (v1.size() > 0 && v2.size() > 0) {
			if (v1.front() < v2.front()) {
				sorted.push_back(v1.front());
				v1.erase(v1.begin());
				
			}
			else {
				sorted.push_back(v2.front());
				v2.erase(v2.begin());
				
			}
			
		}
		else if (v1.size() > 0) {
			for (int a = 0; a < v1.size(); a++) {
				sorted.push_back(v1[a]);
				
			}
			break;
			
		}
		else if (v2.size() > 0) {
			for (int a = 0; a < v2.size(); a++) {
				sorted.push_back(v2[a]);
				
			}
			break;
			
		}
		
	}
	return sorted;
	
}



int main() {
	
		int a[7] = { 1, 2, 3, 4, 5, 6, 7, };
	print_array(7, a);
	cout << endl;
	
		
		int arrays[5][7] = {
		{ 1, 2, 3, 4, 5, 6, 7 },
		{ 22, 1, 63, 67, 11, 17, 12, },
		{ 45, 53, 64, 7, 25, 79, 54, },
		{ 34, 21, 35, 84, 16, 10, 36, },
		{ 41, 2, 85, 94, 69, 9, 92, },
		};
	
		for (int i = 0; i < 5; i++) {
		print_array(7, arrays[i]);
		cout << endl;
		
			selection_sort_in_place(7, arrays[i]);
		
			print_array(7, arrays[i]);
		cout << endl;
		
			cout << endl;
		
	}
	
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, };
	cout << v << endl;
	
		
		
		
		vector<int> vectors[] = {
		vector<int>{ 1, 2, 3, 4, 5, 6, 7 },
		vector<int>{ 22, 1, 63, 67, 11, 17, 12, },
		vector<int>{ 45, 53, 64, 7, 25, 79, 54, },
		vector<int>{ 34, 21, 35, 84, 16, 10, 36, },
		vector<int>{ 41, 2, 85, 94, 69, 9, 92, },
		};
	
		for (const vector<int> & v : vectors) {
		cout << v << endl;
		cout << merge_sort(v) << endl;
		cout << endl;
		
	}
	
		cout << endl;
	
		
		
		
		std::cin.get();
	
		return 0;
	
}
