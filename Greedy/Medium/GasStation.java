import java.util.ArrayList;
public class GasStation {
    int canCompleteCircle(ArrayList<Integer>gas, ArrayList<Integer>cost){
        int total = 0;
        int curr = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            total += gas.get(i) - cost.get(i);
            curr += gas.get(i) - cost.get(i);
            if(curr < 0){
                curr = 0;
                start = i + 1;
            }
        }
        if(total < 0) return -1;
        return start;
    }
    public static void main(String arg[]){
        ArrayList<Integer>gas = new ArrayList<>();
        ArrayList<Integer>cost = new ArrayList<>();
        gas.add(1);
        gas.add(2);
        gas.add(3);
        gas.add(4);
        gas.add(5);
        cost.add(3);
        cost.add(4);
        cost.add(5);
        cost.add(1);
        cost.add(2);
        GasStation obj = new GasStation();
        System.out.println(obj.canCompleteCircle(gas, cost));
    }
}
