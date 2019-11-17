#include<bits/stdc++.h>
#define lower(c) (isupper(c) ? (c + 32) : c)
using namespace std;typedef unsigned long long ull;double t[59];double t1[20];double t2[3];constexpr int P=1e6+7,MOD=1e9+7;double avg(vector<int>&v){double r=0;for(int y:v){r+=y;}
return r/v.size();}
double sqd(vector<int>&v,double&x){double r=0;for(int y:v){r+=pow((y-x),2);}
return sqrt(r/v.size());}
void process(const string&s){fill(t,t+58,0);t[55]=s.size()-3;unordered_map<int,int>words;t[56]=0;t[57]=0;int upperchar=0,upperword=0,wordlength=0,sentencechar=0,sentenceword=0,wordhash=0;vector<int>upperchars,upperwords,sentencechars,sentencewords,wordlengths;for(int i=0;i<t[55]+1;i++){char c=s[i];cout<<c;bool processword=1;bool processsentence=0;if(isalpha(c)){t[0]++;t[lower(c)-'a'+29]++;processword=0;wordlength++;wordhash=((ull)P*wordhash+lower(c))%MOD;if(isupper(c)){t[1]++;upperchars.push_back(upperchar);upperwords.push_back(upperword);upperchar=upperword=0;}
if(lower(c)=='u'){if(lower(s[i+1])=='s')t[58]++;}}
else if(isdigit(c))t[2]++;else if(c==' ')t[3]++;else if(c=='.'){processsentence=1;t[4]++;if(s[i+1]=='.' and s[i+2]=='.')t[5]++;}
else if(c==',')t[6]++;else if(c==';')t[7]++;else if(c==':')t[8]++;else if(c=='"')t[9]++;else if(c=='-')t[10]++;else if(c=='?'){t[11]++;processsentence=1;}else if(c=='!'){t[12]++;processsentence=1;}else if(c=='^')processsentence=1;sentencechar++;upperchar++;if(processword and wordlength){t[56]++;if(wordhash==325955471)
t[13]++;else if(wordhash==105)
t[14]++;else if(wordhash==992934780)
t[15]++;else if(wordhash==97)
t[16]++;upperword++;sentenceword++;wordlengths.push_back(wordlength);words[wordhash]++;wordlength=wordhash=0;}
if(processsentence and sentenceword){t[57]++;sentencechars.push_back(sentencechar);sentencewords.push_back(sentenceword);sentencechar=sentenceword=0;}}
t[17]=words.size();for(auto&xd:words)
t[18]+=(xd.second==1?1:0);t[19]=avg(wordlengths);t[20]=sqd(wordlengths,t[19]);t[21]=avg(sentencechars);t[22]=sqd(sentencechars,t[21]);t[23]=avg(sentencewords);t[24]=sqd(sentencewords,t[23]);if(upperchars.size()){t[25]=avg(upperchars);t[26]=sqd(upperchars,t[25]);}else{t[25]=t[26]=0;}
if(upperwords.size()){t[27]=avg(upperwords);t[28]=sqd(upperwords,t[27]);}else{t[27]=t[28]=0;}
for(int i=0;i<13;i++)t[i]/=t[55];for(int i=29;i<55;i++)t[i]/=t[55];for(int i=13;i<19;i++)t[i]/=t[56];t[58]/=t[56];}
int main(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);int q;cin>>q;string s;cin.ignore();while(q--){getline(cin,s);s=s+"^^^";process(s);for(int i=0;i<59;i++){cout<<t[i]<<"\n";}}
cout<<"FINISHED";return 0;}