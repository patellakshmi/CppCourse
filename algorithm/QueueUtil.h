//
// Created by Lakshmi S Patel on 04/02/21.
//

#ifndef CPPCOURSE_QUEUEUTIL_H
#define CPPCOURSE_QUEUEUTIL_H
namespace q {

    class QueueUtil{
    private:
    public:

    };

    class QueueUsingStackO_1FAndO_nP{
        stack<int> st;
    public:
        void populate(vector<int> &v);
        void print();
        int front();
        void push(int value);
        int dequeue(){ return front(); };
        void enqueue(int value){ push(value); };
    };

    class QueueUsingStackO_nFAndO_1P{
        stack<int> st;
    public:
        void populate(vector<int> &v);
        void print();
        int front();
        void push(int value);
        int dequeue(){ return front(); };
        int enqueue(int value){ push(value); };
        void getBottom(int &front);
    };
};

void q::QueueUsingStackO_1FAndO_nP::populate(vector<int> &v){
    for(int x: v){
        st.push(x);
    }
}

void q::QueueUsingStackO_nFAndO_1P::populate(vector<int> &v){
    for(int x: v){
        st.push(x);
    }
}

void q::QueueUsingStackO_1FAndO_nP::print(){
    if( st.empty()) { cout<< " <--Bottom"; return;}

    int top = st.top(); st.pop();
    cout<< " "<< top;
    print();
    st.push(top);

}


void q::QueueUsingStackO_nFAndO_1P::print(){
    if( st.empty()) { cout<< " <--Bottom"; return;}

    int top = st.top(); st.pop();

    cout<< " "<< top;
    print();
    st.push(top);

}


//fast front operation
int q::QueueUsingStackO_1FAndO_nP::front() {
    if( st.empty()) return -1;
    int top = st.top(); st.pop();
    return top;
}


void q::QueueUsingStackO_nFAndO_1P::getBottom(int &front) {

    if( st.empty()) { front = -1; return; }

    int x = st.top(); st.pop();
    if( st.empty()){ front = x; return; }
    else{
        getBottom(front);
    }

    st.push(x);

}


int q::QueueUsingStackO_nFAndO_1P::front() {
    int front= -1;
    getBottom(front);
    return front;
}

//O(n) time operation for push:
/*
 * main objective of this fuction to put the element at bottom
 * so that it should simulate like queue.
 * */

void q::QueueUsingStackO_1FAndO_nP::push(int value){

    if( st.empty()){
        st.push(value);
        return;
    }

    int top = st.top(); st.pop();
    push(value);
    st.push(top);
}


void q::QueueUsingStackO_nFAndO_1P::push(int value) {
    st.push(value);
}





#endif //CPPCOURSE_QUEUEUTIL_H
