
/* longest palindrome dynamic O(n)
 *
 *
 * floor(r/2)*2 or floor(r/2)+1
 *
 * comparing words in constant time
 * n log n preprocessing or n log^2 n
 * n log n memory
 * no collision!
 *
 * dictionary of substrings of len 2^n
 * 
 * * = +-infinity
 * lets map everyletter in alphabet to its index starting with 1
 *  /\
 * p |
 *   |
 * 4 | 1 5 4 3
 * / | (1,4) (5,3) (4,*) (3,*)
 * 2 | 1 5 4 3
 * / | (1,2) (2,2) (2,1) (1,*)    
 * 0 | 1 2 2 1                    1 3 2 1
 *   |---------------------------->
 *     a b b a *                  a c b a *
 * p = 2^k > len(abba*) and 2^(k-1) <= len(abba*) 
 * now lets map every pair to a value by sorted order, preferably dict sort (in c++ std::sort due to slow maps etc)
 * 1,2: 1 1,3: 2; 1,*: 3; 2,1: 4; 2,2: 5; 3,2: 6;
 *
 * 1,4: 1; 2,4: 2; 3,*: 3; 4,*: 4; 5,3: 5; 6,3: 6;
 *
 * i mamy od razu tablice sufiksową (taka ktora podaje kolejnosc leksykograficzna sufiksow)
