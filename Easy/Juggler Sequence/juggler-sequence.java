//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            long n = Long.parseLong(in.readLine());

            Solution ob = new Solution();
            List<Long> ans = new ArrayList<>();
            StringBuilder out = new StringBuilder();
            ans = ob.jugglerSequence(n);
            for (int i = 0; i < ans.size(); i++) out.append(ans.get(i) + " ");
            System.out.println(out);
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    static void solve(List<Long> result, long n){
        if(n <= 1){
            return;
        }
        if(n % 2 == 0){
            n = (long)Math.sqrt(n);
            result.add(n);
        }
        else{
            n = (long)(n * Math.sqrt(n));
            result.add(n);
        }
        
        solve(result, n);
    }
    static List<Long> jugglerSequence(long n) {
        List<Long> result = new ArrayList<Long>();
        result.add(n);
        solve(result, n);
        return result;
    }
}