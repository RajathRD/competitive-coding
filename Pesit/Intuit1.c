// Problem- Given 2 strings A and B, consider every prefix of A, and compare it with all possible substrings of B(of any length)
// and sum the starting indices(of array B i guess) of every match found between the 2.
// eg - A is "aaba", B is "abcaab", here first prefix 'a' of A, matches substring(here the starting letter) 'a' in B. 
// another prefix 'aa' of string A matches substring 'aa' in B
// Now what I'm not sure is whether its the starting index or the ending index to be considered for addition.
//Also, substring 'a' of string B matches prefix 'a' of A, and substring 'aa' of B matches prefix 'aa'. 
// Both have same starting index, does that mean it should be added twice? 
// examples weren't indicative enough and were very vague and confusing.