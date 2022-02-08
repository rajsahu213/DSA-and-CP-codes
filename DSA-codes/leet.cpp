struct trienode;
struct u
{
    string str;
    struct trienode* nolf[27];
};

struct trienode
{
    bool is_leaf;
    struct u ptr;
};

typedef struct trienode* tptr;

tptr creat_noleaf()
{
    tptr temp;
    temp=new trienode;
    temp->is_leaf=false;
    for(char i=0;i<=26;i++)
    {
        temp->ptr.nolf[i]=NULL;
    }
    return temp;
}

tptr creat_leaf(string &s)
{
    tptr temp;
    temp=new trienode;
    temp->is_leaf=true;
    temp->ptr.str=s;
    return temp;
}

tptr creat_trie(tptr &t,int &i,string &s)
{
    if(t==NULL)
    {
        t=creat_leaf(s);
    }
    else
    {
        if(t->is_leaf)
        {
            tptr temp=t;
            t=creat_noleaf();
            if((temp->ptr.str.length())==i)t->ptr.nolf[26]=temp;
            else t->ptr.nolf[temp->ptr.str[i]-'a']=temp;
        }
        if(s.length()==i)t->ptr.nolf[26]=creat_leaf(s);
        for(int j=i;j<s.length();j++)
        {
            t->ptr.nolf[s[j]-'a']=creat_trie(t->ptr.nolf[s[j]-'a'],++i,s);
            break;
        }
    }
    return t;
}

void print(tptr &t)
{
 if(t!=NULL)
 {
     if(t->is_leaf)
     {
            cout<<t->ptr.str<<" ";
     }
     else
     {
         for(int i=0;i<27;i++)
         {
             print(t->ptr.nolf[i]);
         }
     }
 }
}

bool search1(tptr t,int i,string &s)
{
    if(t==NULL)return false;
    if(t->is_leaf){if(t->ptr.str==s)return true;else return false;}
    else if(i>=s.length())return search1(t->ptr.nolf[26],i,s);
    else return search1(t->ptr.nolf[s[i]-'a'],i+1,s)||search1(t->ptr.nolf[26],i,s);
}

bool is(string a,string b){
    if(b.length()>a.length())return false;
    for(int i=0;i<a.length();i++){
        if(i>=b.length())return true;
        else if(a[i]!=b[i])return false;
    }
    return true;
}

bool fun(tptr temp,int i,string &s)
{
    tptr t=temp;
    while(t!=NULL && i<s.length()){
        if(t->is_leaf){
            if(is(t->ptr.str,s))return true;
            else return false;
        }else{
            t=t->ptr.nolf[s[i++]-'a'];
        }
    }
    if(t==NULL)return false;
    return true;
    // else return false;
}


class Trie {
public:
    /** Initialize your data structure here. */
    tptr t;
    Trie() {
        t=NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int i=0;
        if(!search1(t,i,word))t=creat_trie(t,i,word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search1(t,0,word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return fun(t,0,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */