//
// Created by Lakshmi S Patel on 17/05/21.
//

#ifndef CPPCOURSE_REGULAREXPMATCH_H
#define CPPCOURSE_REGULAREXPMATCH_H
enum Result {
    TRUE, FALSE
}

class RegularExpMatch {
    Result[][] memo;

    public boolean isMatch(String text, String pattern) {
            memo = new Result[text.length() + 1][pattern.length() + 1];
            return dp(0, 0, text, pattern);
        }

    public boolean dp(int i, int j, String text, String pattern) {
            if (memo[i][j] != null) {
                return memo[i][j] == Result.TRUE;
            }
            boolean ans;
            if (j == pattern.length()){
                ans = i == text.length();
            } else{
                boolean first_match = (i < text.length() &&
                                       (pattern.charAt(j) == text.charAt(i) ||
                                        pattern.charAt(j) == '.'));
                /* index:  i
                 * text :  a b
                 * Pat  :  t *
                 * index:  j
                 *
                 * In above scenerio treated t as zero char and moved j to j+2 and compare with i char of text
                 *
                 * index:  i
                 * text :  a b
                 * Pat  :  a *
                 * index:  j
                 *
                 * In this scenerio i,j char match, now you can compare the i+1 e.i b with a at j because * gives one more
                 * char of a
                 *
                 *
                 * */
                if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
                    ans = (dp(i, j+2, text, pattern) ||
                           first_match && dp(i+1, j, text, pattern));
                } else {
                    ans = first_match && dp(i+1, j+1, text, pattern);
                }
            }
            memo[i][j] = ans ? Result.TRUE : Result.FALSE;
            return ans;
        }
}

#endif //CPPCOURSE_REGULAREXPMATCH_H
