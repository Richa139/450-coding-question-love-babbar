// 1st method
// tc:O(n);
// sc:O(n);
string reverseWord(string str){
    string ans;
    int n=str.length();
    for(int i=n-1;i>=0;i--){
    ans+=str[i];
    }
    return ans;
}

// 2nd method
// tc:O(n);
// sc:O(1);
string reverseWord(string str){
    
   int i=0;
   int j=str.length()-1;
   while(i<j){
       swap(str[i],str[j]);
       i++;
       j--;
   }
   return str;
}

