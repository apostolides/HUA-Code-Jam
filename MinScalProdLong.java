import java.util.*;
public class MinScalProdLong{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        //Read Number of test cases
        int testCases = Integer.parseInt(scanner.nextLine());
        for(int i=0;i<testCases;i++){
            //Read length of vectors (not used in this solution)
            int vectorSize = Integer.parseInt(scanner.nextLine());
            //Read next 2 vectors
            List<String> strVectorX = new ArrayList<String>();
            List<String> strVectorY = new ArrayList<String>();
            strVectorX = Arrays.asList(scanner.nextLine().split(" "));
            strVectorY = Arrays.asList(scanner.nextLine().split(" "));

            List<Long> vectorX = new ArrayList<Long>();
            List<Long> vectorY = new ArrayList<Long>();

            for(int j=0;j<strVectorX.size();j++){
                vectorX.add(Long.parseLong(strVectorX.get(j)));
                vectorY.add(Long.parseLong(strVectorY.get(j)));
            }

            Collections.sort(vectorX);
            Collections.sort(vectorY,Collections.reverseOrder());

            long sum = 0;
            for(int j=0;j<vectorX.size();j++){
                sum+=vectorX.get(j)*vectorY.get(j);
            }
            System.out.printf("Case #%d: %d\n",i+1,sum);
        }
    }
}
