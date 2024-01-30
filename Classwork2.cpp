
SIMPLE BUBBLE SORT:

#include <iostream>
using namespace std;
int main(){
    
int a[]={8,7,6,5,2,4,1,3,9};
int getArrayLength = sizeof(a) / sizeof(int);
for (int i = 0; i < getArrayLength; i++)//up unitl the length
{
    for(int j = 0;j<getArrayLength-1; j++){//up until last but one
        if(a[j]>a[j+1]){
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
}
//printing
for (int i=0;i<getArrayLength;i++){
    cout<<a[i];
}

}

STACK IN C: 

#include <iostream> 
#include <stack>
using namespace std;
int main() {
	stack<int> stack;
	stack.push(21);
// The values pushed in the stack should be of the same data which is written during declaration of stack
	stack.push(22);
	stack.push(24);
	stack.push(25);
	int num=0;
	stack.push(num);
	stack.pop();
	stack.pop();
	stack.pop();

	while (!stack.empty()) {
		cout << stack.top() <<" ";
		stack.pop();
	}
}

QUEUE in C:

#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void showq(queue<int> gq)
{
	queue<int> g = gq;
	while (!g.empty()) {
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';
}

// Driver Code
int main()
{
	queue<int> gquiz;
	gquiz.push(10);
	gquiz.push(20);
	gquiz.push(30);

	cout << "The queue gquiz is : ";
	showq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.front() : " << gquiz.front();
	cout << "\ngquiz.back() : " << gquiz.back();

	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showq(gquiz);

	return 0;
}

