import java.util.Scanner;
import java.util.StringTokenizer;

public class bai2 {
    public static void main(String[] args){
        System.out.print("input string to count words: \n");

        Scanner sc = new Scanner(System.in);
        StringTokenizer fullname = new StringTokenizer(sc.nextLine(), " ");
        int amount = fullname.countTokens(); 
        System.out.print("An Amount of words: " + amount + "\n");

        System.out.print("input 2 strings to concat: \n");
        StringBuilder sb1 = new StringBuilder(sc.nextLine());
        StringBuilder sb2 = new StringBuilder(sc.nextLine());
        System.out.print("An Amount of words: " + sb1.append(sb2)+ "\n");

        System.out.print("input string to check palindrome: ");
        StringBuffer sb3 = new StringBuffer(sc.nextLine());
        if(sb3.toString().equals(sb3.reverse().toString())){
            System.out.print("your string is palindrome");
        } else {
            System.out.print("your string is not palindrome");
        }
         
    }
}
