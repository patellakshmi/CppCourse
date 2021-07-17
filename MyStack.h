/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 24/06/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_MYSTACK_H
#define CPPCOURSE_MYSTACK_H


int a[10];
int stackSize = 10;
int i = -1;

void push(int value){
    if( i < stackSize ){
        i = i +1;
        a[i] = value;
    }else{
        printf("\n Stack is full");
    }
}

void pop(){
    if( i == -1){
        printf("\n Stack is empty");
    }else{
        i = i -1;
    }
}

int top(){
    if( i == -1){
        printf("\n Stack is empty");
        return -1;
    }else{
        return a[i];
    }
}



#endif //CPPCOURSE_MYSTACK_H
