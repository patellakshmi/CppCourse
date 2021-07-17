/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 10/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_STICKERTOSPELLWORDS_H
#define CPPCOURSE_STICKERTOSPELLWORDS_H

/*
class Solution {
    Map<String,Integer>dp=new HashMap<>();
    int find(int stickers[][],String target){
        if(target.length()==0)return 0;
        if(dp.containsKey(target))return dp.get(target);
        int min=1000_000;
        for(int i=0;i<stickers.length;i++){
            if(stickers[i][target.charAt(0)-'a']==0)continue;
            //take clone bcz we don't want to change in original array
            int t[]=stickers[i].clone();
            StringBuilder temp=new StringBuilder();
            for(char c : target.toCharArray()){
                if(t[c-'a']>0)t[c-'a']--;
                else temp.append(c);
            }
            min=Math.min(min,1+find(stickers,temp.toString()));
        }
        dp.put(target,min);
        return min;
    }
public int minStickers(String[] sticker, String target) {
        int stickers[][]=new int[sticker.length][26];
        for(int i=0;i<sticker.length;i++)
            for(char c : sticker[i].toCharArray())
                stickers[i][c-'a']++;
        int t =find(stickers,target);
        return t>=1000_000 ? -1 : t;
    }
}

*/

#endif //CPPCOURSE_STICKERTOSPELLWORDS_H
