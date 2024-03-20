#include <bits/stdc++.h>
using namespace std; 
class NStack
{
public:
    int *arr;
    int *top;
    int *next;
    
    int n, s;
     
    int freeSpot;
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        //top initialise
        for(int i=0; i<n; i++)
            top[i] = -1;
        
        //next initialise
        for(int i=0; i<s; i++)
            next[i] = i+1;

        //update last index value to -1
        next[s-1] = -1;
        
        //initialise freespot
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //Overflow condition
        if(freeSpot == -1)
            return false;

        //Find index
        int index = freeSpot;

        //Update freeSpot
        freeSpot = next[index];

        //Insert element
        arr[index] = x;

        //Update next array
        next[index] = top[m-1];

        //Update top array
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //Underflow condition
         if(top[m-1] == -1)
            return -1;

        //Reverse the operation of push to pop the elements
        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }
};

int main(){
	return 0;
}