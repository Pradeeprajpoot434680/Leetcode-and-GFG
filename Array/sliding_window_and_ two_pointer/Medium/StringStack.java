class StringStack {
    public void StringStack(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        int i = n - 1, j = m - 1;
        while (i >= 0 || j >= 0) {
            if(s1.charAt(i)==s2.charAt(j)){
                i--; j--;
            }else{
                i-=2;
            }
        }
        if(j<0) System.out.println("true");
        else System.out.println("false");
    }
    public static void main(String[] args){
        StringStack obj = new StringStack();
        obj.StringStack("gdrefefedg", "gfg");
    }
}