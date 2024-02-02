public class bai5 {
    public static void main(String[] args){
        String chuoi1 = "        xin chao moi nguoi";
        String chuoi3 = "xin chao moi nguoi          ";
        String chuoi5 = "    xin     chao      moi        nguoi          ";
        String chuoi2 = chuoi1.trim();
        String chuoi4 = chuoi3.trim();
        String chuoi6 = removeExtraSpaces(chuoi5);

        System.out.println("original string: " + chuoi1);
        System.out.println("string after removing leading spaces: " + chuoi2);
        System.out.println(chuoi3 + " is a original string");
        System.out.println(chuoi4 + " is  a string after removing trailing spaces");
        System.out.println(chuoi5 + " is a original string");
        System.out.println(chuoi6 + " is  a string after removing extra spaces");
    }
    public static String removeExtraSpaces(String chuoi) {
        return chuoi.replaceAll("\\s+", " ").trim();
    }
}
