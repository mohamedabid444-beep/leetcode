class Solution {
    public String longestCommonPrefix(String[] strs) {
        String cp = "";
        Boolean test = true;
        int j = 0;
        char c;
        while (test) {
            if ( strs[0].length() > j) {
                c = strs[0].charAt(j);
                for (int i = 1; i < strs.length; i++) {
                    if (!(strs[i].length() > j && strs[i].charAt(j) == c)) {
                        test = false;
                    }
                }
                if (test) {
                    cp = cp + String.valueOf(c);
                    j = j + 1;
                }
            
            }

            else {
                test = false;
            }

            }
           
            
        
        
        return cp;
    }
}
