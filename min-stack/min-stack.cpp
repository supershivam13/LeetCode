long long min_ele;

class MinStack {

private:
    stack< long long> s;
    
public:
    
    void push(long long val) {
        
        if(s.size()==0){
            s.push(val);
            min_ele=val;
        }
        else{
            if(val>=min_ele)
                s.push(val);
            else{
                s.push((val*2)-min_ele);
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
                min_ele=(min_ele*2)-s.top();
                s.pop();
            } 
        }
    }
    
    int top(){
        
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