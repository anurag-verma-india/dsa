
public class TimeComplexityDemo {
    public static void main(String args[]) {
        double now = System.currentTimeMillis();
        TimeComplexityDemo demo = new TimeComplexityDemo();

        System.out.println(demo.findSum(999999));

        System.out.println("Time taken (with formua): "+ (System.currentTimeMillis() - now) + " milliseconds.");

        double now2 = System.currentTimeMillis();

        System.out.println(demo.findSumLoop(999999));

        System.out.println("Time taken (with loop): "+ (System.currentTimeMillis() - now2) + " milliseconds.");

    }

    public int findSum(int n) {
        return n*(n+1)/2;
    }

    public int findSumLoop(int n) {
        int sum = 0;

        for(int i =1;i<=n;i++) {
            sum+=i;
        }
        return sum;
    }
}