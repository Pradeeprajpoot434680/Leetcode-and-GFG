import java.util.*;

class MinCostToCutABoardInSqures {
   int minCost(int x[],int[] y,int m,int n){
        Arrays.sort(x);
        Arrays.sort(y);
        int h=1,v=1;
        int i=m-1,j=n-1;
        int cost=0;
        while(i>=0 && j>=0){
            if(x[i]>y[j]){
                cost+=x[i]*v;
                h++;
                i--;    
            }else{
                cost+=y[j]*h;
                v++;
                j--;
            }
        }
        while(i>=0){
            cost+=x[i]*v;
            h++;
            i--;
        }
        while(j>=0){
            cost+=y[j]*h;
            v++;
            j--;
        }
        return cost;
    }

    public static void main(String[] args) {
        MinCostToCutABoardInSqures obj = new MinCostToCutABoardInSqures();
        int x[] = {2,1,3,1,4};
        int y[] = {4,1,2};
        int m = x.length;
        int n = y.length;
        System.out.println(obj.minCost(x, y, m, n));
    }
}