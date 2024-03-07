import java.util.Scanner;
import java.util.StringTokenizer;

public class bai3 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String temp = sc.nextLine();
        StringTokenizer fullname = new StringTokenizer(temp);
        StringBuilder output1 = new StringBuilder(temp);
        StringBuilder output2 = new StringBuilder(temp);
        StringBuilder output3 = new StringBuilder(fullname.nextToken());
        int startIndex = 0;
        int endIndex = output2.length() - 1;
        while(startIndex < output1.length() && Character.isWhitespace(output1.charAt(startIndex))){
            startIndex++;
        }
        while(endIndex >= 0  && Character.isWhitespace(output1.charAt(endIndex))){
            endIndex--;
        }
        while(fullname.hasMoreTokens()){
            output3.append(" " + fullname.nextToken());
        }
        System.out.print("\nString after removing leading white spaces: \n" + output1.delete(0, startIndex) + "\n");
        System.out.print("\nString after removing trailing white spaces: \n" + output2.delete(endIndex+1, output2.length()) + "\n");
        System.out.print("\nString after removing extra white spaces: \n" + output3 + "\n\n");
    }
}
