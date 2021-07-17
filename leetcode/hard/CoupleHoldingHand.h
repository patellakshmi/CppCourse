/*
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Created by Lakshmi S. Patel on 15/07/21.
   Copyright (c) 2021, Fight For Education Pvt. Ltd. All rights reserved.
   Please visit us: www.fight4edu.com or www.fight4edu.org
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#ifndef CPPCOURSE_COUPLEHOLDINGHAND_H
#define CPPCOURSE_COUPLEHOLDINGHAND_H

/*

 class Solution {
public int minSwapsCouples(int[] row) {
int swapCount=0;

    //Using Hashmap to store the index values that will be later used when swapping
     HashMap<Integer, Integer> hashmap= new HashMap<Integer, Integer>();
     for(int i=0;i<row.length;i++){
         hashmap.put(row[i],i);
     }

    //iterate through the loop two positions at a time
     for(int i=0;i<row.length;i=i+2){

    //if couples already present, do nothing.
      if(((row[i]%2)==0)&&(row[i+1]==(row[i]+1))){}
          //continue;
      else if(((row[i]%2)!=0)&&(row[i+1]==(row[i]-1))){}
          //continue;

    //if not couple, swap thier position
      else if((row[i]%2)==0){
          int index= hashmap.get(row[i]+1);
          row[index]=row[i+1];
          row[i+1]=row[i]+1;
          swapCount++;
          hashmap.put(row[i]+1, i+1);
          hashmap.put(row[index], index);
      }
      else if((row[i]%2)!=0){
          int index= hashmap.get(row[i]-1);
          row[index]=row[i+1];
          row[i+1]=row[i]-1;
          swapCount++;
          hashmap.put(row[i]-1, i+1);
          hashmap.put(row[index], index);
     }
     }

    return swapCount;
}
}


 */
#endif //CPPCOURSE_COUPLEHOLDINGHAND_H
