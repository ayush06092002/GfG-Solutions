//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            System.out.println(ob.firstElement(n));
        }
    }
}
// } Driver Code Ends


// User function Template for Java
class Solution {
    static int firstElement(int n) {
        if(n == 1){
            return 1;
        }
        int mod = 1000000007;
        int a = 1, b = 1;
        int c = a + b;
        for(int i = 0; i < n - 2; i++){
            c = (a % mod + b % mod) % mod;
            a = b;
            b = c;
        }
        
        return c;
    }
}