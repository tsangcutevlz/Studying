import java.util.Scanner;
import java.util.StringTokenizer;

public class bai1 {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        StringTokenizer fullname = new StringTokenizer(sc.nextLine(), " ");
        String firstname = fullname.nextToken();
        String lastname = null;
        while(fullname.hasMoreTokens()){
            lastname = fullname.nextToken();
        }

        System.out.println(firstname + " " + lastname);

    }
}
