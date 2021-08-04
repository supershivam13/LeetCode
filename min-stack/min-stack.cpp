int min_ele;

class MinStack {

private:
    stack<signed long long> s;
    
public:
    
    void push(int val) {
        
        if(s.size()==0){
            s.push(val);
            min_ele=val;
        }
        else{
            if(val>=min_ele)
                s.push(val);
            else{
                s.push((2ll*val)-min_ele);
                min_ele=val;
            }
        }
        
    }
    
    void pop() {
        
        if(s.size()==0)
            return;
        else{
            if(s.top()>=min_ele)
                s.pop();
            else{
                min_ele=(2ll*min_ele)-s.top();
                s.pop();
            } 
        }
    }
    
    int top() {
        
        if(s.size()==0)
            return -1;
        
        if(s.top()>=min_ele)
            return s.top();
        else
            return min_ele;
    }
    
    int getMin() {
        
        if(s.size()==0)
            return -1;
        
        return min_ele;
    }
};