#include <iostream>
using namespace std;

char highestOccurringChar(char input[]) {
    int freq[26] = {0};
    for(int i=0; input[i]!='\0'; i++){
        freq[int(input[i] - 'a')]++;
    }

    int maxi = -1, ans = 0;
    for(int i=0; i<26; i++){
        if(maxi < freq[i]){
            ans = i;
            maxi = max(maxi, freq[i]);
        }
    }

    return char('a'+ans);
}

int main(){
	char input[] = "abdefgbabfba";
	cout << "Highest occuring character: " << highestOccurringChar(input) << endl;
	return 0;
}