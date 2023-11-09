#include <bits/stdc++.h>
using namespace std;

class FreqStack {
public:
    unordered_map<int, int> frequency;
    unordered_map<int, stack<int>> m;
    int maxFrequency;
    FreqStack() {
        maxFrequency=0;
    }
    
    void push(int val) {
        maxFrequency=max(maxFrequency, ++frequency[val]);
        m[frequency[val]].push(val);
    }
    
    int pop() {
        int num=m[maxFrequency].top();
        m[maxFrequency].pop();
        if(m[frequency[num]--].size()==0){
            maxFrequency--;
            cout << maxFrequency << endl;
        }
        
        return num;
    }
};

int main(){
	
	FreqStack freqStack;
	freqStack.push(5); // The stack is [5]
	freqStack.push(7); // The stack is [5,7]
	freqStack.push(5); // The stack is [5,7,5]
	freqStack.push(7); // The stack is [5,7,5,7]
	freqStack.push(4); // The stack is [5,7,5,7,4]
	freqStack.push(5); // The stack is [5,7,5,7,4,5]
	freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
	freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. 
					   // The stack becomes [5,7,5,4].
	freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
	freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. 
	                   // The stack becomes [5,7].

	return 0;
}