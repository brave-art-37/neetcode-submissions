class MedianFinder {
public:
    priority_queue<int> firstHalf;
    priority_queue<int,vector<int>,greater<int>> secondHalf;
    int total;

    MedianFinder():firstHalf(),secondHalf(),total(0){
        firstHalf.push(INT_MIN);
        secondHalf.push(INT_MAX);
    }
    
    void addNum(int num) {
        int a = firstHalf.top(), b=secondHalf.top();
        if(total%2==1){ //uneven size, (firstHalf - secondHalf) = 1
            if(a<=num && num<=b){
                secondHalf.push(num);
            }
            else if(num<a){
                secondHalf.push(a);
                firstHalf.pop();
                firstHalf.push(num);
            }
            else if(b<num){
                secondHalf.push(num);
            }
        }
        else{
            if(a<=num && num<=b){
                firstHalf.push(num);
            }
            else if(num<a){
                firstHalf.push(num);
            }
            else if(b<num){
                firstHalf.push(b);
                secondHalf.pop();
                secondHalf.push(num);
            }
        }
        total++;
    }
    
    double findMedian() {
        if(total%2==1){
            return (double) firstHalf.top();
        }
        return ((double) firstHalf.top()+secondHalf.top())/2;
    }
};
