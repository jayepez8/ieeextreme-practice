#include <iostream>

using namespace std;

void init(int n,int list[]){
    for(int i = 0;i<n;i++)
        list[i]=i;    
}

int remplace(int x, int list[]){
    while(x!=list[x]){        
        list[x]=list[list[x]];
        x=list[x];
    }    
    return x;
}

bool connect(int x,int y,int list[]){
    int rX=remplace(x,list);
    int rY=remplace(y,list);
    if(rX==rY) return true;
    list[rY]=list[rX];    
    return false;
}

int main(){	
    int tam = 1e3;
    int list[tam];    
	int t;
	cin>>t;
    for(int i = 0; i<t;i++){
        int n,m;
        bool res = false;
        cin>>n>>m;
        init(n,list);	
		for(int i = 0;i<m;i++){
            int x,y;
            cin>>x>>y;
            res = res|connect(x,y,list);
        }
        if(res) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }			    
	return 0;
}