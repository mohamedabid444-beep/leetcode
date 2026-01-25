int lengthOfLongestSubstring(char* s) {
    // Creation of an empty string
    char deja_vu [177];
    deja_vu[0] = '\0';

    int size = 0;
    int size_longest_substring = 0;

    for (int i = 0; i < strlen(s); i++){
        char* doublee = strchr(deja_vu,s[i]);
        if (doublee == NULL){
            deja_vu[size] = s[i];
            size++;
            deja_vu[size] = '\0';       
        }
        else{
            if (size_longest_substring < size){
                size_longest_substring = size;
            }  

            int pos = (int)(doublee - deja_vu); // To know the position of the double
            // To make i point to the double so that after advancing by 1 i points at the character after the double
            i = i - (size - pos);  
            size = 0;
            deja_vu[0] = '\0';

        }
        
    }
    if (size_longest_substring < size){
        size_longest_substring = size;
    }  

    return size_longest_substring;
}