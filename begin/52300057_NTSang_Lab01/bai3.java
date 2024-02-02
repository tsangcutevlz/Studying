import java.util.Scanner;
public class bai3 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String fullName = sc.nextLine();
        String firstName = fullName.substring(fullName.lastIndexOf(" ") + 1);
        String lastName = fullName.substring(0, fullName.indexOf(" "));
        System.out.println("first name: " + firstName);
        System.out.println("last name: " + lastName);
        fullName = capitalizeFullName(fullName);
        System.out.println("capitalize full name: " + fullName);

    }
    public static String capitalizeFullName(String fullName){
        return fullName.toUpperCase();
    }
}
