public class bai4 {
    public static void main(String[] args){
        String chuoi = "hello cac ban";
        String chuoi1 = ", cam on cac ban";
        String chuoi2 = chuoi + chuoi1;
        String chuoi3 = "abcdedcba";
        System.out.println("Length of the string: " + chuoi.length());
        System.out.println("The amount of Words in the string: " + countWords(chuoi));
        System.out.println("Concatenate one string contents to another.: " + chuoi2);
        if(checkPalindrome(chuoi3)){
            System.out.println(chuoi3 + " is a palindrome string");
        } else {
            System.out.println(chuoi3 + " is not a palindrome string");
        }
    }
    public static int countWords(String chuoi){
        int count = 0;
        for(int i = 0; i< chuoi.length();i++){
            if(Character.isLetter(chuoi.charAt(i))){
                count++;
            }
        }
        return count;
    }
    public static boolean checkPalindrome(String chuoi) {
        // Remove spaces and convert to lowercase for a case-insensitive check
        chuoi = chuoi.replaceAll("\\s", "").toLowerCase();
        for (int i = 0; i < chuoi.length() / 2; i++) {
            if (chuoi.charAt(i) != chuoi.charAt(chuoi.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }
}
