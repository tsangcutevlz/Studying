import java.util.Scanner;

public class Bai1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("nhap vao chuoi: ");
        String chuoi = sc.nextLine();
        int count = 0;
        for(int i = 0; i < chuoi.length()-1;i++){
            if(Character.isWhitespace(chuoi.charAt(i)) && Character.isLetterOrDigit(chuoi.charAt(i+1))){
                count++;
            }
        }
        String firstName = chuoi.substring(chuoi.lastIndexOf(" ") + 1);
        System.out.println("So tu la: " + (count + 1));
        System.out.println("first name: " + firstName);

    }
}
