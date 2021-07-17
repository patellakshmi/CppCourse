/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 01/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_STRONGPASSWORD_H
#define CPPCOURSE_STRONGPASSWORD_H


/*
 *
A password is considered strong if the below conditions are all met:
It has at least 6 characters and at most 20 characters.
It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
It does not contain three repeating characters in a row (i.e., "...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.
 *
 *
 *
 */


class Solution {
public:
    int  flag,one=0,two=0;
    int case1(string s)
    {
        int l=s.size();
        if(l>=6&&l<=20)
            return 0;
        if(l<6)
        {
            flag=1;
            return abs(6-l);
        }
        if(l>20)
        {
            flag=0;
            return l-20;
        }
        return 0;
    }
    int case2(string s)
    {
        int ans=0;
        bool f1=false,f2=false,f3=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]-'a'>=0&&s[i]-'a'<26)
                f1=true;
            if(s[i]-'A'>=0&&s[i]-'A'<26)
                f2=true;
            if(s[i]-'0'>=0&&s[i]-'0'<9)
                f3=true;
        }
        if(!f1)
            ans++;
        if(!f2)
            ans++;
        if(!f3)
            ans++;
        return ans;
    }
    int case3(string s)
    {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int j=i+1,cnt=1;
            while(j<s.size()&&s[j]==s[i])
            {
                j++;cnt++;
            }
            i=j-1;
            ans+=max(0,cnt/3);
            if(cnt>=3)
            {
                if(cnt%3==0)
                    one++;
                else if(cnt%3==1)
                    two++;
            }
        }
        return ans;
    }
    int strongPasswordChecker(string password) {
        flag =-1;one=0;two=0;
        int x=case1(password),y=case2(password),z=case3(password);
        cout<<password.size()<<" "<<x<<" "<<y<<" "<<z<<endl;
        int ans=0;
        if(flag==1)
        {
            return max(x,y);
        }
        if(flag==-1)
        {
            return max(y,z);
        }
        else
        {
            z-=min(x,one);
            z-=min(max(x-one,0),two*2)/2;
            z-=(max(x - one - 2 * two, 0) / 3);
        }
        return max(z,y)+x;
    }
};

#endif //CPPCOURSE_STRONGPASSWORD_H
