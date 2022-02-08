#include<bits/stdc++.h>
using namespace std;
void ignore_missing(vector<int> &a){
	cout<<"Ignoring missing tuples:"<<"\n";
	for(int i=0;i<a.size();i++){
		if(a[i]!=-1)cout<<a[i]<<" ";
	}
	cout<<"\n";
}
void fill(vector<int> &a){
	cout<<"Replacement with global constant:"<<"\n";
	for(int i=0;i<a.size();i++){
		if(a[i]==-1)cout<<INT_MIN<<" ";
		else cout<<a[i]<<" ";
	}
	cout<<endl;
}
void replace_by_mean(vector<int> &a){
	int sum=0,n=0;
	for(int x:a)if(x!=-1){sum+=x;n++;}
	double mean=(double)sum/n;
	cout<<"Replacement with central tendency: mean"<<"\n";
	for(int i=0;i<a.size();i++){
		if(a[i]==-1)cout<<mean<<" ";
		else cout<<a[i]<<" ";
	}cout<<endl;
}
void replace_by_median(vector<int> &a){
	vector<int> temp;for(int x:a)if(x!=-1)temp.push_back(x);
	sort(temp.begin(),temp.end());double median;
	if(temp.size()&1)median=temp[temp.size()/2];
	else median=(temp[temp.size()/2-1]+temp[temp.size()/2])/2.0;
	cout<<"Replacement with central tendency: median"<<"\n";
	for(int i=0;i<a.size();i++){
		if(a[i]==-1)cout<<median<<" ";
		else cout<<a[i]<<" ";
	}cout<<endl;
}

void binning(vector<int> &a){
	sort(a.begin(),a.end());
	int n=a.size();
	int num=n/3;
	vector<vector<int>> bins;
	vector<int> temp;
	for(int i=0;i<n;i++){
		if(i!=0 && i%num==0){
			bins.push_back(temp);
			temp.clear();
		}
		temp.push_back(a[i]);
	}
	bins.push_back(temp);temp.clear();
	cout<<"Partition by freq:"<<"\n";
	for(int i=0;i<bins.size();i++){
		cout<<"Bin "<<i+1<<": ";
		for(int x:bins[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}	
	cout<<"Bin means:"<<"\n";
	for(int i=0;i<bins.size();i++){
		int sum=0;sum=accumulate(bins[i].begin(),bins[i].end(),sum);
		double mean=(double)sum/bins[i].size();
		cout<<"Bin "<<i+1<<": ";
		for(int x:bins[i]){
			cout<<mean<<" ";
		}
		cout<<endl;
	}
	cout<<"Bin median:"<<"\n";
	for(int i=0;i<bins.size();i++){
		double median;
		if(bins[i].size()&1)median=bins[i][bins[i].size()/2];
		else median=(bins[i][bins[i].size()/2]+bins[i][bins[i].size()/2-1])/2.0;
		cout<<"Bin "<<i+1<<": ";
		for(int x:bins[i]){
			cout<<median<<" ";
		}
		cout<<endl;
	}
	cout<<"Bin by boundaries:"<<"\n";
	for(int i=0;i<bins.size();i++){
		int left=bins[i][0],right=bins[i].back();
		cout<<"Bin "<<i+1<<": ";
		for(int j=0;j<bins[i].size();j++){
			if((bins[i][j]-left)<(right-bins[i][j])){
				cout<<left<<" ";
			}else{
				cout<<right<<" ";
			}
		}
		cout<<endl;
	}	

}
int main(){
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);	
	int n;cin>>n;
	vector<int> a1(n),a2(n);
	for(int i=0;i<n;i++)cin>>a1[i];
	ignore_missing(a1);
    fill(a1);
    replace_by_mean(a1);
    replace_by_median(a1);
    for(int i=0;i<n;i++)cin>>a2[i];
    binning(a2);
}