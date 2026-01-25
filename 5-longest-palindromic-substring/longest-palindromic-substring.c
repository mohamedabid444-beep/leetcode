bool is_Palindrome(char* s){
    bool test = true;
    int l = strlen(s);
    int ls = l/2;
    int i = 0;
    while (test && i < ls){
        test = (s[i] == s[l-i-1]);
        i++;
    }
    return test;
    
}

char* longestPalindrome(char* s) {

    int length_s = strlen(s);

    

    // Initilization of the length and the start of the output
    int len_output = 1;
    int start_output = 0;

    // We try for all possible sizes
    for (int len = 2; len <= length_s; len++){
        
        char cut[len+1];
        strncpy(cut, s, len);
        cut[len] = '\0';

        int i = 0;
        // For a fixed size we try all subtrings until we find a palindome
        while ( (i + len <= length_s ) && (!is_Palindrome(cut)) ){
            i = i + 1;
            strncpy(cut, s+i, len);
            cut[len] = '\0';
            
        }
        if (is_Palindrome(cut)){
            start_output = i;
            len_output = len;
        }
                
    }
    // Assigning the string of the output
    char* output = malloc((len_output+1) * sizeof(char));
    strncpy(output,s+start_output,len_output);
    output[len_output] = '\0';


    return output;
}