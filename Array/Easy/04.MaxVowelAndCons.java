import java.util.*;
class MaxVowelAndCons{
    int findMax(String s){
        int[] arr = new int[26];
       for(int i=0;i<s.length();i++){
           arr[s.charAt(i)-'a']++;
       }    

         int maxVowel = 0;
            int maxCons = 0;
            
            for(int i=0; i<26; i++){
                char ch = (char)(i + 'a');
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    maxVowel = Math.max(maxVowel, arr[i]);
                } else {
                    maxCons = Math.max(maxCons, arr[i]);
                }
            }
            return maxVowel + maxCons;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        MaxVowelAndCons obj = new MaxVowelAndCons();
        System.out.println(obj.findMax(s));
        sc.close();
    }
}