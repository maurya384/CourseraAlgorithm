#include <bits/stdc++.h>
using namespace std;
int hamming_distance(string& fs, string& ss)
{
    int hm_distance = 0;

    if((fs.length() == ss.length()))
    {

      for(int i = 0; i < fs.length(); i++){
        if(!(fs[i] == ss[i])){
          hm_distance++;
        }
      }

    }
    else
    {
      hm_distance = -1;
    }
    return hm_distance;
}

int main ()
{
     //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    int hm_distance;

    while(true)
    {
    cout << "Input First String: ";
    cin>>s1;
    cout << "Input Second String: ";
    cin>>s2;

    hm_distance = hamming_distance(s1, s2);

    // check and display
    if(hm_distance >= 0){
      cout<<hm_distance<<endl;
    }else{
      cout << "String are not equal in size!\n\n";
    }
  }

  return 0;
}
