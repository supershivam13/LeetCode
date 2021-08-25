class node {
public:
    
    node* a[2];

    // Constructor
    node() {
        for (int i = 0; i < 2; i++)
            a[i] = NULL;
    }

    // Destructor
    ~node() {
        for (int i = 0; i < 2; i++) {
            if (a[i] != NULL)
                delete a[i];
        }
    }
};


void insert(node *root,int x){
    
    node* temproot = root;
    
    for(int i=31;i>=0;i--){
        
        int bit = (x>>i)&1;
        
        if(temproot->a[bit]==NULL)
            temproot->a[bit]= new node();
        
        temproot = temproot->a[bit];
    }
}

int getAns(node *root,int x){
    
    node* temproot = root;
    int ans=0;
    
    for(int i=31;i>=0;i--){
        
        int bit = (x>>i)&1;
        
        if(bit==0){
            
            if(temproot->a[1]!=NULL){
                temproot = temproot->a[1];
                ans+=(1<<i);
            }
            else
                temproot = temproot->a[0]; 
        }
        
        else{
            
            if(temproot->a[0]!=NULL){
                temproot = temproot->a[0];
                ans+=(1<<i);
            }
            else
                temproot = temproot->a[1];
        }
        
    }
    return ans;
}


class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        
        node* root = new node();
        int size=a.size();
        
        for(int i=0;i<size;i++)
            insert(root,a[i]);
        
        int ans=0;
        int temp;
        
        for(int i=0;i<size;i++){
            
            temp = getAns(root,a[i]);
            
            ans=max(temp,ans);
        }
        
        return ans;
    }
};