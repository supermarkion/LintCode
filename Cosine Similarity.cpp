/*
    Cosine similarity is a measure of similarity between two vectors of an inner product space that 
    measures the cosine of the angle between them. The cosine of 0° is 1, and it is less than 1 for any other angle.
    Return 2.0000 if cosine similarity is invalid (for example A = [0] and B = [0]).
    Link: http://www.lintcode.com/en/problem/cosine-similarity/
    Example: 
    Given A = [1, 2, 3], B = [2, 3 ,4].
    Return 0.9926.
    Given A = [0], B = [0].
	Return 2.0000
    Solution: No need to discuss, we compute three part of equation to speed up compution process.
    Source: https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/cosine-similarity.cpp
*/

 class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        const double invalide = 2.0;
        if (A.size() != B.size()) {
            return invalide;
        }
        
        double A_dot_B = 0.0, A_dot_A = 0.0, B_dot_B = 0.0;
        for (int i = 0; i < A.size(); i++) {
            A_dot_B += A[i] * B[i];
            A_dot_A += A[i] * A[i];
            B_dot_B += B[i] * B[i];
        }
        return A_dot_A && B_dot_B ?
                A_dot_B / sqrt(A_dot_A) / sqrt(B_dot_B) :
                invalide;    
    }
};
